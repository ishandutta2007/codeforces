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
using namespace std;
long long f[2020][2020];
long long g[2020][2020];
int n,m;
int p=1000000007;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=2;i<=m;i++)
		f[1][i]=1;
	for(int i=2;i<=n;i++)
	{
		long long s=0,c=0;
		for(int j=1;j<=m;j++)
		{
			s+=f[i-1][j];
			s%=p;
			c+=s;
			c%=p;
			f[i][j]+=c;
			f[i][j]%=p;
		}
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			f[i][j]+=f[i-1][j];
			f[i][j]%=p;
		}
	}
	long long z=0;
	for(int i=1;i<=n;i++)
		for(int k=1;k<=m;k++) 
		{
			z=(z+f[i][k]*f[n-i+1][k]%p*(m-k+1))%p;
		}
	for(int i=1;i<n;i++)
		for(int k=1;k<=m;k++) 
		{
			z=(z-f[i][k]*f[n-i][k]%p*(m-k+1))%p;
		}
	cout << (z+p)%p << endl;
}