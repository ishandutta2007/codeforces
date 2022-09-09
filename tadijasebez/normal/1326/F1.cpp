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
const int N=14;
vector<ll> dp[1<<N][N];
int mat[N][N];
char s[N];
int main(){
	int n;
	scanf("%i",&n);
	for(int i=0;i<n;i++){
		scanf("%s",s);
		for(int j=0;j<n;j++)mat[i][j]=s[j]=='1';
	}
	for(int i=0;i<n;i++)dp[1<<i][i].pb(1);
	for(int i=0;i<1<<n;i++){
		int bc=__builtin_popcount(i);
		if(bc<=1)continue;
		for(int j=0;j<n;j++)if(i>>j&1){
			int ost=i^(1<<j);
			dp[i][j].resize(1<<(bc-1));
			for(int c=0;c<(1<<(bc-1));c++){
				int l=c>>(bc-2)&1;
				int d=c;
				if(l)d^=1<<(bc-2);
				//printf("%i %i\n",l,d);
				for(int k=0;k<n;k++)if((ost>>k&1) && mat[j][k]==l){
					dp[i][j][c]+=dp[ost][k][d];
					//printf("%i %i %i\n",d,ost,k);
				}
				//printf("%i %i %i : %i\n",c,i,j,dp[c][i][j]);
			}
		}
	}
	for(int c=0;c<1<<(n-1);c++){
		ll sum=0;
		for(int i=0;i<n;i++){
			sum+=dp[(1<<n)-1][i][c];
		}
		printf("%lld ",sum);
	}
	return 0;
}