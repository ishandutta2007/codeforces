//CF1142B
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
const int N = 222222;
int n,m,q,a[N],b[N*2],p[N],f[N][22],g[N];
int main()
{
	int i,j,x;
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<=n;i=i+1)
		scanf("%d",&x),p[x]=i;
	for(i=1;i<=m;i=i+1)
		scanf("%d",&x),a[i]=p[x];
	for(i=m;i;i=i-1){
		f[i][0]=b[a[i]+1];
		b[a[i]]=i;
		b[a[i]+n]=i;
	}
	for(j=1;j<=19;j=j+1)
		for(i=1;i<=m;i=i+1)
			f[i][j]=f[f[i][j-1]][j-1];
	for(i=1;i<=m;i=i+1)
		g[i]=i;
	for(i=1;i<=m;i=i+1)
		for(j=19;j>=0;j=j-1)
			if((n-1)&(1<<j))
				g[i]=f[g[i]][j];
	for(i=m;i;i=i-1){
		if(g[i])
			if(!g[i-1]||g[i-1]>g[i])
				g[i-1]=g[i];
	}
	for(i=1;i<=q;i=i+1){
		scanf("%d%d",&j,&x);
		cout<<(g[j]&&g[j]<=x);
	}
	return 0;
}