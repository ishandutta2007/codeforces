#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans; return ans;
}
#define N 200005
#define mod 1000000007
int fac[N];
int inv[N];
int a[N];
int C(int x,int y)
{
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int qpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=ans*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return ans;
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	int n,T;
	cin>>n>>T;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		a[i]+=a[i-1];
	}
	fac[0]=fac[1]=1;
	inv[0]=inv[1]=1;
	for(int i=2;i<=n;i++)
	{
		fac[i]=fac[i-1]*i%mod;
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	}
	for(int i=2;i<=n;i++) inv[i]=inv[i-1]*inv[i]%mod;
	int ans=0,tmp=0;
	bool DO=true;
	int siz=0;
	for(int i=1;i<=n;i++)
	{
		if(T-a[i]>=i) ans=(ans+1)%mod;
		else
		{
			if(T-a[i]<0) break;
			if(DO)
			{
				DO=false;
				siz=T-a[i];
				for(int j=0;j<=siz;j++)
				{
					tmp=(tmp+C(i,j))%mod;
				}
				ans=(ans+tmp*qpow(qpow(2,i),mod-2)%mod)%mod;
			}
			else
			{
				int x=T-a[i];
				for(int j=x+1;j<=siz;j++)
				{
					tmp=(tmp-C(i-1,j)+mod)%mod;
				}
				siz=x;
				tmp=tmp*2%mod;
				tmp=(tmp-C(i-1,x)+mod)%mod;
				ans=(ans+tmp*qpow(qpow(2,i),mod-2)%mod)%mod;
			}
		}
	}
	cout<<ans<<endl;
#ifndef ONLINE_JUDGE
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}