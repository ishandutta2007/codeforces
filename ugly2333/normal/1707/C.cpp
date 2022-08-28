//CF1707C
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
const int Q = 22;
int n,m,a[N],b[N],e[N],c[N],d[N],f[N][Q],s[N];
vector<int> v[N];
int fnd(int x){
	if(c[x]==x)
		return x;
	return c[x]=fnd(c[x]);
}
void dfs(int u,int fa){
	int i,x;
	d[u]=d[fa]+1;
	f[u][0]=fa;
	for(i=0;i<v[u].size();i++){
		x=v[u][i];
		if(x!=fa)
			dfs(x,u);
	}
}
int lca(int x,int y){
	int j;
	if(d[x]<d[y])
		swap(x,y);
	for(j=20;d[x]>d[y];j--)
		if(d[f[x][j]]>=d[y])
			x=f[x][j];
	if(x==y)
		return x;
	for(j=20;f[x][0]!=f[y][0];j--)
		if(f[x][j]!=f[y][j])
			x=f[x][j],y=f[y][j];
	return f[x][0];
}
int ff(int x,int y){
	int j;
	for(j=20;j>=0;j--)
		if(d[f[x][j]]>d[y])
			x=f[x][j];
	return x;
}
void dfs2(int u,int fa){
	int i,x;
	for(i=0;i<v[u].size();i++){
		x=v[u][i];
		if(x!=fa)
			s[x]+=s[u],dfs2(x,u);
	}
}
int main()
{
	int i,j,k,o;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		c[i]=i;
	for(i=1;i<=m;i++){
		scanf("%d%d",a+i,b+i);
		if(fnd(a[i])!=fnd(b[i])){
			c[fnd(a[i])]=fnd(b[i]);
			v[a[i]].push_back(b[i]);
			v[b[i]].push_back(a[i]);
			e[i]=1;
		}
	}
	dfs(1,0);
	for(j=1;j<=20;j++)
		for(i=1;i<=n;i++)
			f[i][j]=f[f[i][j-1]][j-1];
	for(i=1;i<=m;i++){
		if(!e[i]){
			k=lca(a[i],b[i]);
			if(k==b[i])
				swap(a[i],b[i]);
			if(k==a[i]){
				o=ff(b[i],a[i]);
				s[1]++;
				s[o]--;
				s[b[i]]++;
			}
			else{
				s[a[i]]++;
				s[b[i]]++;
			}
		}
	}
	dfs2(1,0);
	for(i=1;i<=n;i++)
		printf("%d",(s[i]==m-n+1));
	return 0;
}