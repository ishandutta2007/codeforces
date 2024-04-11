//CF1408D
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
const int W = 1e6+16;
int n,m,a[N],b[N],c[N],d[N];
int w=1e6,f[W];
int main()
{
	int i,j,x;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i=i+1)
		scanf("%d%d",a+i,b+i);
	for(i=1;i<=m;i=i+1)
		scanf("%d%d",c+i,d+i);
	for(i=0;i<=w;i=i+1)
		f[i]=-1;
	for(i=1;i<=n;i=i+1)
		for(j=1;j<=m;j=j+1)
			if(a[i]<=c[j]&&b[i]<=d[j])
				f[c[j]-a[i]]=max(f[c[j]-a[i]],d[j]-b[i]);
	for(i=w;i>=1;i=i-1)
		f[i-1]=max(f[i-1],f[i]);
	x=W*2;
	for(i=0;i<=w;i=i+1)
		x=min(x,i+f[i]+1);
	printf("%d",x);
	return 0;
}