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
int add(int a, int b){ a+=b;return a>=mod?a-mod:a;}
void ckadd(int &a, int b){ a=add(a,b);}
int sub(int a, int b){ a-=b;return a<0?a+mod:a;}
void cksub(int &a, int b){ a=sub(a,b);}
int mul(int a, int b){ return (ll)a*b%mod;}
void ckmul(int &a, int b){ a=mul(a,b);}
int powmod(int x, int k){ int ans=1;for(;k;k>>=1,ckmul(x,x)) if(k&1) ckmul(ans,x);return ans;}
int inv(int x){ return powmod(x,mod-2);}

const int N=3605;
int F[N],I[N];
int binom(int n, int k)
{
	if(n<k) return 0;
	return mul(F[n],mul(I[k],I[n-k]));
}
void calc()
{
	F[0]=1;
	for(int i=1;i<N;i++) F[i]=mul(F[i-1],i);
	I[N-1]=inv(F[N-1]);
	for(int i=N-2;~i;i--) I[i]=mul(I[i+1],i+1);
}

const int K=N/2;
int tmp[K],pre[K],n,m,q,dp_R[K],dp_C[K];
bool C_was[N],R_was[N];
void Clear(int a[], int n){ for(int i=0;i<=n/2;i++) a[i]=0;}
void DP(bool a[], int n, int dp[])
{
	Clear(dp,n);
	Clear(tmp,n);
	dp[0]=1;
	int h=n/2;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=h;j++)
		{
			pre[j]=tmp[j];
			tmp[j]=dp[j];
			if(i>1 && j>0 && a[i]==0 && a[i-1]==0) ckadd(dp[j],pre[j-1]);
		}
	}
}
int main()
{
	calc();
	int RS=0,CS=0;
	scanf("%i %i %i",&n,&m,&q);
	while(q--)
	{
		int x,y;
		scanf("%i %i",&x,&y);
		R_was[x]=1;
		C_was[y]=1;
		scanf("%i %i",&x,&y);
		R_was[x]=1;
		C_was[y]=1;
	}
	for(int i=1;i<=n;i++) if(!R_was[i]) RS++;
	for(int i=1;i<=m;i++) if(!C_was[i]) CS++;
	DP(R_was,n,dp_R);
	//for(int x=0;x<=n/2;x++) printf("%i ",dp_R[x]);printf("\n");
	DP(C_was,m,dp_C);
	//for(int x=0;x<=m/2;x++) printf("%i ",dp_C[x]);printf("\n");
	int ans=0;
	for(int x=0;x<=n/2;x++)
	{
		for(int y=0;y<=m/2;y++)
		{
			ckadd(ans,mul(mul(dp_R[x],dp_C[y]),mul(mul(binom(RS-2*x,y),binom(CS-2*y,x)),mul(F[x],F[y]))));
			//printf("x:%i y:%i: %i\n",x,y,mul(mul(dp_R[x],dp_C[y]),mul(mul(binom(RS-2*x,y),binom(CS-2*y,x)),mul(F[x],F[y]))));
		}
	}
	printf("%i\n",ans);
	return 0;
}