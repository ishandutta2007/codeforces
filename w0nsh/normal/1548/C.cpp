#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

constexpr int MOD = 1000000007;
constexpr int N = 3000047;
int fact[N];
int inv[N];
int invfact[N];

int modpow(int a, int e){
	int ret = 1;
	while(e){
		if(e&1) ret = (1ll*ret*a)%MOD;
		a = (1ll*a*a)%MOD;
		e>>=1;
	}
	return ret;
}

int binco(int n, int k){
	if(k < 0 || k > n) return 0;
	int xd = (1ll*fact[n]*invfact[k])%MOD;
	return (1ll*xd*invfact[n-k])%MOD;
}

inline int ADD(int a, int b){
	return (a + b >= MOD ? a + b - MOD : a + b);
}
inline int SUB(int a, int b){
	return (a - b < 0 ? a - b + MOD : a - b);
}
inline int NEG(int a){
	return (a == 0 ? 0 : MOD - a);
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	inv[1] = 1;
	for(int i = 2; i < N; ++i)
    	inv[i] = (MOD - (1ll * (MOD/i) * inv[MOD%i] % MOD)) % MOD;

	fact[0] = invfact[0] = 1;
	REP(i, 1, N) fact[i] = (1ll*fact[i-1]*i)%MOD;
	REP(i, 1, N) invfact[i] = (1ll*invfact[i-1]*inv[i])%MOD;

	int n, q;
	std::cin >> n >> q;
	std::vector<PII> A(q);
	FOR(i, q){
		std::cin >> A[i].X;
		A[i].Y = i;
	}
	std::sort(A.begin(), A.end());
	std::reverse(A.begin(), A.end());
	VI ans(q);

	int lastx = -1;
	VI sum(3);
	TRAV(que, A){
		int x = que.X;
		if(lastx == -1){
			REP(i, 1, n+1){
				sum[0] = ADD(sum[0], binco(3*i-2, x));
				sum[1] = ADD(sum[1], binco(3*i-1, x));
				sum[2] = ADD(sum[2], binco(3*i, x));
			}
			lastx = x;
		}else{
			while(lastx != x){
				VI ns(3);
				ns[0] = SUB(sum[1], sum[0]);
				ns[1] = SUB(sum[2], sum[1]);
				int xd = SUB(sum[0], binco(1, lastx));
				xd = ADD(xd, binco(3*n+1, lastx));
				ns[2] = SUB(xd, sum[2]);
				sum = ns;
				lastx--;
			}
		}

		ans[que.Y] = sum[2];
	}

	TRAV(i, ans) std::cout << i << "\n";

	return 0;
}