#include <set>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i,a,b) for (int i=a;i<=b;++i)
#define dep(i,a,b) for (int i=a;i>=b;--i)

const int nn=510,inf=1000000000;

int n,m;
int c[nn][nn],g[nn][nn],f[nn][nn];

void init(){
	scanf("%d%d",&n,&m);
	memset(c,0x7f,sizeof(c));
	rep(i,1,m){
		int x,y,z;scanf("%d%d%d",&x,&y,&z);
		c[x][y]=c[y][x]=z;
	}
}
void floyd(){
	memset(f,0x7f,sizeof(f));
	rep(i,1,n) f[i][i]=0;
	rep(i,1,n)rep(j,1,n)f[i][j]=min(f[i][j],c[i][j]);
	rep(k,1,n)rep(i,1,n)rep(j,1,n)
		if (f[i][k]<inf&&f[k][j]<inf&&f[i][j]>f[i][k]+f[k][j])
		f[i][j]=f[i][k]+f[k][j];
}
void work(){
	floyd();
	rep(i,1,n)rep(j,1,n)rep(k,1,n)
		if (c[k][j]&&f[i][k]+c[k][j]==f[i][j])g[i][j]++;
	rep(i,1,n)rep(j,i+1,n){
		int ans=0;
		rep(k,1,n) if (f[i][k]<inf&&f[k][j]<inf&&f[i][k]+f[k][j]==f[i][j]) ans+=g[i][k];
		printf("%d ",ans);
	}
}
int main(){
	init();
	work();
	return 0;
}