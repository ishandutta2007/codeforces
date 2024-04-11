#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+9;
int n,m1,m2;
int f[N][3];
int find(int x,int i){
	return f[x][i]==x?x:(f[x][i]=find(f[x][i],i));
}
void merge(int x,int y,int i){
	int fx=find(x,i),fy=find(y,i);
	if(fx!=fy){
		f[fx][i]=fy;
	}
	return ;
}
int cnt;
int ax[N],ay[N];
void add(int u,int v){
	ax[++cnt]=u,ay[cnt]=v;
	return ;
}


int main(){
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=n*n;i++) f[i][0]=f[i][1]=f[i][2]=i;
	for(int i=1;i<=m1;i++){
		int u,v;scanf("%d%d",&u,&v);merge(u,v,1);
	}
	for(int i=1;i<=m2;i++){
		int u,v;scanf("%d%d",&u,&v);merge(u,v,2);
	}
	cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++)
			if(find(i,1)!=find(j,1)&&find(i,2)!=find(j,2)&&find(i,0)!=find(j,0)){
				merge(i,j,0);merge(i,j,1);merge(i,j,2);
				add(i,j);
			} 
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++) printf("%d %d\n",ax[i],ay[i]);
	return 0;
}