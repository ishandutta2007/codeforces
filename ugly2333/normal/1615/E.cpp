//CF1615E
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
const int N = 1<<19;
int n,k,m,e,a[N],b[N],g[N],c[N],d[N],f[N],t[N],w[N],p[N];
vector<int> v[N];
void upd(int k){
	if(t[k<<1]>t[k<<1|1])
		t[k]=t[k<<1]+w[k],p[k]=p[k<<1];
	else
		t[k]=t[k<<1|1]+w[k],p[k]=p[k<<1|1];
}
void build(int k=1,int l=1,int r=n){
	if(l==r){
		t[k]=d[g[l]];
		w[k]=0;
		p[k]=l;
		return;
	}
	int h=l+r>>1;
	build(k<<1,l,h);
	build(k<<1|1,h+1,r);
	upd(k);
}
void modify(int L,int R,int X,int k=1,int l=1,int r=n){
	if(L<=l&&r<=R){
		w[k]+=X;
		t[k]+=X;
		return;
	}
	int h=l+r>>1;
	if(L<=h)
		modify(L,R,X,k<<1,l,h);
	if(h<R)
		modify(L,R,X,k<<1|1,h+1,r);
	upd(k);
}
void dfs(int u,int fa){
	int i,x,o=1;
	a[u]=++e;
	g[e]=u;
	d[u]=d[fa]+1;
	f[u]=fa;
	for(i=0;i<v[u].size();i++){
		x=v[u][i];
		if(x!=fa)
			dfs(x,u),o=0;
	}
	m+=o;
	b[u]=e;
}
void go(int x){
	while(x&&!c[x]){
		modify(a[x],b[x],-1);
		c[x]=1;
		e++;
		x=f[x];
	}
}
int main()
{
	int i,x,y;
	LL s=0;
	scanf("%d%d",&n,&k);
	for(i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	e=0;
	dfs(1,0);
	if(m<=k){
		for(i=m;i<=k;i++)
			s=max(s,(LL)i*(n-i));
		cout<<s;
		return 0;
	}
	build();
	e=0;
	for(i=1;i<=k;i++){
		go(g[p[1]]);
	}
	s=(LL)k*(n-k);
	for(i=0;i<=n-e;i++)
		s=min(s,(LL)(k-i)*(n-k-i));
	cout<<s;
	return 0;
}