#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
#define lson o<<1
#define rson o<<1|1
#define mid ((l+r)>>1)
using namespace std;
const ll MOD=1e9+7;
struct Point
{
	ll x,y;
	Point(ll xx=0,ll yy=0){x=xx,y=yy;}
	Point operator+(Point p){return Point(x+p.x,y+p.y);}
	Point operator-(Point p){return Point(x-p.x,y-p.y);}
	ll det(Point p){return x*p.y-y*p.x;}
}p[500005],sum[500005];
int n;
ll ans,s,a[2000005],b[2000005];
Point ask(int l,int r)
{
	if(l>r)return ask(l,n)+ask(1,r);
	return sum[r]-sum[l-1];
}
void add(int o,int l,int r,int from,int to,ll aa,ll bb)
{
	if(from>to)
	{
		add(1,1,n,from,n,aa,bb);
		add(1,1,n,1,to,(aa+bb*(n-from+1))%MOD,bb);
		return;
	}
	if(l>=from&&r<=to)
	{
		a[o]=(a[o]+aa)%MOD;
		b[o]=(b[o]+bb)%MOD;
		return;
	}
	if(to<=mid)return add(lson,l,mid,from,to,aa,bb);
	if(from>mid)return add(rson,mid+1,r,from,to,aa,bb);
	add(lson,l,mid,from,to,aa,bb);
	add(rson,mid+1,r,from,to,(aa+bb*(mid-max(l,from)+1))%MOD,bb);
}
ll query(int o,int l,int r,int p)
{
	ll ans=a[o]+b[o]*(p-l);
	if(l==r)return ans;
	if(p<=mid)ans+=query(lson,l,mid,p);
	else ans+=query(rson,mid+1,r,p);
	return ans%MOD;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld%lld",&p[n-i+1].x,&p[n-i+1].y);
	s=0;
	for(int i=1;i<=n;i++)
	{
		s+=p[i].det(p[i%n+1]);
		sum[i]=sum[i-1]+p[i];
	}
	int j=1;
	ll ss=0;
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		while(ss<=s/2)
		{
			ss-=p[j].det(p[i]);
			ss+=p[j].det(p[j%n+1]);
			j=j%n+1;
			ss+=p[j].det(p[i]);
		}
		if(i!=j%n+1)
		{
//			printf("[%d,%d],%d [%d,%d],%d,%d\n",i,(j-2+n)%n+1,(i+n-j-1)%n,j,(i-2+n)%n+1,(i+n-j-1)%n-2,-2);
//			printf("s=%lld\n",ss);
			add(1,1,n,i,(j-2+n)%n+1,(i+n-j-1)%n,0);
			add(1,1,n,j,(i-2+n)%n+1,(i+n-j-1)%n-2,-2);
			add(1,1,n,(i-2+n)%n+1,(i-2+n)%n+1,2,0);
			Point a=ask(j,(i+n-3)%n+1);
//			printf("(%lld,%lld) det [%d,%d]\n",p[i].x,p[i].y,j,(i+n-3)%n+1);
			a.x%=MOD,a.y%=MOD;
			ans=(ans+a.det(p[i])*2)%MOD;
		}
		ss-=p[j].det(p[i]);
		ss-=p[i].det(p[i%n+1]);
		ss+=p[j].det(p[i%n+1]);
	}
	for(int i=1;i<=n;i++)
	{
//		printf("%lld\n",query(1,1,n,i));
		ans=(ans+p[i].det(p[i%n+1])%MOD*query(1,1,n,i))%MOD;
	}
	if(ans<0)ans+=MOD;
	printf("%lld\n",ans);
	return 0;
}