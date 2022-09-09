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
template<typename T> bool ckmn(T &a,T b){T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a,T b){T c=a;a=max(a,b);return a!=c;}
int gt(vector<int> o){
	int ans=0;
	for(int i:o)ans+=1<<(i-1);
	return ans;
}
int C[10]={
	gt({1,2,3,5,6,7}),
	gt({3,6}),
	gt({1,3,4,5,7}),
	gt({1,3,4,6,7}),
	gt({2,3,4,6}),
	gt({1,2,4,6,7}),
	gt({1,2,4,5,6,7}),
	gt({1,3,6}),
	gt({1,2,3,4,5,6,7}),
	gt({1,2,3,4,6,7})};
const int N=2050;
bool dp[N][N];
int go[N][N],de[N][N];
int mask[N];
char s[10];
void B(int x){
	for(int i=0;i<7;i++)printf("%i",x>>i&1);
	printf("\n");
}
int main(){
	int n,k;
	scanf("%i %i",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		for(int j=0;j<7;j++){
			if(s[j]=='1')mask[i]+=1<<j;
		}
	}
	dp[n+1][0]=1;
	for(int i=n;i>=1;i--){
		for(int j=0;j<=k;j++){
			for(int cif=9;cif>=0;cif--){
				if((mask[i]&C[cif])==mask[i]){
					int cost=__builtin_popcount(C[cif])-__builtin_popcount(mask[i]);
					if(j-cost>=0 && dp[i+1][j-cost]){
						dp[i][j]=1;
						go[i][j]=cif;
						de[i][j]=cost;
						break;
					}
				}
			}
		}
	}
	if(dp[1][k]){
		int j=k;
		for(int i=1;i<=n;i++){
			printf("%i",go[i][j]);
			j-=de[i][j];
		}
		printf("\n");
	}else printf("-1\n");
	return 0;
}