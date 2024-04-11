#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=200050;
const int M=2*N;
const ll inf=9e18;
struct Line
{
	ll k,n;
	Line(ll a=0, ll b=0){ k=a,n=b;}
	ll Get(ll x){ return k*x+n;}
};
vector<ll> id;
int Find(ll x){ return lower_bound(id.begin(),id.end(),x)-id.begin();}
struct LiChao
{
	int ls[M],rs[M],tsz,root;
	Line line[M];
	LiChao(){ root=tsz=0;}
	void Set(int &c, int ss, int se, Line k)
	{
		if(!c){ c=++tsz;line[c]=k;return;}
		ll A=line[c].Get(id[ss]),B=k.Get(id[ss]),C=line[c].Get(id[se]),D=k.Get(id[se]);
		if(A>=B && C>=D) return;
		if(A<=B && C<=D){ line[c]=k;return;}
		int mid=ss+se>>1;
		if(A<B) swap(line[c],k);
		if(line[c].Get(id[mid])>=k.Get(id[mid])) Set(rs[c],mid+1,se,k);
		else swap(line[c],k),Set(ls[c],ss,mid,k);
	}
	void Set(ll k, ll n){ Set(root,0,(int)id.size()-1,Line(k,n));}
	ll Get(int c, int ss, int se, int qi)
	{
		if(!c) return -inf;
		if(ss==se) return line[c].Get(id[qi]);
		int mid=ss+se>>1;
		ll ans=line[c].Get(id[qi]);
		if(qi<=mid) ans=max(ans,Get(ls[c],ss,mid,qi));
		else ans=max(ans,Get(rs[c],mid+1,se,qi));
		return ans;
	}
	ll Get(ll x){ return Get(root,0,(int)id.size()-1,Find(x));}
} Hull;
int a[N];
ll sum[N],S[N];
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),sum[i]=sum[i-1]+a[i],S[i]=S[i-1]+(ll)a[i]*i,id.pb(sum[i]);
	sort(id.begin(),id.end());id.resize(unique(id.begin(),id.end())-id.begin());
	//for(auto p:id) printf("%lld ",p);printf("\n");
	ll sol=0;
	for(i=1;i<=n;i++)
	{
		int l=i-1;
		Hull.Set(-l,sum[l]*l-S[l]);
		sol=max(sol,Hull.Get(sum[i])+S[i]);
		//printf("%i: %lld\n",i,Hull.Get(sum[i])+S[i]);
	}
	printf("%lld\n",sol);
	return 0;
}