#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1000003;
ll a[15][15],s[15];
ll fastpow(ll a,ll p)
{
	ll ans=1;
	while(p)
	{
		if(p&1)ans=ans*a%mod;
		a=a*a%mod;p>>=1;
	}
	return ans;
}
ll inv(ll x)
{
	return fastpow(x,mod-2);
}
void gauss(int n)
{
    for(int i=0;i<=n;i++)
    {
        int p=i;
        for(int j=i+1;j<=n;j++)if(abs(a[j][i])>abs(a[p][i]))p=j;
        swap(a[p],a[i]);
        ll x=a[i][i];
        for(int j=0;j<=n+1;j++)a[i][j]=a[i][j]*inv(x)%mod;
        for(int j=0;j<=n;j++)if(i!=j)
        {
            ll x=a[j][i];
            for(int k=0;k<=n+1;k++)a[j][k]=(a[j][k]-x*a[i][k]%mod+mod)%mod;
        }
    }
}
ll k[15];
ll f(ll x)
{
	ll res=0,t=1;
	for(int i=0;i<=10;++i)
	{
		res=(res+t*k[i]%mod)%mod;
		t=t*x%mod;
	}
	return res;
}
int main()
{
	for(int i=0;i<=10;++i)
	{
		cout<<"?"<<" "<<i<<endl;
		fflush(stdout);
		ll x;
		cin>>x;
		ll t=1;
		for(int j=0;j<=10;++j)
		{
			a[i][j]=t;
			t=t*i%mod;
		}
		a[i][11]=x;
	}
	gauss(10);
	for(int i=0;i<=10;++i)k[i]=a[i][11];
	for(int i=0;i<=1000003;++i)
	{
		if(f(i)==0)
		{
			cout<<"!"<<" "<<i<<endl;
			return 0;
		}
	}
	puts("! -1");
	return 0;
}