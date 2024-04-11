#include<stdio.h>
#include<iostream>
using namespace std;
const int maxn=1005;
int n,m,q,tot;
int a[maxn][maxn],f[maxn][maxn][2];
long long ans;
inline void update(int x,int y){
	ans-=f[x][y][0]+f[x][y][1];
	if(a[x][y]==1)
		f[x][y][0]=f[x][y][1]=0;
	else f[x][y][0]=f[x-1][y][1]+1,f[x][y][1]=f[x][y-1][0]+1;
	ans+=f[x][y][0]+f[x][y][1];
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			update(i,j);
	tot=n*m;
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		tot+=a[x][y],a[x][y]^=1,tot-=a[x][y];
		update(x,y),x++,y++;
		while(x<=n+1&&y<=m+1){
			if(x<=n)
				update(x,y-1);
			if(y<=m)
				update(x-1,y);
			if(x<=n&&y<=m)
				update(x,y);
			x++,y++;
		}
		printf("%lld\n",ans-tot);
	}
	return 0;
}