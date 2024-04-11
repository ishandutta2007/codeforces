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
#define mt make_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}

const int mod=1e9+7;
int add(int a, int b){ a+=b;return a>=mod?a-mod:a;}
void ckadd(int &a, int b){ a=add(a,b);}
int sub(int a, int b){ a-=b;return a<0?a+mod:a;}
void cksub(int &a, int b){ a=sub(a,b);}
int mul(int a, int b){ return (ll)a*b%mod;}
void ckmul(int &a, int b){ a=mul(a,b);}
int powmod(int x, int k){ int ans=1;for(;k;k>>=1,ckmul(x,x)) if(k&1) ckmul(ans,x);return ans;}
int inv(int x){ return powmod(x,mod-2);}

const int N=100050;
int dp[2][N];
int Calc(int n)
{
	dp[0][0]=dp[1][0]=1;
	for(int i=1;i<=n;i++) for(int j=0;j<2;j++)
	{
		if(i>=2) dp[j][i]=add(dp[j^1][i-1],dp[j^1][i-2]);
		else dp[j][i]=dp[j^1][i-1];
	}
	return add(dp[0][n],dp[1][n]);
}
int main()
{
	int n,m;
	scanf("%i %i",&n,&m);
	int ans=sub(add(Calc(n),Calc(m)),2);
	printf("%i\n",ans);
	return 0;
}