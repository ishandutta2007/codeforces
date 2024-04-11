#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <complex>
#include <iostream>
#include <cctype>
#include <cstring>
#include <bitset>
#include <stack>
#include <functional>
#include <cassert>
#include <tuple>
#include <iomanip>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt meke_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
const int mod=998244353;
int mul(int x, int y){ return (ll)x*y%mod;}
int add(int x, int y){ x+=y;return x>=mod?x-mod:x;}
int sub(int x, int y){ x-=y;return x<0?x+mod:x;}
int powmod(int x, int k){ int ans=1;for(;k;k>>=1,x=mul(x,x)) if(k&1) ans=mul(ans,x);return ans;}
int mul_inv(int x){ return powmod(x,mod-2);}
void fft(int a[], int n, bool inv)
{
	for(int i=1,j=0;i<n;i++)
	{
		int k=n;do j^=k>>=1; while(~j&k);
		if(j>i) swap(a[i],a[j]);
	}
	for(int j=2;j<=n;j<<=1)
	{
		int ang=powmod(3,(mod-1)/j);
		if(inv) ang=mul_inv(ang);
		for(int i=0;i<n/j;i++)
		{
			int cur=1;
			for(int k=i*j;k<i*j+j/2;k++)
			{
				int tmp=mul(cur,a[k+j/2]);
				a[k+j/2]=sub(a[k],tmp);
				a[k]=add(a[k],tmp);
				cur=mul(cur,ang);
			}
		}
	}
	int m=mul_inv(n);
	if(inv) for(int i=0;i<n;i++) a[i]=mul(a[i],m);
}
const int N=2000050;
int dp[2][N],par[N],nepar[N];
int main()
{
	int n,i;
	scanf("%i",&n);
	dp[1][0]=1;
	dp[0][1]=1;
	i=1;
	for(i=2;i*2-1<=n;i*=2)
	{
		for(int j=0;j<i*2;j++) par[j]=(j%2==0?dp[1][j]:0);
		for(int j=0;j<i*2;j++) nepar[j]=(j%2==1?dp[0][j]:0);
		fft(dp[0],i*2,0);
		fft(dp[1],i*2,0);
		fft(par,i*2,0);
		fft(nepar,i*2,0);
		for(int j=0;j<i*2;j++) dp[1][j]=mul(dp[0][j],nepar[j]);
		for(int j=0;j<i*2;j++) dp[0][j]=mul(dp[0][j],par[j]);
		fft(dp[0],i*2,1);
		fft(dp[1],i*2,1);
		//for(int j=0;j<i*2;j++) printf("%i ",dp[0][j]);printf("\n");
		//for(int j=0;j<i*2;j++) printf("%i ",dp[1][j]);printf("\n");
	}
	n-=i-1;
	printf("%i\n",add(dp[0][n],dp[1][n]));
	return 0;
}