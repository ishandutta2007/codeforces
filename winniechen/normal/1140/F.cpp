#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
#include <map>
using namespace std;
#define N 300005
#define M 300000
#define ll long long
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
vector<pair<int ,int > >v[N<<2];
void Update(int L,int R,const pair<int ,int > &c,int l,int r,int rt)
{
	if(L<=l&&r<=R)return v[rt].push_back(c),void();int m=(l+r)>>1;
	if(L<=m)Update(L,R,c,lson);if(m<R)Update(L,R,c,rson);
}
struct node
{
	int p,x,y;
	node(){p=x=y=0;}
	node(int a,int b,int c){p=a,x=b,y=c;}
};
int fa[N<<1],sx[N<<1],sy[N<<1],sta[N<<1],top,n;ll ans;
int find(int x){return x==fa[x]?x:find(fa[x]);}
ll calc(int x){return (ll)sx[x]*sy[x];}
void uni(int x,int y)
{
	x=find(x),y=find(y);if(x==y)return ;
	if(sx[x]+sy[x]<sx[y]+sy[y])swap(x,y);
	sta[++top]=y,ans-=calc(x)+calc(y);
	sx[x]+=sx[y],sy[x]+=sy[y],fa[y]=x,ans+=calc(x);
}
void undo(){int y=sta[top--],x=find(y);ans-=calc(x),sx[x]-=sx[y],sy[x]-=sy[y],fa[y]=y;ans+=calc(x)+calc(y);}
void solve(int l,int r,int rt)
{
	int lst=top;int m=(l+r)>>1;
	for(int i=0;i<v[rt].size();i++)uni(v[rt][i].first,v[rt][i].second+M);
	if(l==r)printf("%lld ",ans);else solve(lson),solve(rson);for(;top>lst;)undo();
}
map<pair<int ,int > ,int >mp;
map<pair<int ,int > ,int >::iterator it;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=M<<1;i++)fa[i]=i,sx[i]=(i<=M),sy[i]=(i>M);
	for(int i=1,x,y;i<=n;i++)
	{
		scanf("%d%d",&x,&y);pair<int ,int >tmp=make_pair(x,y);
		if(mp.find(tmp)!=mp.end()&&mp[tmp])
			Update(mp[tmp],i-1,tmp,1,n,1),mp[tmp]=0;
		else mp[tmp]=i;
	}
	for(it=mp.begin();it!=mp.end();it++)
		if((*it).second!=0)Update((*it).second,n,(*it).first,1,n,1);
	solve(1,n,1);puts("");
}