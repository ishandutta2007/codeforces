//CF1408G
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
const int N = 1555;
const int M = N*N/2;
const int MO = 998244353;
void ad(int&x,int y){
	x+=y;
	if(x>=MO)
		x-=MO;
}
int mul(int x,int y){
	return (LL)x*y%MO;
}
int n,m,a[M],b[M],f[N],g[N],h[N][N],s[N],t[N];
int fnd(int x){
	if(f[x]==x)
		return x;
	return f[x]=fnd(f[x]);
}
void mrg(int x,int y){
	int i,j;
	for(i=1;i<=g[x];i=i+1)
		for(j=1;j<=g[y];j=j+1)
			ad(t[i+j],mul(h[x][i],h[y][j]));
	f[y]=x;
	g[x]+=g[y];
	s[x]+=s[y];
	for(i=1;i<=g[x];i=i+1)
		h[x][i]=t[i],t[i]=0;
}
int main()
{
	int i,j,x;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1)
		for(j=1;j<=n;j=j+1)
			scanf("%d",&x),a[x]=i,b[x]=j;
	for(i=1;i<=n;i=i+1)
		f[i]=i,g[i]=1,h[i][1]=1,s[i]=0;
	m=n*(n-1)/2;
	for(i=1;i<=m;i=i+1){
		a[i]=fnd(a[i]),b[i]=fnd(b[i]);
		if(a[i]!=b[i])
			mrg(a[i],b[i]);
		s[a[i]]++;
		if(s[a[i]]==g[a[i]]*(g[a[i]]-1)/2)
			h[a[i]][1]++;
	}
	for(i=1;i<=n;i=i+1)
		printf("%d ",h[fnd(1)][i]);
	return 0;
}