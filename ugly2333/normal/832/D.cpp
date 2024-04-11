//CF 832D
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
vector<int> v[111111];
int d[111111],f[111111][22];
void dfs(int u)
{
	d[u]=d[f[u][0]]+1;
	int i,s;
	s=v[u].size();
	for(i=0;i<s;i=i+1)
		dfs(v[u][i]);
}
int lca(int x,int y)
{
	if(x==y)
		return x;
	int i;
	if(d[x]<d[y])
		swap(x,y);
	for(i=20;i>=0;i=i-1){
		if(d[f[x][i]]>=d[y])
			x=f[x][i];
	}
	if(x==y)
		return x;
	for(i=20;i>=0;i=i-1){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}
int cal(int s,int f,int t,int lsf,int lft,int lst)
{
	if(lsf==f&&lft==f)
		return d[lst]-d[f]+1;
	if(lsf==f||lft==f)
		return 1;
	if(lsf==lft)
		return d[f]+d[lst]-d[lsf]-d[lft]+1;
	return d[f]-max(d[lsf],d[lft])+1;
}
int main()
{
	int n,q,i,j,a,b,c,x,y,z;
	scanf("%d%d",&n,&q);
	f[1][0]=0;
	for(i=2;i<=n;i=i+1){
		scanf("%d",&j);
		v[j].push_back(i);
		f[i][0]=j;
	}
	d[0]=0;
	dfs(1);
	for(j=1;j<=20;j=j+1)
		for(i=1;i<=n;i=i+1)
			f[i][j]=f[f[i][j-1]][j-1];
	while(q--){
		scanf("%d%d%d",&a,&b,&c);
		x=lca(a,b);
		y=lca(b,c);
		z=lca(c,a);
		j=0;
		j=max(j,cal(a,b,c,x,y,z));
		j=max(j,cal(b,c,a,y,z,x));
		j=max(j,cal(c,a,b,z,x,y));
		printf("%d\n",j);
	}
	return 0;
}