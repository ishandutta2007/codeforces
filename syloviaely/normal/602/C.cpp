#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
int d[500][500],pd[500][500],b[500][500],n,m;
struct atom{
	int x,y;
};
queue<atom>Q;
void push(atom k1,int k2){
	if (d[k1.x][k1.y]!=-1) return;
	d[k1.x][k1.y]=k2; Q.push(k1);
}
void update(int k1,int k2,int k3){
	for (int i=1;i<=n;i++)
		if (i!=k2&&b[i][k2]==0&&i!=k1) push((atom){k1,i},k3+1);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int k1,k2; scanf("%d%d",&k1,&k2); b[k1][k2]=1; b[k2][k1]=1;
	}
	memset(d,0xff,sizeof d); d[1][1]=0;
	Q.push((atom){1,1});
	while (!Q.empty()){
		atom k=Q.front();
		if (k.x==n&&k.y==n){printf("%d\n",d[k.x][k.y]); return 0;}
		if (k.x==n){
			for (int i=1;i<=n;i++) if (i!=k.y&&b[k.y][i]==0) push((atom){k.x,i},d[k.x][k.y]+1);
		} else if (k.y==n){
			for (int i=1;i<=n;i++) if (i!=k.x&&b[k.x][i]) push((atom){i,k.y},d[k.x][k.y]+1);
		} else for (int i=1;i<=n;i++) if (i!=k.x&&b[k.x][i]&&pd[i][k.y]==0){
			pd[i][k.y]=1; update(i,k.y,d[k.x][k.y]);
		}
		Q.pop();
	}
	printf("-1\n");
	return 0;
}