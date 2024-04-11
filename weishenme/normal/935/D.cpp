#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=1e9+7;
typedef long long ll;
ll a[N],b[N],n,m,f[N]; 
ll ksm(ll x,ll y)
{
	if (!y)return 1;
	ll z=ksm(x,y/2);
	z*=z;z%=M;
	if (y&1)z*=x;
	z%=M;
	return z;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)scanf("%d",&b[i]);
	ll ni=ksm(m,M-2);
	for (int i=n;i;i--)
	 {
	 	if (a[i]==0&&b[i]==0)f[i]=m*(m-1)/2%M*ni%M*ni%M+f[i+1]*ni%M;
	 	else if (a[i]==0)f[i]=(m-b[i])*ni%M+f[i+1]*ni%M;
	 	else if (b[i]==0)f[i]=(a[i]-1)*ni%M+f[i+1]*ni%M;
	 	else if (a[i]>b[i])f[i]=1;
	 	else if (a[i]<b[i])f[i]=0;
	 	else f[i]=f[i+1];
	 	f[i]%=M;
	 }
	cout<<f[1]; 
}