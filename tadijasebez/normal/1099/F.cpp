#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=100050;
int root,tsz,ls[N],rs[N],y[N];
ll sum[N],sz[N],tme[N],one[N];
int MakeNode(int t, int x)
{
	tsz++;
	y[tsz]=(rand()<<12)+rand();
	sz[tsz]=sum[tsz]=x;
	one[tsz]=t;
	tme[tsz]=(ll)t*x;
	return tsz;
}
void pull(int c){ if(c) sum[c]=sz[c]+sum[ls[c]]+sum[rs[c]],tme[c]=sz[c]*one[c]+tme[ls[c]]+tme[rs[c]];}
void RotL(int &c)
{
	int a=rs[c],b=ls[a];
	rs[c]=b;
	ls[a]=c;
	pull(c);pull(a);
	c=a;
}
void RotR(int &c)
{
	int a=ls[c],b=rs[a];
	ls[c]=b;
	rs[a]=c;
	pull(c);pull(a);
	c=a;
}
void Add(int &c, ll t, ll x)
{
	if(!c){ c=MakeNode(t,x);return;}
	if(mp(one[c],sz[c])<=mp(t,x))
	{
		Add(rs[c],t,x);
		if(y[rs[c]]>y[c]) RotL(c);
		else pull(c);
	}
	else
	{
		Add(ls[c],t,x);
		if(y[ls[c]]>y[c]) RotR(c);
		else pull(c);
	}
}
void Del(int &c, ll t, ll x)
{
	if(!c) return;
	if(mp(one[c],sz[c])<mp(t,x))
	{
		Del(rs[c],t,x);
		pull(c);
	}
	else if(mp(one[c],sz[c])>mp(t,x))
	{
		Del(ls[c],t,x);
		pull(c);
	}
	else
	{
		if(!ls[c]) c=rs[c];
		else if(!rs[c]) c=ls[c];
		else if(y[ls[c]]>y[rs[c]]) RotR(c),Del(rs[c],t,x);
		else RotL(c),Del(ls[c],t,x);
		pull(c);
	}
}
ll Get(int c, ll T)
{
	if(!c) return 0;
	if(tme[ls[c]]>T) return Get(ls[c],T);
	if(tme[ls[c]]+one[c]*sz[c]>T)
	{
		ll ans=sum[ls[c]];
		T-=tme[ls[c]];
		ans+=T/one[c];
		return ans;
	}
	else return sum[ls[c]]+sz[c]+Get(rs[c],T-(tme[ls[c]]+one[c]*sz[c]));
}
void P(int c){ if(!c) return;P(ls[c]);printf("(%lld %lld)",one[c],sz[c]);P(rs[c]);}
void Print(){ P(root);printf("\n");}
vector<int> E[N];
ll dep[N],val[N],dp[N],T;
int x[N],t[N],par[N];
void DFS(int u)
{
	dep[u]+=dep[par[u]];
	Add(root,t[u],x[u]);
	//printf("u:%i ",u);
	//Print();
	val[u]=Get(root,T-2*dep[u]);
	for(int v:E[u]) DFS(v);
	Del(root,t[u],x[u]);
}
void Solve(int u)
{
	vector<ll> tmp;
	for(int v:E[u]) Solve(v),tmp.pb(dp[v]);
	sort(tmp.begin(),tmp.end());
	reverse(tmp.begin(),tmp.end());
	if(tmp.size()>1) dp[u]=max(val[u],tmp[1]);
	else dp[u]=val[u];
	if(u==1 && tmp.size()) dp[u]=max(dp[u],tmp[0]);
}
int main()
{
	srand(time(0));
	int n,i;
	scanf("%i %lld",&n,&T);
	for(i=1;i<=n;i++) scanf("%i",&x[i]);
	for(i=1;i<=n;i++) scanf("%i",&t[i]);
	for(i=2;i<=n;i++) scanf("%i %lld",&par[i],&dep[i]),E[par[i]].pb(i);
	DFS(1);Solve(1);
	//for(i=1;i<=n;i++) printf("%lld ",val[i]);printf("\n");
	//for(i=1;i<=n;i++) printf("%lld ",dp[i]);printf("\n");
	printf("%lld\n",dp[1]);
	return 0;
}