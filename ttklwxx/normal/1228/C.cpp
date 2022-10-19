#include<iostream>
#include<cstdio>
#include<cmath>
#define mod 1000000007
#define int long long
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int ksm(int n,int k)
{
	if(k==0)return 1;
	if(k==1)return n;
	int nn=ksm(n,k/2);
	if(k%2==1)return 1LL*nn*nn%mod*1LL*n%mod;
	else return 1LL*nn*nn%mod; 
}
int sl(int n,int p)
{
	int ans=0;
	while(n!=0)
	{
		ans+=n/p;
		n/=p;
	}
	return ans;
}
signed main()
{
    int x,n,sth,ans=1;
    x=read();
    n=read();
    sth=sqrt(x);
    for(int i=2;i<=sth;i++)
    {
    	if(x%i!=0)continue;
    	while(x%i==0)x/=i;
    	ans=ans*ksm(i,sl(n,i))%mod;
	}
	if(x>1)ans=ans*ksm(x,sl(n,x))%mod;
	cout<<ans<<endl;
    return 0;
}