#include<cstdio>
#include<algorithm>
#include<cstring>
#define lson o<<1
#define rson o<<1|1
#define mid (l+r)/2
#define ll long long
using namespace std;
ll k,MOD,n,m,s[50005];
struct Matrix
{
	ll a[2][2];
	Matrix(){a[0][0]=a[0][1]=a[1][0]=a[1][1]=0;}
	void I(){a[0][0]=a[1][1]=1,a[0][1]=a[1][0]=0;}
	ll*operator[](int i){return a[i];}
	Matrix operator+(Matrix b)
	{
		Matrix ans;
		ans[0][0]=a[0][0]+b[0][0];
		ans[0][1]=a[0][1]+b[0][1];
		ans[1][0]=a[1][0]+b[1][0];
		ans[1][1]=a[1][1]+b[1][1];
		return ans;
	}
	Matrix operator-(Matrix b)
	{
		Matrix ans;
		ans[0][0]=a[0][0]-b[0][0];
		ans[0][1]=a[0][1]-b[0][1];
		ans[1][0]=a[1][0]-b[1][0];
		ans[1][1]=a[1][1]-b[1][1];
		return ans;
	}
	Matrix operator*(ll d)
	{
		d%=MOD;
		Matrix ans;
		ans[0][0]=a[0][0]*d%MOD;
		ans[0][1]=a[0][1]*d%MOD;
		ans[1][0]=a[1][0]*d%MOD;
		ans[1][1]=a[1][1]*d%MOD;
		return ans;
	}
	Matrix operator*(Matrix b)
	{
		Matrix ans;
		ans[0][0]=(a[0][0]*b[0][0]+a[0][1]*b[1][0])%MOD;
		ans[0][1]=(a[0][0]*b[0][1]+a[0][1]*b[1][1])%MOD;
		ans[1][0]=(a[1][0]*b[0][0]+a[1][1]*b[1][0])%MOD;
		ans[1][1]=(a[1][0]*b[0][1]+a[1][1]*b[1][1])%MOD;
		return ans;
	}
}st[50005],A[75],tree[200005];
void pushup(int o)
{
	tree[o]=tree[rson]*tree[lson];
}
void build(int o,int l,int r)
{
	if(l==r)
	{
		tree[o]=st[l];
		return;
	}
	build(lson,l,mid);
	build(rson,mid+1,r);
	pushup(o);
}
Matrix query(int o,int l,int r,int from,int to)
{
	if(l>=from&&r<=to)return tree[o];
	Matrix ans;
	ans.I();
	if(from>to)return ans;
	if(from<=mid)ans=query(lson,l,mid,from,to)*ans;
	if(to>mid)ans=query(rson,mid+1,r,from,to)*ans;
	return ans;
}
struct Diff
{
	ll p;
	ll v;
}diff[50005];
ll f0=0,f1=1;
bool cmp(Diff a,Diff b)
{
	return a.p<b.p;
}
Matrix quick_pow(ll a)
{
	Matrix ans;
	ans.I();
	for(int i=0;i<=60;i++)
	  if((1ll<<i)&a)
	    ans=ans*A[i];
	return ans;
}
int main()
{
	tree[0].I();
	scanf("%lld%lld%lld",&k,&MOD,&n);
	if(k==0)
	{
		printf("0\n");
		return 0;
	}
	for(int i=0;i<n;i++)scanf("%lld",&s[i]);
	scanf("%lld",&m);
	for(int i=1;i<=m;i++)scanf("%lld%lld",&diff[i].p,&diff[i].v);
	sort(diff+1,diff+m+1,cmp);
	while(m&&diff[m].p>=k)m--;
	for(int i=1;i<=n;i++)
	{
		st[i][0][0]=s[i%n];
		st[i][0][1]=s[i-1];
		st[i][1][0]=1;
		st[i][1][1]=0;
	}
	build(1,1,n);
	if(k-1<n)
	{
		Matrix res=query(1,1,n,1,k-1);
		ll ff1=(f1*res[0][0]+f0*res[0][1])%MOD;
		ll ff0=(f1*res[1][0]+f0*res[1][1])%MOD;
		f0=ff0,f1=ff1;
		printf("%lld\n",f1);
		return 0;
	}
	A[0].I();
	for(int i=1;i<=n;i++)A[0]=st[i]*A[0];
	for(int i=1;i<=70;i++)A[i]=A[i-1]*A[i-1];
	ll now=1;
	for(int i=1;i<=m;i++)
	{
		if(diff[i].p==diff[i-1].p+1&&i!=1)
		{
			swap(f0,f1);
			f1=(f1*diff[i-1].v+f0*diff[i].v)%MOD;
			now++;
			continue;
		}
		if(i!=1)
		{
			swap(f0,f1);
			f1=(f1*diff[i-1].v+f0*s[(diff[i-1].p+1)%n])%MOD;
			now++;
		}
		Matrix res;
		if(((now-1)/n+1)*n+1<=diff[i].p)
		{
			res=query(1,1,n,(now-1)%n+1,n);
			ll ff1=(f1*res[0][0]+f0*res[0][1])%MOD;
			ll ff0=(f1*res[1][0]+f0*res[1][1])%MOD;
			f0=ff0,f1=ff1;
			now=((now-1)/n+1)*n+1;
		}
		if(now!=diff[i].p)
		{
			if((now-1)/n+1==(diff[i].p-2)/n+1)res=query(1,1,n,(now-1)%n+1,(diff[i].p-2)%n+1);
			else res=query(1,1,n,1,(diff[i].p-2)%n+1)*quick_pow((diff[i].p-2)/n-(now-1)/n);
			ll ff1=(f1*res[0][0]+f0*res[0][1])%MOD;
			ll ff0=(f1*res[1][0]+f0*res[1][1])%MOD;
			f0=ff0,f1=ff1;
		}
		now=diff[i].p;
		swap(f1,f0);
		f1=(f1*s[(diff[i].p-1)%n]+f0*diff[i].v)%MOD;
		now++;
	}
	if(now==k)
	{
		printf("%lld\n",f1);
		return 0;
	}
	swap(f0,f1);
	f1=(f1*diff[m].v+f0*s[(diff[m].p+1)%n])%MOD;
	now++;
	Matrix res;
	if(((now-1)/n+1)*n+1<=k)
	{
		res=query(1,1,n,(now-1)%n+1,n);
		ll ff1=(f1*res[0][0]+f0*res[0][1])%MOD;
		ll ff0=(f1*res[1][0]+f0*res[1][1])%MOD;
		f0=ff0,f1=ff1;
		now=((now-1)/n+1)*n+1;
	}
	if(now==k)
	{
		printf("%lld\n",f1);
		return 0;
	}
	if((now-1)/n+1==(k-2)/n+1)res=query(1,1,n,(now-1)%n+1,(k-2)%n+1);
	else res=query(1,1,n,1,(k-2)%n+1)*quick_pow((k-2)/n-(now-1)/n);
	ll ff1=(f1*res[0][0]+f0*res[0][1])%MOD;
	ll ff0=(f1*res[1][0]+f0*res[1][1])%MOD;
	f0=ff0,f1=ff1;
	printf("%lld\n",f1);
	return 0;
}