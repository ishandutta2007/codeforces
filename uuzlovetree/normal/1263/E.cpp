#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define mpr(a,b) make_pair(a,b)
using namespace std;
ll gcd(ll a,ll b){if(!b)return a;return gcd(b,a%b);}
ll fastpow(ll a,ll p,ll mod)
{
	ll ans=1;
	while(p)
	{
		if(p&1)ans=ans*a%mod;
		a=a*a%mod;p>>=1;
	}
	return ans;
}
ll inv(ll x,ll mod){return fastpow(x,mod-2,mod);}
#define maxn 2000005
int n;
char opt[maxn],s[maxn];
int pos;
int addv[maxn<<2],maxv[maxn<<2],minv[maxn<<2];
void pushup(int rt)
{
	maxv[rt]=max(maxv[rt<<1],maxv[rt<<1|1]);
	minv[rt]=min(minv[rt<<1],minv[rt<<1|1]);
}
void pushdown(int rt)
{
	if(addv[rt])
	{
		int t=addv[rt];
		maxv[rt<<1]+=t;maxv[rt<<1|1]+=t;
		minv[rt<<1]+=t;minv[rt<<1|1]+=t;
		addv[rt<<1]+=t;addv[rt<<1|1]+=t;
		addv[rt]=0;
	}
}
void add(int rt,int l,int r,int ql,int qr,int v)
{
	if(ql<=l&&r<=qr)
	{
		maxv[rt]+=v;minv[rt]+=v;
		addv[rt]+=v;
		return;
	}
	pushdown(rt);
	int mid=(l+r)>>1;
	if(ql<=mid)add(rt<<1,l,mid,ql,qr,v);
	if(qr>mid)add(rt<<1|1,mid+1,r,ql,qr,v);
	pushup(rt);
}
int querymax(int rt,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr)return maxv[rt];
	pushdown(rt);
	int ans=0,mid=(l+r)>>1;
	if(ql<=mid)ans=max(ans,querymax(rt<<1,l,mid,ql,qr));
	if(qr>mid)ans=max(ans,querymax(rt<<1|1,mid+1,r,ql,qr));
	pushup(rt);
	return ans;
}
int querymin(int rt,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr)return minv[rt];
	pushdown(rt);
	int ans=0,mid=(l+r)>>1;
	if(ql<=mid)ans=min(ans,querymin(rt<<1,l,mid,ql,qr));
	if(qr>mid)ans=min(ans,querymin(rt<<1|1,mid+1,r,ql,qr));
	pushup(rt);
	return ans;
}
int main()
{
	scanf("%d",&n);
	scanf("%s",opt+1);
	pos=1;
	int M=1000002;
	for(int i=1;i<=n;++i)
	{
		if(opt[i]=='L')pos=max(1,pos-1);
		else if(opt[i]=='R')pos++;
		else
		{
			if(s[pos]=='(')add(1,1,M,pos,M,-1);
			if(s[pos]==')')add(1,1,M,pos,M,1);
			s[pos]=opt[i];
			if(s[pos]=='(')add(1,1,M,pos,M,1);
			if(s[pos]==')')add(1,1,M,pos,M,-1);
		}
		if(querymax(1,1,M,M,M)!=0||querymin(1,1,M,1,M)<0)printf("%d ",-1);
		else printf("%d ",querymax(1,1,M,1,M));
	}
}