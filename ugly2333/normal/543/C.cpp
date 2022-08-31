//CF543C
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
const int N = 33;
const int inf = 1e9;
char ch[N];
int n,m,a[N][N],b[N][N],c[N],d[N],e[N],h[N],f[1<<20],g[1<<20];
vector<int> v[N];
int main()
{
	int i,j,x;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i=i+1){
		scanf("%s",ch);
		for(j=0;j<m;j=j+1)
			a[i][j]=ch[j]-'a';
	}
	for(i=0;i<(1<<n);i=i+1)
		f[i]=inf;
	for(i=0;i<n;i=i+1){
		c[i]=inf;
		for(j=0;j<m;j=j+1){
			scanf("%d",b[i]+j);
			c[i]=min(c[i],b[i][j]);
		}
		f[1<<i]=c[i];
		v[i].push_back(1<<i);
	}
	for(j=0;j<m;j=j+1){
		for(i=0;i<n;i=i+1){
			x=a[i][j];
			d[x]|=1<<i;
			e[x]+=b[i][j];
			h[x]=max(h[x],b[i][j]);
		}
		for(i=0;i<n;i=i+1){
			x=a[i][j];
			if(d[x]!=(1<<i))
				v[i].push_back(d[x]);
			f[d[x]]=min(f[d[x]],e[x]-h[x]);
		}
		for(i=0;i<26;i=i+1)
			d[i]=0,e[i]=0,h[i]=0;
	}
	g[0]=-inf;
	for(i=0;i<(1<<n)-1;i=i+1){
		for(j=0;j<n;j=j+1)
			if(!(i&(1<<j)))
				break;
		x=j;
		for(j=v[x].size();j--;)
			g[i|v[x][j]]=min(g[i|v[x][j]],g[i]+f[v[x][j]]);
	}
	cout<<g[(1<<n)-1]+inf;
	return 0;
}