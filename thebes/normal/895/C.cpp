#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;
ll dp[2][1<<20], N, i, m[72], x, f[72], pw[100005]={1};
ll p[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};

int main(){
	for(i=2;i<=70;i++){
		ll rem = i;
		for(ll j=0;j<19;j++){
			while(rem%p[j]==0){
				rem /= p[j];
				m[i] ^= (1<<j);
			}
		}
	}
	for(i=1;i<=100000;i++) pw[i]=(pw[i-1]*2)%mod;
	for(scanf("%lld",&N),i=0;i<N;i++){
		scanf("%lld",&x); 
		f[x]++;
	}
	dp[1][0] = 1;
	for(i=1;i<=70;i++){
		for(ll j=0;j<(1<<20);j++)
			dp[(i+1)%2][j] = (dp[i%2][j]*pw[max(0LL,f[i]-1)])%mod;
		for(ll j=0;j<(1<<20)&&f[i];j++){
			dp[(i+1)%2][j^m[i]]+=(dp[i%2][j]*pw[f[i]-1]);
			dp[(i+1)%2][j^m[i]]%=mod;
		}
	}
	printf("%lld\n",(dp[1][0]-1+mod)%mod);
	return 0;
}