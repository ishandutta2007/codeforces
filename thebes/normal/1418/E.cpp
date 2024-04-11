#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define F first
#define S second
#define pb push_back

#define int long long
const int MN = 2e5+5, mod = 998244353;
int N, M, i, j, arr[MN], fac[MN], inv[MN], ans[MN], sm, A, B;
struct qur{int a, b, id;}q[MN];

int qpow(int b,int exp){
	if(exp<=0) return 1;
	else if(exp&1) return 1LL*b*qpow(b,exp-1)%mod;
	else{int r=qpow(b,exp>>1); return 1LL*r*r%mod;}
}

inline int C(int n,int k){
	if(k>n) return 0;
	else return 1LL*fac[n]*inv[k]%mod*inv[n-k]%mod;
}

signed main(){
	scanf("%lld%lld",&N,&M);
	for(i=1;i<=N;i++){
		scanf("%lld",&arr[i]);
		sm = (sm+arr[i])%mod;
	}
	sort(arr+1,arr+N+1);
	fac[0] = inv[0] = 1;
	for(i=1;i<MN;i++){
		fac[i] = 1LL*i*fac[i-1]%mod;
		inv[i] = qpow(fac[i],mod-2);
	}
	for(i=1;i<=M;i++){
		scanf("%lld%lld",&q[i].a,&q[i].b);
		q[i].id = i;
	}
	sort(q+1,q+M+1,[](qur i,qur j){return i.b<j.b;});
	B = sm;
	for(i=j=1;i<=M;i++){
		while(j<=N&&arr[j]<q[i].b){
			A = (A+arr[j])%mod;
			B = (1LL*B-arr[j]+2*mod)%mod;
			j++;
		}
		int T = N-j+1;
		if(q[i].a<=T-1&&T){
			int ways = C(N,T), ways2 = fac[N-T], ways3 = fac[T-1];
			ans[q[i].id] = (ans[q[i].id]+1LL*B*ways%mod*ways2%mod*ways3%mod*(T-q[i].a)%mod)%mod;
		}
		if(q[i].a<=T&&T<N){
			int ways = C(N,T+1), ways2 = fac[N-T-1], ways3 = fac[T];
			ans[q[i].id] = (ans[q[i].id]+1LL*A*ways%mod*ways2%mod*ways3%mod*(T-q[i].a+1)%mod)%mod;
		}
	}
	for(i=1;i<=M;i++)
		printf("%lld\n",1LL*ans[i]*inv[N]%mod);
	return 0;
}