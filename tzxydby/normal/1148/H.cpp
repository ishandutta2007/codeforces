#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,c,rt0,vis[N],mx;
set<pair<int,int>>s[N];
pair<int,int>sg[N];
long long las;
struct seg
{
	int tr[N<<2];
	pair<int,int>ask(int k,int l,int r,int v)
	{
		if(l==r)
			return {l,tr[k]};
		int mid=l+r>>1;
		if(tr[k<<1]<v)
			return ask(k<<1,l,mid,v);
		else
			return ask(k<<1|1,mid+1,r,v);
	}
	pair<int,int>ask(int v){return ask(1,0,n+1,v);}
	void upd(int k,int l,int r,int x,int v)
	{
		if(l==r)
		{
			tr[k]=v;
			return;
		}
		int mid=l+r>>1;
		if(x<=mid) upd(k<<1,l,mid,x,v);
		else upd(k<<1|1,mid+1,r,x,v);
		tr[k]=min(tr[k<<1],tr[k<<1|1]);
	}
	void upd(int x,int v){upd(1,0,n+1,x,v);}
}sgt;
struct nd
{
	int ch[2],s1,tg1,tg2;
	long long s2;
}tr[N<<6];
void sol(int k,int l,int v,int t)
{
	tr[k].tg2+=t,tr[k].s2+=1ll*l*t;
	tr[k].tg1+=v,tr[k].s1+=v*l;
}
void upd(int &k,int bs,int l,int r,int a,int b,int v,int t)
{
	k=++c;
	tr[k]=tr[bs];
	if(l>=a&&r<=b)
	{
		sol(k,r-l+1,v,t);
		return;
	}
	int mid=l+r>>1;
	if(a<=mid) upd(tr[k].ch[0],tr[bs].ch[0],l,mid,a,min(b,mid),v,t);
	if(b>mid) upd(tr[k].ch[1],tr[bs].ch[1],mid+1,r,max(a,mid+1),b,v,t);
	tr[k].s1=tr[tr[k].ch[0]].s1+tr[tr[k].ch[1]].s1;
	tr[k].s2=tr[tr[k].ch[0]].s2+tr[tr[k].ch[1]].s2;
}
void upd(int &k,int bs,int a,int b,int v,int t){upd(k,bs,1,n,a,b,v,t);}
void del(int t,int l,int r,int v)
{
	sg[v]={0,0};
	int nx=(--s[v].end())->second;
	int rt;
	upd(rt,nx,l,r,-1,t);
	s[v].insert({t,rt});
}
void ins(int t,int l,int r,int v)
{
	if(sg[v].first)
		sg[v].second=r;
	else
		sg[v]={l,r};
	int nx=(s[v].begin()==s[v].end()?rt0:(--s[v].end())->second);
	int rt;
	upd(rt,nx,l,r,1,-t);
	s[v].insert({t,rt});
}
pair<int,long long>operator+(pair<int,long long>a,pair<int,long long>b){return {a.first+b.first,a.second+b.second};}
pair<int,long long>query(int k,int l,int r,int a,int b)
{
	if(!k) return {0,0};
	if(l>=a&&r<=b)
		return {tr[k].s1,tr[k].s2};
	pair<int,long long> ans={(b-a+1)*tr[k].tg1,1ll*(b-a+1)*tr[k].tg2};
	int mid=l+r>>1;
	if(a<=mid) ans=ans+query(tr[k].ch[0],l,mid,a,min(b,mid));
	if(b>mid) ans=ans+query(tr[k].ch[1],mid+1,r,max(a,mid+1),b);
	return ans;
}
long long query(int t,int l,int r,int v)
{
	if(s[v].begin()==s[v].end())
		return 0;
	auto it=s[v].upper_bound({r,1000000000});
	if(it==s[v].begin())
		return 0;
	--it;
	auto x=query(it->second,1,n,l,r);
	return 1ll*(r+1)*x.first+x.second;
}
void build(int &k,int l,int r)
{
	k=++c;
	if(l==r)
		return;
	int mid=l+r>>1;
	build(tr[k].ch[0],l,mid);
	build(tr[k].ch[1],mid+1,r);
}
int main()
{
	scanf("%d",&n);
	build(rt0,1,n);
	for(int i=1;i<=n;i++)
	{
		int v,l,r,k;
		scanf("%d%d%d%d",&v,&l,&r,&k);
		v=(v+las)%(n+1);
		l=(l+las)%i+1;
		r=(r+las)%i+1;
		k=(k+las)%(n+1);
		if(l>r)
			swap(l,r);
		vis[v]=1;
		while(vis[mx])
			mx++;
		sgt.upd(v,i);
		pair<int,int>t=sg[v];
		if(t.first&&t.first<i)
		{
			del(i,t.first,t.second,v);
			while(t.second>=t.first)
			{
				pair<int,int>x=sgt.ask(t.second);
				x.second=max(x.second,t.first-1);
				ins(i,x.second+1,t.second,x.first);
				t.second=x.second;
			}
		}
		int w=(v==0?1:0);
		ins(i,i,i,w);
		las=query(i,l,r,k);
		printf("%lld\n",las);
	}
	return 0;
}