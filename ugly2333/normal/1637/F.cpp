//CF1637F
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
int n,rt,a[N],f[N],e[N],c[N];
vector<int> v[N];
pair<int,int> p[N];
void dfs(int u,int fa){
	f[u]=fa;
	int i,x;
	for(i=0;i<v[u].size();i++){
		x=v[u][i];
		if(x!=fa)
			dfs(x,u);
	}
}
int go(int x){
	if(e[x])
		return x;
	e[x]=1;
	go(f[x]);
}
int main()
{
	int i,x,y;
	LL s;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i),p[i]=make_pair(a[i],i);
	for(i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	sort(p+1,p+n+1);
	reverse(p+1,p+n+1);
	rt=p[1].second;
	dfs(rt,0);
	e[rt]=1;
	c[rt]=p[1].first;
	x=p[2].second;
	go(x);
	c[x]=c[rt];
	for(i=3;i<=n;i++){
		x=p[i].second;
		if(e[x])
			continue;
		y=go(x);
		if(c[y])
			c[x]=c[y],c[y]=0;
		else
			c[x]=p[i].first;
	}
	s=0;
	for(i=1;i<=n;i++)
		s+=c[i];
	printf("%lld\n",s);
	return 0;
}