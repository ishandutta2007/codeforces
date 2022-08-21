#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <limits>
#include <set>
#include <map>
using namespace std;
int n,b,k,x;
long long g[2333],s[233][233];
long long mod=1000000007;
struct matrix {int n,m; long long s[106][106];};
matrix operator * (matrix a,matrix b)
{
	matrix ans;
	ans.n=a.n; ans.m=b.m;
	for(int i=0;i<ans.n;i++)
	{
		for(int j=0;j<ans.m;j++)
		{
			long long rp=0;
			for(int k=0;k<a.m;k++) rp=(rp+a.s[i][k]*b.s[k][j]%mod)%mod;
			ans.s[i][j]=rp;
		}
	}
	return ans;
}
matrix quickpow(matrix a,long long b)
{
	matrix ans;
	bool first=1;
	while(b)
	{
		if(b&1)
		{
			if(first) {first=0; ans=a;}
			else ans=ans*a;
		}
		a=a*a; b>>=1;
	}
	return ans;
}
int main()
{
	scanf("%d%d%d%d",&n,&b,&k,&x);
	for(int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		g[a]++; g[a]%=mod;
	}
	for(int i=0;i<x;i++)
	{
		for(int j=1;j<=9;j++)
		{
			s[i][(i*10%x+j)%x]+=g[j];
			s[i][(i*10%x+j)%x]%=mod;
		}
	}
	matrix cs;
	cs.n=1; cs.m=x;
	memset(cs.s,0,sizeof(cs.s));
	cs.s[0][0]=1;
	matrix zj;
	zj.n=zj.m=x;
	for(int i=0;i<x;i++)
	{
		for(int j=0;j<x;j++) zj.s[i][j]=s[i][j];
	}
	matrix pp=quickpow(zj,b);
	matrix g=cs*pp;
	cout<<g.s[0][k];
}