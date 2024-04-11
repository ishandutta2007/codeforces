#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt meke_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
const int N=105;
const int mod=1e9+7;
int add(int x, int y){ x+=y;return x>=mod?x-mod:x;}
int mul(int x, int y){ return (ll)x*y%mod;}
struct Matrix
{
	int a[N][N];
	Matrix(){}
};
Matrix operator * (Matrix a, Matrix b)
{
	Matrix ans;
	for(int i=1;i<N;i++)
	{
		for(int j=1;j<N;j++)
		{
			ans.a[i][j]=0;
			for(int k=1;k<N;k++)
			{
				ans.a[i][j]=add(ans.a[i][j],mul(a.a[i][k],b.a[k][j]));
			}
		}
	}
	return ans;
}
int main()
{
	ll n;
	int m;
	scanf("%lld %i",&n,&m);
	Matrix dp;
	dp.a[1][1]=1;
	dp.a[1][m]=1;
	for(int i=2;i<=m;i++) dp.a[i][i-1]=1;
	Matrix ans;
	for(int i=1;i<=m;i++) ans.a[i][i]=1;
	for(;n;n>>=1,dp=dp*dp) if(n&1) ans=ans*dp;
	printf("%i\n",ans.a[1][1]);
	return 0;
}