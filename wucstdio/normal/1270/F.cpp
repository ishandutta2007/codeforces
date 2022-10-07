#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<cmath>
#define ll long long
using namespace std;
int n,p[200005],top,num[200005];
ll a[200005];
char s[200005];
int ss[100000005];
int main()
{
	scanf("%s",s+1);
	n=(int)strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='1')p[++top]=i;
		num[i]=num[i-1]+(s[i]=='1');
	}
	p[++top]=n+1;
	int B=(int)sqrt(n);
	ll ans=0;
	for(int x=1;x<=B;x++)
	for(int i=1;i+x<=top;i++)
	{
		int len=p[i+x-1]-p[i]+1,a=p[i]-p[i-1]-1,b=p[i+x]-p[i+x-1]-1;
		len%=x;
		len=x-len;
		len%=x;
		if(a>b)swap(a,b);
		ll k=-1;
		if(len<=a)
		{
			k=(a-len)/x;
			ans+=1ll*(len+1)*(k+1)+1ll*k*(k+1)/2*x;
		}
		if(len<=b)
		{
			ll k2=(b-len)/x;
			ans+=1ll*(k2-k)*(a+1);
			k=k2;
		}
		if(len<=a+b)
		{
			ll k2=(a+b-len)/x;
			ans+=(a+b+1-len)*(k2-k)-x*(k2*(k2+1)/2-k*(k+1)/2);
			k=k2;
		}
	}
	for(int k=0;k<=n/(B+1);k++)
	{
		int l=0;
		for(int i=1;i<=n;i++)
		{
			a[i]=a[i-1]+(s[i]=='1'?k:-1);
			while(num[i]-num[l]>B)ss[a[l]+n]++,l++;
			ans+=ss[a[i]+n];
		}
		for(int i=0;i<l;i++)ss[a[i]+n]=0;
	}
	printf("%lld\n",ans);
	return 0;
}