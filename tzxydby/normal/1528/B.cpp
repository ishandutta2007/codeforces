#include<bits/stdc++.h>
using namespace std;
const int N=2000005,mod=998244353;
int n,s[N],t,f[N],p;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j+=i)
			s[j]++;
	for(int i=1;i<=n;i++)
	{
		f[i]=(p+s[i])%mod;
		p=(p+f[i])%mod;
	}
	printf("%d\n",f[n]);
	return 0;
}