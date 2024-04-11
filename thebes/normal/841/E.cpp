#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define F first
#define S second
#define pb push_back

const int MN = 310, mod = 1e9+7;
int N, M, i, j, k, l, arr[MN], sm[MN], a[MN], dp[MN][MN], fac[2*MN], inv[2*MN];
map<int,int> mp;

int qpow(int b,int exp){
	if(exp<=0) return 1;
	else if(exp&1) return 1LL*b*qpow(b,exp-1)%mod;
	else{int r=qpow(b,exp>>1); return 1LL*r*r%mod;}
}

inline int C(int n,int k){
	if(k>n) return 0;
	else return 1LL*fac[n]*inv[k]%mod*inv[n-k]%mod;
}

int main(){
	scanf("%d",&N);
	for(i=1;i<=N;i++){
		scanf("%d",&arr[i]);
		int rem = arr[i];
		for(j=2;j*j<=arr[i];j++){
			while(rem%(j*j)==0){
				rem /= (j*j);
			}
		}
		mp[rem]++;
	}
	for(auto v : mp)
		a[++M] = v.S;
	fac[0] = inv[0] = 1;
	for(i=1;i<=2*N;i++){
		fac[i] = 1LL*i*fac[i-1]%mod;
		inv[i] = qpow(fac[i],mod-2);
	}
	dp[0][0] = 1;
	for(i=1;i<=M;i++){
		sm[i] = sm[i-1]+a[i];
		for(j=1;j<=a[i];j++){
			int ways = 1LL*C(a[i]-1,j-1)*fac[a[i]]%mod;
			int delta = a[i]-j;
			for(k=0;k<=sm[i-1]+1;k++){
				if(!dp[i-1][k]) continue;
				for(l=0;l<=min(j,k);l++){
					int ww = 1LL*C(k,l)*C(sm[i-1]+1-k,j-l)%mod;
					dp[i][k-l+delta]=(1LL*dp[i][k-l+delta]+1LL*dp[i-1][k]*ways%mod*ww)%mod;
				}
			}
		}
	}
	printf("%d\n",dp[M][0]);
	return 0;
}