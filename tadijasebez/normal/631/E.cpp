#include <stdio.h>
#include <set>
using namespace std;
#define ll long long
const int N=200050;
const int H=1000050;
const int M=40*N;
const ll inf=9e18;
/*bool Q;
struct Line
{
	mutable ll k,n,x;
	Line(ll a, ll b, ll c=0){ k=a,n=b,x=c;}
	bool operator < (Line b) const{ return Q?x<b.x:k>b.k;}
	ll operator ^ (Line b) const
	{
		ll p=n-b.n,q=b.k-k;
		if(q<0) p=-p,q=-q;
		if(p>0) return p/q;
		return -((-p+q-1)/q);
	}
};
struct DynamicConvexHullTrick : multiset<Line>
{
	bool Bad(iterator it)
	{
		if(it==end()) return 0;
		iterator it1,it2;
		it1=it;it1++;
		if(it1==end()) it->x=inf;
		else it->x=*it^*it1;
		if(it==begin() || it1==end()) return 0;
		it1=it;it1--;
		it2=it;it2++;
		if((*it1^*it)>=(*it1^*it2)) erase(it);
		else return 0;
		return 1;
	}
	void AddLine(ll k, ll n)
	{
		iterator it=lower_bound(Line(k,n)),it1;
		if(it!=end() && it->k==k)
		{
			if(it->n<n) return;
			it->n=n;
		}
		else insert(Line(k,n));
		it=find(Line(k,n));
		if(Bad(it)) return;
		do{it1=it;it1++;}while(Bad(it1));
		while(it!=begin())
		{
			it1=it;it1--;
			if(!Bad(it1)) break;
		}
		Bad(it);
	}
	ll Query(ll x)
	{
		if(empty()) return inf;
		Q=1;iterator it=lower_bound(Line(0,0,x));Q=0;
		if(it!=end()) return it->k*x+it->n;
	}
} Hull;*/
struct Line
{
	ll k,n;
	Line(){}
	Line(ll a, ll b){ k=a,n=b;}
	ll Get(ll x){ return k*x+n;}
} line[M];
ll max(ll a, ll b){ return a>b?a:b;}
void Swap(Line &a, Line &b){ Line tmp=a;a=b;b=tmp;}
bool has[M];
int ls[M],rs[M],tsz,root;
//void Init(){ for(int i=1;i<=tsz;i++) ls[i]=rs[i]=has[i]=0;tsz=root=0;}
void AddLine(int &c, int ss, int se, Line k)
{
	if(!c) c=++tsz;
	if(!has[c]){ has[c]=1;line[c]=k;return;}
	if(line[c].Get(ss)>=k.Get(ss) && line[c].Get(se)>=k.Get(se)) return;
	if(line[c].Get(ss)<=k.Get(ss) && line[c].Get(se)<=k.Get(se)){ line[c]=k;return;}
	int mid=(ss+se)/2;
	if(line[c].Get(ss)<k.Get(ss)) Swap(line[c],k);
	if(line[c].Get(mid)<k.Get(mid)) Swap(line[c],k),AddLine(ls[c],ss,mid,k);
	else AddLine(rs[c],mid+1,se,k);
}
ll Get(int c, int ss, int se, ll qi)
{
	if(!has[c]) return -inf;
	if(ss==se) return line[c].Get(qi);
	int mid=(ss+se)/2;
	if(qi<=mid) return max(line[c].Get(qi),Get(ls[c],ss,mid,qi));
	else return max(line[c].Get(qi),Get(rs[c],mid+1,se,qi));
}
/*#define mp make_pair
void Swap(pair<ll,ll> &a, pair<ll,ll> &b){ pair<ll,ll> tmp=a;a=b;b=tmp;}
ll max(ll a, ll b){ return a>b?a:b;}
struct LiChao
{
	int ls[M],rs[M],root[25],bck[25],tsz,sz,n;
	bool has[M];
	pair<ll,ll> line[M];
	LiChao(){}
	void Init(int _n){ n=_n;}
	void AddRoot(){ root[sz+1]=root[sz];sz++;bck[sz]=tsz;}
	void DelRoot(){ tsz=bck[sz];sz--;}
	ll Get(pair<ll,ll> line, ll x){ return (ll)line.first*x+line.second;}
	void AddLine(int p, int &c, int ss, int se, pair<ll,ll> x)
	{
		c=++tsz;ls[c]=ls[p];rs[c]=rs[p];has[c]=has[p];line[c]=line[p];
		if(!has[c]){ has[c]=1;line[c]=x;return;}
		ll A=Get(line[c],ss),B=Get(x,ss),C=Get(line[c],se),D=Get(x,se);
		if(A>=B && C>=D) return;
		if(A<=B && C<=D){ line[c]=x;return;}
		if(A<B) Swap(line[c],x);
		int mid=ss+se>>1;
		if(Get(line[c],mid)>=Get(x,mid)) AddLine(rs[p],rs[c],mid+1,se,x);
		else Swap(line[c],x),AddLine(ls[p],ls[c],ss,mid,x);
	}
	void AddLine(pair<ll,ll> x){ AddLine(root[sz],root[sz],-n,n,x);}
	ll Get(int c, int ss, int se, ll qi)
	{
		ll ans=-inf;
		if(has[c]) ans=Get(line[c],qi);
		if(ss==se) return ans;
		int mid=ss+se>>1;
		if(qi<=mid) return max(ans,Get(ls[c],ss,mid,qi));
		else return max(ans,Get(rs[c],mid+1,se,qi));
	}
	ll Get(ll x){ return Get(root[sz],-n,n,x);}
} Tree;*/
int max(int a, int b){ return a>b?a:b;}
ll a[N];
ll l[N],r[N];
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(i=1;i<=n;i++) l[i]=l[i-1]+a[i];
	for(i=n;i>=1;i--) r[i]=r[i+1]+a[i];
	ll sum=0;
	for(i=1;i<=n;i++) sum+=a[i]*i;
	ll sol=sum;
	//Tree.Init(H);
	//Tree.AddRoot();
	for(i=2;i<=n;i++)
	{
		AddLine(root,-H,H,Line((i-1),-l[i-2]));
		ll ans=Get(root,-H,H,a[i])+sum;
		ans+=l[i-1];
		ans-=a[i]*i;
		sol=max(sol,ans);
	}
	root=0;
	//Tree.DelRoot();
	//Tree.AddRoot();
	for(i=n-1;i>=1;i--)
	{
		AddLine(root,-H,H,Line((i+1),-l[i+1]));
		ll ans=Get(root,-H,H,a[i])+sum;
		ans+=l[i];
		ans-=a[i]*i;
		sol=max(sol,ans);
	}
	printf("%lld\n",sol);
	return 0;
}