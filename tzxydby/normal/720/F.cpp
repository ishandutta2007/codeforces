#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
const long long inf=1e12;
int n,a[N],rk[N],sq[N];
ll k,s[N],v[N],pm[N];
pair<ll,ll>tr[N<<2],tg[N<<2],mx[N<<2];
pair<ll,ll>operator+(pair<ll,ll>a,pair<ll,ll>b){return {a.first+b.first,a.second+b.second};}
struct bit
{
	ll b[N];
	void init()
	{
		for(int i=0;i<=n+1;i++)
			b[i]=0;
	}
	void add(int x,ll v)
	{
		x++;
		for(int i=x;i<=n+1;i+=i&(-i))
			b[i]+=v;
	}
	ll ask(int x)
	{
		x++;
		ll v=0;
		for(int i=x;i;i-=i&(-i))
			v+=b[i];
		return v;
	}
}t1,t2;
struct rmq
{
	int st[N][20],lg[N];
	void init()
	{
		for(int i=2;i<=n+1;i++)
			lg[i]=lg[i>>1]+1;
		for(int i=0;i<=n;i++)
			st[i][0]=sq[i];
		for(int j=1;(1<<j)<=n+1;j++)
			for(int i=0;i+(1<<j)-1<=n;i++)
				st[i][j]=min(st[i][j-1],st[i+(1<<j-1)][j-1]);
	}
	int ask(int l,int r)
	{
		if(l>r) return -1;
		int d=lg[r-l+1];
		return min(st[l][d],st[r-(1<<d)+1][d]);
	}
}st;
void build(int k,int l,int r)
{
	tr[k]=mx[k]={0-inf,0},tg[k]={0,0};
	if(l==r)
		return;
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
}
void pd(int k)
{
	tr[k<<1]=tr[k<<1]+tg[k];
	mx[k<<1]=mx[k<<1]+tg[k];
	tg[k<<1]=tg[k<<1]+tg[k];
	tr[k<<1|1]=tr[k<<1|1]+tg[k];
	mx[k<<1|1]=mx[k<<1|1]+tg[k];
	tg[k<<1|1]=tg[k<<1|1]+tg[k];
	tg[k]={0,0};
}
void upd(int k,int l,int r,int x,pair<ll,ll> v)
{
	if(l==r)
	{
		mx[k]=tr[k]=v;
		if(l) tr[k].first-=pm[l-1];
		return;
	}
	pd(k);
	int mid=l+r>>1;
	if(x<=mid) upd(k<<1,l,mid,x,v);
	else upd(k<<1|1,mid+1,r,x,v);
	tr[k]=max(tr[k<<1],tr[k<<1|1]);
	mx[k]=max(mx[k<<1],mx[k<<1|1]);
}
void add(int k,int l,int r,int a,int b,pair<ll,ll> v)
{
	if(l==a&&r==b)
	{
		tr[k]=tr[k]+v;
		mx[k]=mx[k]+v;
		tg[k]=tg[k]+v;
		return;
	}
	pd(k);
	int mid=l+r>>1;
	if(b<=mid) add(k<<1,l,mid,a,b,v);
	else if(a>mid) add(k<<1|1,mid+1,r,a,b,v);
	else add(k<<1,l,mid,a,mid,v),add(k<<1|1,mid+1,r,mid+1,b,v);
	tr[k]=max(tr[k<<1],tr[k<<1|1]);
	mx[k]=max(mx[k<<1],mx[k<<1|1]);
}
pair<ll,ll>ask(int k,int l,int r,int a,int b)
{
	if(a>b) return {-inf,0};
	if(l==a&&r==b)
		return tr[k];
	pd(k);
	int mid=l+r>>1;
	if(b<=mid) return ask(k<<1,l,mid,a,b);
	else if(a>mid) return ask(k<<1|1,mid+1,r,a,b);
	else return max(ask(k<<1,l,mid,a,mid),ask(k<<1|1,mid+1,r,mid+1,b));
}
pair<ll,ll>askv(int k,int l,int r,int a,int b)
{
	if(a>b) return {-inf,0};
	if(l==a&&r==b)
		return mx[k];
	pd(k);
	int mid=l+r>>1;
	if(b<=mid) return askv(k<<1,l,mid,a,b);
	else if(a>mid) return askv(k<<1|1,mid+1,r,a,b);
	else return max(askv(k<<1,l,mid,a,mid),askv(k<<1|1,mid+1,r,mid+1,b));
}
pair<ll,ll>sol(ll x)
{
	build(1,0,n);
	t1.init(),t2.init();
	pair<ll,ll>dp={0,0};
	upd(1,0,n,0,{0,0});
	for(int i=1;i<=n;i++)
	{
		t1.add(rk[i-1],1),t2.add(rk[i-1],s[i-1]);
		int z=upper_bound(v,v+n+1,s[i]-x)-v-1;
		ll z1=t1.ask(z),z2=t2.ask(z);
		z2=z1*s[i]-z2-z1*x;
//		cout<<"base: "<<i<<' '<<z<<' '<<z1<<' '<<z2<<endl;
		add(1,0,n,0,i,{z2,z1});
		dp=dp+make_pair(z2,z1);
		if(z1==i)
			continue;
		int b=(z1?st.ask(0,z):i);
		if(b==0&&s[i]>=x)
			b--;
//		cout<<"b= "<<b<<endl;
		auto d=askv(1,0,n,b+1,i);
//		cout<<"d= "<<d.first<<' '<<d.second<<endl;
		dp=max(dp,d);
		if(!z1)
		{
			upd(1,0,n,i,dp);
			dp={-inf,0};
		}
		auto c=ask(1,0,n,0,b);
		c.first+=s[i]-x;
		c.second++;
//		cout<<"c= "<<c.first<<' '<<c.second<<endl;
		dp=max(dp,c);
//		cout<<"dp= "<<' '<<dp.first<<' '<<dp.second<<endl;
	}
	return dp;
}
int main()
{
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),s[i]=s[i-1]+a[i],sq[i]=i;
	for(int i=1;i<=n;i++)
		pm[i]=min(pm[i-1],s[i]);
	sort(sq,sq+n+1,[&](int x,int y){return s[x]<s[y];});
	for(int i=0;i<=n;i++)
		rk[sq[i]]=i,v[i]=s[sq[i]];
	for(int i=1;i<=n;i++)
		if(s[i]==s[i-1])
			rk[i]=min(rk[i],rk[i-1]);
	for(int i=n-1;i>=0;i--)
		if(s[i]==s[i+1])
			rk[i]=min(rk[i],rk[i+1]);
//	for(int i=0;i<=n;i++)
//		cout<<"#"<<i<<' '<<v[i]<<' '<<sq[i]<<endl;
	st.init();
	ll l=-5e9,r=5e9;
	while(l<r)
	{
		ll mid=(l+r+1)/2;
		if(sol(mid).second>=k)
			l=mid;
		else
			r=mid-1;
	}
	ll ans=sol(l).first;
	ans+=l*k;
	printf("%lld\n",ans);
	return 0;
}