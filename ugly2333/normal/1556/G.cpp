//CF1556G
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
const int M = 55555;
const int W = M*100;
int n,m,qt[M],ans[M];
LL o,ql[M],qr[M];
vector<LL> v;
int tot,cnt,ls[W],rs[W],a[W],rt,p[W];
vector<int> e[W],g[M];
void modify(int&k,LL L,LL R,LL l=0,LL r=o-1){
	if(!k)
		k=++tot;
	if(L<=l&&r<=R){
		a[k]=++cnt;
		return;
	}
	LL h=l+r>>1;
	if(L<=h)
		modify(ls[k],L,R,l,h);
	if(h<R)
		modify(rs[k],L,R,h+1,r);
}
void dfs(int k1,int k2,int d,int D){
	if(d>D){
		if(a[k1])
			return;
		dfs(ls[k1],ls[k2],d-1,D);
		dfs(rs[k1],rs[k2],d-1,D);
		return;
	}
	if(d==D){
		if(a[k1])
			return;
		dfs(ls[k1],rs[k2],d-1,D);
		return;
	}
	if(a[k1]&&a[k2]){
		e[a[k1]].push_back(a[k2]);
		e[a[k2]].push_back(a[k1]);
		return;
	}
	if(a[k1]){
		dfs(k1,ls[k2],d-1,D);
		dfs(k1,rs[k2],d-1,D);
		return;
	}
	if(a[k2]){
		dfs(ls[k1],k2,d-1,D);
		dfs(rs[k1],k2,d-1,D);
		return;
	}
	dfs(ls[k1],ls[k2],d-1,D);
	dfs(rs[k1],rs[k2],d-1,D);
}
void query(int k,LL L,LL R,int i,LL l=0,LL r=o-1){
	if(L<=l&&r<=R){
		p[a[k]]=i;
		g[i].push_back(a[k]);
		return;
	}
	LL h=l+r>>1;
	if(L<=h)
		query(ls[k],L,R,i,l,h);
	if(h<R)
		query(rs[k],L,R,i,h+1,r);
}
int f[W];
int fnd(int x){
	if(f[x]==x)
		return x;
	return f[x]=fnd(f[x]);
}
void ins(int x){
	int i;
	f[x]=x;
	for(i=0;i<e[x].size();i++)
		if(f[e[x][i]])
			f[fnd(x)]=fnd(e[x][i]);
}
int geta(int k,LL x){
	int i;
	for(i=n-1;i>=0;i--){
		if((x>>i)&1)
			k=rs[k];
		else
			k=ls[k];
		if(a[k])
			return a[k];
	}
}
int main()
{
	int i,j;
	char ch[5];
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%s%lld%lld",ch,ql+i,qr+i);
		if(ch[0]=='a')
			qt[i]=1;
		else
			v.push_back(ql[i]-1),v.push_back(qr[i]);
	}
	o=(LL)1<<n;
	v.push_back(-1),v.push_back(o-1);
	sort(v.begin(),v.end());
	v.resize(unique(v.begin(),v.end())-v.begin());
	for(i=1;i<v.size();i++)
		modify(rt,v[i-1]+1,v[i]);
	for(i=0;i<n;i++)
		dfs(rt,rt,n-1,i);
	for(i=1;i<=m;i++){
		if(!qt[i])
			query(rt,ql[i],qr[i],i);
	}
	for(i=1;i<=cnt;i++)
		if(!p[i])
			ins(i);
	for(i=m;i>=1;i--){
		if(!qt[i]){
			for(j=0;j<g[i].size();j++)
				ins(g[i][j]);
		}
		else{
			ql[i]=geta(rt,ql[i]);
			qr[i]=geta(rt,qr[i]);
			ans[i]=fnd(ql[i])==fnd(qr[i]);
		}
	}
	for(i=1;i<=m;i++)
		if(qt[i])
			printf("%d\n",ans[i]);
	return 0;
}