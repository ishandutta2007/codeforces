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
const int N=2050;
const int M=5050;
const ll inf=1e18;
vector<ll> dp[M];
int cnt[M],a[N],s[N],c[M];
int main(){
	int n,m;
	scanf("%i %i",&n,&m);
	for(int i=1;i<=n;i++)scanf("%i",&a[i]),cnt[a[i]]++;
	for(int i=1;i<=n;i++)scanf("%i",&s[i]);
	for(int i=1;i<=n+m;i++)scanf("%i",&c[i]);
	m++;
	for(int i=1;i<=n+m;i++)cnt[i]+=cnt[i-1]/2,dp[i].resize(cnt[i]+1,-inf);
	for(int i=1;i<=n+m;i++)dp[i][0]=0;
	for(int i=n;i>=1;i--){
		//ckmx(dp[a[i]][1],c[a[i]]-s[i]);
		for(int j=cnt[a[i]];j>0;j--){
			ckmx(dp[a[i]][j],dp[a[i]][j-1]+c[a[i]]-s[i]);
		}
		for(int sz=1;sz<n+m;sz++){
			for(int j=0;j<dp[sz].size();j++)
				ckmx(dp[sz+1][j/2],dp[sz][j]+(j/2)*c[sz+1]);
		}
		/*printf("%i\n",i);
		for(int sz=1;sz<n+m;sz++){
			for(int j=0;j<dp[sz].size();j++)
				printf("(%i %i) %i| ",sz,j,dp[sz][j]);
			printf("\n");
		}*/
	}
	ll res=0;
	for(int i=1;i<=n+m;i++)ckmx(res,dp[i][0]);
	printf("%lld\n",res);
	return 0;
}