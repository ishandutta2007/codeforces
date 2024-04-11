#include<map>
#include<set>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>
#define mod 1000000007
#define ll long long
using namespace std;
ll read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,a,b;
ll f[1000005],ans;
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		int x=read();
		if(x==1)a++;
		else b++;
	}
	f[0]=1;f[1]=1;
	for(int i=2;i<=a;i++)
		f[i]=(f[i-1]+f[i-2]*(i-1))%mod;
	ans=f[a];
	for(int i=a+1;i<=a+b;i++)
		ans=ans*i%mod;
	printf("%d\n",ans);
	return 0;
}