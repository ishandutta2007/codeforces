//CF1086E
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 2222;
const int MO = 998244353;
void ad(int&x,int y){
	x+=y;
	if(x>=MO)
		x-=MO;
}
int mul(int x,int y){
	return (LL)x*y%MO;
}
int n,f[N][N],g[N];
int F(int x,int y){
	return f[n-x-y*2][y];
}
int p[N],a[N],b[N],t[N][2];
void ad(int e,int x,int y){
	while(x<=n){
		t[x][e]+=y;
		x+=x&-x;
	}
}
int qu(int e,int x){
	int y=0;
	while(x){
		y+=t[x][e];
		x-=x&-x;
	}
	return y;
}
int main()
{
	int i,j,x,y,o,ans=0;
	n=2000;
	f[1][0]=0;
	f[2][0]=1;
	for(i=3;i<=n;i=i+1)
		f[i][0]=mul(i-1,f[i-2][0]+f[i-1][0]);
	f[0][0]=1;
	for(i=1;i<=n;i=i+1)
		f[0][i]=mul(i,f[0][i-1]);
	for(i=1;i<=n;i=i+1){
		for(j=1;i+j<=n;j=j+1){
			f[i][j]=mul(j,f[i-1][j]);
			if(i>=2)
				ad(f[i][j],mul(i-1,f[i-2][j+1]));
		}
	}
	scanf("%d",&n);
	g[0]=1;
	for(i=1;i<=n;i=i+1)
		g[i]=mul(g[i-1],f[n][0]);
	for(i=1;i<=n;i=i+1)
		ad(0,i,1);
	for(i=1;i<=n;i=i+1){
		scanf("%d",&o);
		ad(0,o,-1);
		ad(ans,mul(mul(qu(0,o),f[0][n-i]),g[n-1]));
		p[i]=o;
	}
	for(i=2;i<=n;i=i+1){
		memset(t,0,sizeof(t));
		x=0,y=0;
		for(j=1;j<=n;j=j+1)
			ad(0,j,1),a[j]=0,b[j]=0;
		for(j=1;j<=n;j=j+1){
			scanf("%d",&o);
			if(b[p[j]])
				x++,y--;
			else
				y++,ad(0,p[j],-1);
			ad(ans,mul(mul(qu(0,o-1),F(x,(y+1)/2)),g[n-i]));
			ad(ans,mul(mul(qu(1,o-1),F(x+1,(y-1)/2)),g[n-i]));//cout<<ans<<x<<y<<qu(0,o-1)<<endl;
			a[p[j]]=1;
			if(!b[p[j]])
				ad(1,p[j],1);
			b[o]=1;
			if(a[o])
				x++,y--,ad(1,o,-1);
			else
				y++,ad(0,o,-1);
			p[j]=o;
		}
	}
	cout<<ans;
	return 0;
}