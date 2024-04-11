#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll inf=1e18;
int n,q,lg[N],od[N];
struct jw
{
	int w,v,id,d;
	long long c;
	bool operator<(const jw k)const
	{
		return (v==k.v?w<k.w:v>k.v);
	}
}ar[N];
pair<ll,ll>operator+(pair<ll,ll>a,pair<ll,ll>b){return {a.first+b.first,a.second+b.second};}
struct seg1
{
	pair<ll,ll>tr[N<<2];
	void build(int k,int l,int r)
	{
		if(l==r)
		{
			tr[k]={0,0};
			return;
		}
		int mid=l+r>>1;
		build(k<<1,l,mid);
		build(k<<1|1,mid+1,r);
		tr[k]=tr[k<<1]+tr[k<<1|1];
	}
	void add(int k,int l,int r,int x,int v)
	{
		if(l==r)
		{
			tr[k].first+=1ll*v*ar[l].w;
			tr[k].second+=1ll*v*ar[l].v;
			return;
		}
		int mid=l+r>>1;
		if(x<=mid) add(k<<1,l,mid,x,v);
		else add(k<<1|1,mid+1,r,x,v);
		tr[k]=tr[k<<1]+tr[k<<1|1];
	}
	pair<ll,ll>query(int k,int l,int r,int a,int b)
	{
		if(a>b)
			return {0,0};
		if(l==a&&r==b)
			return tr[k];
		int mid=l+r>>1;
		if(b<=mid) return query(k<<1,l,mid,a,b);
		else if(a>mid) return query(k<<1|1,mid+1,r,a,b);
		else return query(k<<1,l,mid,a,mid)+query(k<<1|1,mid+1,r,mid+1,b);
	}
	pair<pair<ll,ll>,int>ask(int k,int l,int r,int a,int b,ll v)
	{
		if(l==a&&r==b)
		{
			if(tr[k].first<=v)
				return {tr[k],-1};
			if(l==r)
			{
				ll d=v/ar[l].w;
				return {{d*ar[l].w,d*ar[l].v},l};
			}
			int mid=l+r>>1;
			if(tr[k<<1].first<=v)
			{
				auto x=ask(k<<1|1,mid+1,r,mid+1,r,v-tr[k<<1].first);
				x.first=x.first+tr[k<<1];
				return x;
			}
			else return ask(k<<1,l,mid,l,mid,v);
		}
		int mid=l+r>>1;
		if(b<=mid) return ask(k<<1,l,mid,a,b,v);
		else if(a>mid) return ask(k<<1|1,mid+1,r,a,b,v);
		else
		{
			auto x=ask(k<<1,l,mid,a,mid,v);
			if(x.second!=-1)
				return x;
			auto y=ask(k<<1|1,mid+1,r,mid+1,b,v-x.first.first);
			y.first=y.first+x.first;
			return y;
		}
	}
}s1[20];
struct seg2
{
	pair<ll,ll>tr[N<<2],tag[N<<2];
	void build(int k,int l,int r)
	{
		tag[k]={0,0};
		if(l==r)
		{
			tr[k]={inf,0};
			return;
		}
		int mid=l+r>>1;
		build(k<<1,l,mid);
		build(k<<1|1,mid+1,r);
		tr[k]=min(tr[k<<1],tr[k<<1|1]);
	}	
	void pd(int k)
	{
		tr[k<<1]=tr[k<<1]+tag[k];
		tag[k<<1]=tag[k<<1]+tag[k];
		tr[k<<1|1]=tr[k<<1|1]+tag[k];
		tag[k<<1|1]=tag[k<<1|1]+tag[k];
		tag[k]={0,0};
	}
	void add(int k,int l,int r,int a,int b,pair<ll,ll>v)
	{
		if(l==a&&r==b)
		{
			tr[k]=tr[k]+v;
			tag[k]=tag[k]+v;
			return;
		}
		pd(k);
		int mid=l+r>>1;
		if(b<=mid) add(k<<1,l,mid,a,b,v);
		else if(a>mid) add(k<<1|1,mid+1,r,a,b,v);
		else add(k<<1,l,mid,a,mid,v),add(k<<1|1,mid+1,r,mid+1,b,v);
		tr[k]=min(tr[k<<1],tr[k<<1|1]);
	}
	pair<pair<ll,ll>,int>ask(int k,int l,int r,int a,int b,ll v)
	{
		if(tr[k].first>v)
			return {{-1,-1},-1};
		if(l==r)
			return {tr[k],l};
		pd(k);
		int mid=l+r>>1;
		if(l==a&&r==b)
		{
			if(tr[k<<1].first<=v) return ask(k<<1,l,mid,l,mid,v);
			else return ask(k<<1|1,mid+1,r,mid+1,r,v);
		}
		if(b<=mid) return ask(k<<1,l,mid,a,b,v);
		else if(a>mid) return ask(k<<1|1,mid+1,r,a,b,v);
		else
		{
			auto x=ask(k<<1,l,mid,a,mid,v);
			if(x.first.first!=-1) return x;
			else return ask(k<<1|1,mid+1,r,mid+1,b,v);
		}
	}
}s2[20];
void upd(int x,int v)
{
	if(!v)
		return;
	if(!ar[x].c)
		s2[lg[ar[x].w]].add(1,1,n,x,x,{-inf+ar[x].w,ar[x].v});
	ar[x].c+=v;
	if(!ar[x].c)
		s2[lg[ar[x].w]].add(1,1,n,x,x,{-ar[x].w+inf,-ar[x].v});
	for(int i=lg[ar[x].w]+1;i<=18;i++)
	{
		s1[i].add(1,1,n,x,v);
		s2[i].add(1,1,n,x,n,{1ll*v*ar[x].w,1ll*v*ar[x].v});
	}
}
ll sol(ll w)
{
	ll v=0;
	int p=1;
	for(int i=18;i>=0;i--)
	{
		if(p>n)
			break;
		if(i&&(1<<i-1)>w)
			continue;
		auto pr=s1[i].query(1,1,n,1,p-1);
		auto x=s2[i].ask(1,1,n,p,n,w+pr.first);
		if(x.first.first==-1)
		{
			auto y=s1[i].ask(1,1,n,p,n,w);
			if(y.second==-1)
				y.second=n;
			w-=y.first.first;
			v+=y.first.second;
			p=y.second+1;
		}
		else
		{
			x.first.first-=pr.first;
			x.first.second-=pr.second;
			w-=x.first.first;
			v+=x.first.second;
			p=x.second+1;
		}
	}
	return v;
}
int main()
{
	ios::sync_with_stdio(0);
	for(int i=2;i<=100000;i++)
		lg[i]=lg[i>>1]+1;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>ar[i].d>>ar[i].w>>ar[i].v;
		ar[i].id=i,ar[i].c=0;
	}
	sort(ar+1,ar+n+1);
	for(int i=1;i<=n;i++)
		od[ar[i].id]=i;
	for(int i=0;i<=18;i++)
		s1[i].build(1,1,n),s2[i].build(1,1,n);
	for(int i=1;i<=n;i++)
		upd(i,ar[i].d);
	while(q--)
	{
		int t;
		cin>>t;
		if(t<=2)
		{
			int v,x;
			cin>>v>>x;
			x=od[x];
			if(t==2)
				v=-v;
			upd(x,v);
		}
		else
		{
			ll c;
			cin>>c;
			cout<<sol(c)<<"\n";
		}
	}
	return 0;
}