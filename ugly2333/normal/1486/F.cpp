//CF1486F
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
const int N = 333333;
const int Q = 22;
LL c2(int x){
	return (LL)x*(x-1)/2;
}
int n,m,d[N],f[N][Q],a[N],b[N],c[N];
vector<int> v[N];
map<pair<int,int>,int> M;
map<pair<int,int>,int>::iterator it;
void dfs1(int u,int fa){
	d[u]=d[fa]+1;
	f[u][0]=fa;
	int i,x;
	for(i=0;i<v[u].size();i=i+1){
		x=v[u][i];
		if(x!=fa)
			dfs1(x,u);
	}
}
int lca(int x,int y){
	int j;
	if(d[x]<d[y])
		swap(x,y);
	for(j=19;j>=0;j=j-1)
		if(d[f[x][j]]>=d[y])
			x=f[x][j];
	if(x==y)
		return x;
	for(j=19;j>=0;j=j-1)
		if(f[x][j]!=f[y][j])
			x=f[x][j],y=f[y][j];
	return f[x][0];
}
int ff(int x,int y){
	int j,o=d[x]-d[y]-1;
	for(j=0;o;j=j+1,o>>=1)
		if(o&1)
			x=f[x][j];
	return x;
}
void dfs2(int u){
	int i,x;
	for(i=0;i<v[u].size();i=i+1){
		x=v[u][i];
		if(x!=f[u][0]){
			dfs2(x);
			a[u]+=a[x];
			b[u]+=b[x];
			c[u]+=c[x];
		}
	}
}
int main()
{
	int i,j,x,y,z,px,py;
	LL ans;
	scanf("%d",&n);
	for(i=1;i<n;i=i+1){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs1(1,0);
	for(j=1;j<=19;j=j+1)
		for(i=1;i<=n;i=i+1)
			f[i][j]=f[f[i][j-1]][j-1];
	scanf("%d",&m);
	for(i=1;i<=m;i=i+1){
		scanf("%d%d",&x,&y);
		z=lca(x,y);
		a[x]++,a[y]++,a[z]--,a[f[z][0]]--;
		b[x]++,b[y]++,b[z]-=2;
		if(x!=z){
			px=ff(x,z);
			c[x]++,c[px]--;
		}
		if(y!=z){
			py=ff(y,z);
			c[y]++,c[py]--;
		}
		if(x!=z&&y!=z){
			if(px<py)
				swap(px,py);
			M[make_pair(px,py)]++;
		}
	}
	dfs2(1);
	ans=0;
	for(i=1;i<=n;i=i+1){
		ans+=c2(a[i]);
		ans-=2*c2(b[i]);
		ans+=c2(c[i]);
	}
	for(it=M.begin();it!=M.end();it++)
		ans+=c2((*it).second);
	cout<<ans;
	return 0;
}