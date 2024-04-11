#include <bits/stdc++.h>
using namespace std;
const int p=1e9+7;
long long n,f[5],c;
struct matrix
{
	long long val[7][7];
	matrix operator * (matrix tmp)
	{
		matrix ans;
		memset(ans.val,0,sizeof(ans.val));
		for(int i=1;i<=5;i++)
			for(int j=1;j<=5;j++)
				for(int k=1;k<=5;k++)
					ans.val[i][j]+=val[i][k]*tmp.val[k][j]%(p-1),ans.val[i][j]%=(p-1);
		return ans;
	}
}unit;
matrix matrix_pow(matrix x,long long y)
{
	matrix ans,now=x;
	memset(ans.val,0,sizeof(ans.val));
	for(int i=1;i<=5;i++) ans.val[i][i]=1;
	while(y)
	{
		if(y&1) ans=ans*now;
		now=now*now;
		y>>=1;
	}
	return ans;
}
matrix now;
long long fast_pow(long long x,long long y)
{
	long long ans=1,now=x;
	while(y)
	{
		if(y&1) ans=(ans*now)%p;
		now=(now*now)%p;
		y>>=1;
	}
	return ans;
}
long long ans=1;
void work(int x)
{
	memset(now.val,0,sizeof(now.val));
	now.val[1][x]=1;
	ans=(ans*fast_pow(f[x],(now*matrix_pow(unit,n-3)).val[1][3]))%p;
}
void init1(void)
{
	unit.val[1][3]=unit.val[2][1]=unit.val[2][3]=unit.val[3][2]=unit.val[3][3]=1;
}
void init2(void)
{
	unit.val[4][3]=unit.val[4][4]=unit.val[5][4]=unit.val[5][5]=1;
	memset(now.val,0,sizeof(now.val));
	now.val[1][4]=now.val[1][5]=2;
}
int main()
{
	init1();
	scanf("%lld%lld%lld%lld%lld",&n,&f[1],&f[2],&f[3],&c);
	for(int i=1;i<=3;i++)
		work(i);
	init2();
	ans=(ans*fast_pow(c,(now*matrix_pow(unit,n-3)).val[1][3]))%p;
	printf("%lld",ans);
	return 0;
}