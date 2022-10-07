#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=1e9+7;
int n,cnt[105];
ll x[105],y[105];
ll quick_pow(ll x,ll a)
{
	ll ans=1;
	while(a)
	{
		if(a&1)ans=ans*x%MOD;
		x=x*x%MOD;
		a>>=1;
	}
	return ans;
}
ll quick_mul(ll x,ll y,ll MOD)
{
	if(x<0)x+=MOD;
	if(y<0)y+=MOD;
	ll ans=0;
	while(y)
	{
		if(y&1)ans=(ans+x)%MOD;
		x=(x+x)%MOD;
		y>>=1;
	}
	return ans;
}
int a[15][4],num,xx=-1,yy=-1;
void calc(ll a1,ll b1,ll a2,ll b2)
{
	num=0;
	for(ll i=2;i*i<=1000000000;i++)
	{
		int ca1=0,ca2=0,cb1=0,cb2=0;
		while(a1%i==0)a1/=i,ca1++;
		while(a2%i==0)a2/=i,ca2++;
		while(b1%i==0)b1/=i,cb1++;
		while(b2%i==0)b2/=i,cb2++;
		if(ca1==0&&ca2==0&&cb1==0&&cb2==0)continue;
		num++;
		a[num][1]=cb1;
		a[num][2]=-cb2;
		a[num][3]=ca2-ca1;
	}
	num++;
	a[num][1]=(b1!=1);
	a[num][2]=-(b2!=1);
	a[num][3]=(a2!=1)-(a1!=1);
	bool flag=0;
	for(int i=1;i<=num;i++)
	{
		for(int j=i+1;j<=num;j++)
		{
			if(a[i][1]*a[j][2]!=a[i][2]*a[j][1])
			{
				swap(a[i][1],a[1][1]),swap(a[i][2],a[1][2]),swap(a[i][3],a[1][3]);
				swap(a[j][1],a[2][1]),swap(a[j][2],a[2][2]),swap(a[j][3],a[2][3]);
				flag=1;
				break;
			}
			else if(a[i][1]*a[j][3]!=a[i][3]*a[j][1])
			{
				puts("-1");
				exit(0);
			}
			else if(a[i][2]*a[j][3]!=a[i][3]*a[j][2])
			{
				puts("-1");
				exit(0);
			}
		}
		if(flag)break;
	}
	if(!flag)return;
//	for(int i=1;i<=num;i++)printf("%d %d %d\n",a[i][1],a[i][2],a[i][3]);
//	printf("\n");
	if(!a[1][1]||!a[2][2])
	{
		swap(a[1][1],a[2][1]);
		swap(a[1][2],a[2][2]);
		swap(a[1][3],a[2][3]);
	}
	if(a[2][1])
	{
		xx=a[1][1],yy=a[2][1];
		a[1][1]*=yy,a[1][2]*=yy,a[1][3]*=yy;
		a[2][1]*=xx,a[2][2]*=xx,a[2][3]*=xx;
		a[2][2]-=a[1][2],a[2][3]-=a[1][3],a[2][1]=0;
	}
	if(a[2][3]%a[2][2])
	{
		puts("-1");
		exit(0);
	}
	yy=a[2][3]/a[2][2];
	if((a[1][3]-yy*a[1][2])%a[1][1])
	{
		puts("-1");
		exit(0);
	}
	xx=(a[1][3]-yy*a[1][2])/a[1][1];
	if(xx<0||yy<0)
	{
		puts("-1");
		exit(0);
	}
	for(int i=1;i<=num;i++)
	{
		if(a[i][1]*xx+a[i][2]*yy!=a[i][3])
		{
			puts("-1");
			exit(0);
		}
	}
}
bool check(ll a1,ll b1,ll n,ll a2,ll b2)
{
	ll ans=-1;
	for(ll i=2;i*i<=1000000000;i++)
	{
		int ca1=0,ca2=0,cb1=0,cb2=0;
		while(a1%i==0)a1/=i,ca1++;
		while(a2%i==0)a2/=i,ca2++;
		while(b1%i==0)b1/=i,cb1++;
		while(b2%i==0)b2/=i,cb2++;
		if(cb2==0&&ca2!=ca1+cb1*n)return 0;
		if(cb2==0)continue;
		if((ca1+cb1*n-ca2)%cb2)return 0;
		if(ans!=-1&&ans*cb2+ca2!=n*cb1+ca1)return 0;
		ans=(ca1+cb1*n-ca2)/cb2;
		if(ans<0)return 0;
	}
	return 1;
}
ll exgcd(ll a,ll b,ll&x,ll&y,ll d=0)
{
	return b?(d=exgcd(b,a%b,y,x),y-=a/b*x,d):(x=1,y=0,a);
}
int main()
{
	scanf("%d",&n);
	ll ans=-1;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&x[i],&y[i]);
		if(y[i]==1)ans=x[i];
	}
	if(ans!=-1)
	{
		for(int i=1;i<=n;i++)
		{
			if(y[i]==1&&x[i]!=ans)
			{
				puts("-1");
				exit(0);
			}
			ll v=x[i];
			while(v<ans)v=v*y[i];
			if(v!=ans)
			{
				puts("-1");
				exit(0);
			}
		}
		printf("%lld\n",ans);
		return 0;
	}
	for(int i=2;i<=n;i++)calc(x[1],y[1],x[i],y[i]);
	if(xx!=-1&&yy!=-1)
	{
		for(int i=2;i<=n;i++)
		{
			if(!check(x[1],y[1],xx,x[i],y[i]))
			{
				puts("-1");
				return 0;
			}
		}
		printf("%lld\n",x[1]*quick_pow(y[1],xx)%MOD);
		return 0;
	}
	ll p=1;
	ll val=y[1];
	num=0;
	int d=0;
	for(int i=2;i*i<=val;i++)
	{
		if(val%i==0)
		{
			num++;
			while(val%i==0)
			{
				val/=i;
				cnt[num]++;
			}
			d=__gcd(d,cnt[num]);
		}
	}
	if(val!=1)
	{
		num++;
		cnt[num]=1;
		d=1;
	}
	val=y[1],num=0;
	for(int i=2;i*i<=val;i++)
	{
		if(val%i==0)
		{
			num++;
			cnt[num]/=d;
			while(cnt[num]--)p=p*i,val/=i;
		}
	}
	if(val!=1)
	{
		num++;
		cnt[num]/=d;
		while(cnt[num]--)p=p*val;
	}
	val=x[1];
	while(val%p==0)val/=p;
	ll nowa=0,nowm=1;
	for(int i=1;i<=n;i++)
	{
		ll c1=0,c2=0;
		while(x[i]%p==0)c1++,x[i]/=p;
		while(y[i]%p==0)c2++,y[i]/=p;
		x[i]=c1,y[i]=c2;
		ll k1=0,k2=0;
		ll d=exgcd(nowm,c2,k1,k2);
		if((c1-nowa)%d)
		{
			puts("-1");
			return 0;
		}
		nowm=nowm/d*c2;
		nowa=quick_mul(quick_mul(k1,nowm/c2*d,nowm),(c1-nowa)/d,nowm)+nowa;
		nowa%=nowm;
		if(nowa<0)nowa+=nowm;
	}
	ans=nowa;
	for(int i=1;i<=n;i++)
	{
		while(ans<x[i])
		  ans+=nowm;
	}
	printf("%lld\n",quick_pow(p,ans)*val%MOD);
	return 0;
}