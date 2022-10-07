#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
struct Point
{
	ll x,y,z;
	Point(ll xx=0,ll yy=0,ll zz=0){x=xx,y=yy,z=zz;}
}a[100005];
int t,n;
ll x,y,z,l1,r1,l2,r2,l3,r3,l4,r4;
bool check(ll d)
{
	l1=l2=l3=l4=-5000000000000000000;
	r1=r2=r3=r4=5000000000000000000;
	for(int i=1;i<=n;i++)
	{
		ll x=a[i].x,y=a[i].y,z=a[i].z;
		r1=min(r1,x+y+z+d);
		l1=max(l1,x+y+z-d);
		r2=min(r2,x+y-z+d);
		l2=max(l2,x+y-z-d);
		r3=min(r3,x-y+z+d);
		l3=max(l3,x-y+z-d);
		r4=min(r4,-x+y+z+d);
		l4=max(l4,-x+y+z-d);
	}
	if(l1>r1||l2>r2||l3>r3||l4>r4)return 0;
	for(int r=0;r<2;r++)
	{
		ll ll1=l1,rr1=r1,ll2=l2,rr2=r2,ll3=l3,rr3=r3,ll4=l4,rr4=r4;
		l1-=3*r,r1-=3*r;
		l2-=r,r2-=r;
		l3-=r,r3-=r;
		l4-=r,r4-=r;
		if(l1%2)l1++;if(r1%2)r1--;
		if(l2%2)l2++;if(r2%2)r2--;
		if(l3%2)l3++;if(r3%2)r3--;
		if(l4%2)l4++;if(r4%2)r4--;
		l1/=2,l2/=2,l3/=2,l4/=2;
		r1/=2,r2/=2,r3/=2,r4/=2;
		if(l1<=r1&&l2<=r2&&l3<=r3&&l4<=r4&&l2+l3+l4<=r1&&r2+r3+r4>=l1)
		{
			ll a,b,c;
			if(l2+l3+l4>=l1)a=l2,b=l3,c=l4;
			else if(r2+r3+r4<=r1)a=r2,b=r3,c=r4;
			else
			{
				a=l2,b=l3,c=l4;
				ll d=l1-l2-l3-l4;
				a+=d,d=0;
				if(a>r2)d=a-r2,a=r2;
				b+=d,d=0;
				if(b>r3)d=b-r3,b=r3;
				c+=d,d=0;
			}
			a=a*2+r,b=b*2+r,c=c*2+r;
			x=(a+b)/2,y=(a+c)/2,z=(b+c)/2;
			return 1;
		}
		l1=ll1,r1=rr1,l2=ll2,r2=rr2,l3=ll3,r3=rr3,l4=ll4,r4=rr4;
	}
	return 0;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
		ll l=0,r=3000000000000000000;
		while(l<=r)
		{
			ll mid=(l+r)>>1;
			if(check(mid))r=mid-1;
			else l=mid+1;
		}
		check(l);
		printf("%lld %lld %lld\n",x,y,z);
	}
	return 0;
}