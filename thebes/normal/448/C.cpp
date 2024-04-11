#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;

const int MN=5005;
int dp[MN][MN], n, arr[MN], i;
int solve(int s,int e,int h){
	int mn=1<<30, last=s, ret=0;
	for(int i=s;i<=e;i++)
		mn = min(mn, arr[i]);
	for(int i=s;i<=e;i++){
		if(arr[i]==mn){
			if(last!=i) ret+=solve(last,i-1,mn);
			last = i+1;
		}
	}
	if(last!=e+1) ret+=solve(last,e,mn);
	return min(ret+mn-h,e-s+1);
}
int main(){
	for(scanf("%d",&n),i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	printf("%d\n",solve(1,n,0));
	getchar(); getchar();
}