#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,mod=1e9+7;
struct pt
{
	long long x,y;
	inline void in(){scanf("%lld%lld",&x,&y);}
	inline long long operator*(const pt&rhs)const{return x*rhs.y-rhs.x*y;}
	inline pt operator+(const pt&rhs)const{return (pt){x+rhs.x,y+rhs.y};}
	inline pt operator-(const pt&rhs)const{return (pt){x-rhs.x,y-rhs.y};}
	inline void mo(){x%=mod;y%=mod;}
}a[N],s2[N];
int n,i,j,ans,s1[N];
long long s0[N],z,tot;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		a[i].in(),s2[i]=s2[i-1]+a[i],s2[i].mo();
	for(i=2;i<=n;i++)
		z=a[i-1]*a[i],s0[i]=s0[i-1]+z,s1[i]=(s1[i-1]+s0[i])%mod;
	tot=abs(s0[n+1]=s0[n]+a[n]*a[1]);
	for(i=3,j=1;i<=n;i++)
	{
		for(;j<i-1&&abs(s0[i]-s0[j]+a[i]*a[j])>tot/2.0;j++);
		ans=(ans+s0[i]%mod*(i-1-j)-(s1[i-2]-s1[j-1])+a[i]*(s2[i-2]-s2[j-1]))%mod;
		ans=(ans+s1[j-1]+s2[j-1]*a[i]+(s0[n+1]-s0[i])%mod*(j-1))%mod;
	}
	ans=((tot%mod*(mod+1>>2)%mod*n%mod*(n-3)%mod+ans)%mod+mod)*2%mod;
	printf("%d\n",ans);
	return 0;
}