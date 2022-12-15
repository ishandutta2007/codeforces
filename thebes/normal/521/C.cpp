#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5, mod = 1e9+7;
int N, K, i, j, x, y, arr[MN], fac[MN]={1}, inv[MN], pw[MN]={1}, ans;
inline int qpow(int b,int exp){
	if(exp<=0) return 1;
	else if(exp&1) return 1LL*b*qpow(b,exp-1)%mod;
	else{int r=qpow(b,exp>>1); return 1LL*r*r%mod;}
}
inline int C(int n,int k){return (1LL*fac[n]*inv[k]%mod)*inv[n-k]%mod;}

int main(){
	scanf("%d%d ",&N,&K);
	for(i=1;i<=N;i++){
		arr[i]=getchar()-'0';
		arr[i]=(arr[i]+arr[i-1])%mod;
		pw[i]=10LL*pw[i-1]%mod;
	}
	for(i=1;i<MN;i++){
		fac[i] = 1LL*fac[i-1]*i%mod;
	}
	inv[MN-1] = qpow(fac[MN-1],mod-2);
	for(i=MN-1;i>=1;i--){
		inv[i-1] = 1LL*inv[i]*i%mod;
	}
	for(i=0;i<N-1&&K&&N-2-i>=K-1;i++){
		ans = (ans+1LL*arr[N-i-1]*C(N-2-i,K-1)%mod*pw[i])%mod;
	}
	for(i=0;i<=N-1&&N-1-i>=K;i++){
		ans = (ans+1LL*(arr[N-i]-arr[N-i-1])*pw[i]%mod*C(N-i-1,K))%mod;
	}
	printf("%d\n",ans);
	return 0;
}