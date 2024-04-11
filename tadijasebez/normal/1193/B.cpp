#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=100050;
const int M=20*20*N;
const ll inf=9e18;
int root[N],tsz,ls[M],rs[M];
ll mx[M],lzy[M];
void Upd(int c, ll f){ mx[c]+=f;lzy[c]+=f;}
void push(int c)
{
	if(lzy[c])
	{
		if(ls[c]) Upd(ls[c],lzy[c]);
		if(rs[c]) Upd(rs[c],lzy[c]);
		lzy[c]=0;
	}
}
void Add(int c, int ss, int se, int qs, int qe, ll f)
{
	if(!c || qs>qe || qs>se || ss>qe) return;
	if(qs<=ss && qe>=se){ Upd(c,f);return;}
	push(c);
	int mid=ss+se>>1;
	Add(ls[c],ss,mid,qs,qe,f);
	Add(rs[c],mid+1,se,qs,qe,f);
	mx[c]=max(mx[ls[c]],mx[rs[c]]);
}
void Set(int &c, int ss, int se, int qi, ll x)
{
	if(!c) c=++tsz;
	if(ss==se){ mx[c]=max(mx[c],x);return;}
	push(c);
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,x);
	else Set(rs[c],mid+1,se,qi,x);
	mx[c]=max(mx[ls[c]],mx[rs[c]]);
}
ll Get(int c, int ss, int se, int qs, int qe)
{
	if(qs>qe || qs>se || ss>qe) return 0;
	if(qs<=ss && qe>=se) return mx[c];
	push(c);
	int mid=ss+se>>1;
	return max(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}
set<int> st[N];
vector<int> E[N];
int tme[N],val[N],k,n,m;
void Solve(int u)
{
	for(int v:E[u])
	{
		Solve(v);
		if(st[u].size()<st[v].size())
		{
			st[u].swap(st[v]);
			swap(root[u],root[v]);
		}
		vector<int> tmp;
		for(int x:st[v]) tmp.pb(x);
		tmp.pb(k+1);
		vector<ll> ans;
		for(int i=0;i+1<tmp.size();i++) ans.pb(Get(root[u],1,k,1,tmp[i]));
		for(int i=0;i+1<tmp.size();i++)
		{
			ll now=Get(root[v],1,k,1,tmp[i]);
			Add(root[u],1,k,tmp[i],tmp[i+1]-1,now);
			if(!st[u].count(tmp[i]))
			{
				Set(root[u],1,k,tmp[i],ans[i]+now);
				st[u].insert(tmp[i]);
			}
		}
	}
	if(tme[u]!=0)
	{
		ll tmp=Get(root[u],1,k,1,tme[u])+val[u];
		Set(root[u],1,k,tme[u],tmp);
		st[u].insert(tme[u]);
		auto it=st[u].find(tme[u]);
		it++;
		vector<int> del;
		while(it!=st[u].end())
		{
			ll now=Get(root[u],1,k,*it,*it);
			if(now>tmp) break;
			del.pb(*it);
			Set(root[u],1,k,*it,tmp);
			it++;
		}
		for(int i:del) st[u].erase(i);
	}
}
int main()
{
	scanf("%i %i %i",&n,&m,&k);
	for(int i=2;i<=n;i++)
	{
		int p;
		scanf("%i",&p);
		E[p].pb(i);
	}
	while(m--)
	{
		int u,t,w;
		scanf("%i %i %i",&u,&t,&w);
		tme[u]=t;
		val[u]=w;
	}
	Solve(1);
	printf("%lld\n",Get(root[1],1,k,1,k));
	return 0;
}