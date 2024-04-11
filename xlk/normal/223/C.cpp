#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
typedef long long ll;
ll a[2020];
ll z[2020];
ll c[2020][2020];
ll v[2020];
ll mo=1000000007;
int n,k;
int main()
{
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++)
		cin>>a[i];

	v[1]=1;
	for(int i=2;i<=2000;i++)
		v[i]=v[mo%i]*(mo-mo/i)%mo;
	for(int i=0;i<=n;i++)
	{
		c[0][i]=1;
		for(int j=0;j<i;j++)
			c[0][i]=c[0][i]*(k-1-j)%mo*v[j+1]%mo;
	}
	for(int i=1;i<=n;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=n;j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mo;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<=i;j++)
			z[i]=(z[i]+a[j]*c[i-j][i-j])%mo;
	for(int i=0;i<n;i++)
			cout<<z[i]<<' ';
	return 0;
}