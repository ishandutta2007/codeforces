#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

ll MOD;
ll add(ll x, ll y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
ll sub(ll x, ll y) {
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
ll mult(ll x, ll y) {
	return (x * y) % MOD;
}

const int N = 404;
//const int N = 40;
ll f[N];
ll A[N];
ll P[N];
ll B[N];
ll dp[N][N];


int main()
{
	int t;
	scanf("%d%lld", &t, &MOD);
	f[0] = 1;
	for (int i = 1; i < N; i++)
		f[i] = mult(f[i - 1], i);
	for (int i = 0; i < N; i++) {
		B[i] = f[i];
		for (int j = 1; j < i; j++)
			B[i] = sub(B[i], mult(B[j], f[i - j]));
	}
	for (int i = 0; i < N; i++) {
		P[i] = f[i];
		for (int j = 2; j < i; j++)
			P[i] = sub(P[i], mult(P[j], f[i - j + 1]));
	}
	dp[1][1] = 1;
	for (int n = 0; n < N; n++) {
		A[n] = P[n];
		if (n >= 3) A[n] = sub(A[n], mult(2, B[n - 1]));
		for (int m = 1; m < n; m++)
			for (int k = 0; k < n; k++)
				dp[n][k + 1] = add(dp[n][k + 1], mult(dp[n - m][k], f[m]));
		for (int k = 3; k < n; k++)
			A[n] = sub(A[n], mult(dp[n][k], A[k]));
	}
	
	while(t--) {
		int x;
		scanf("%d", &x);
		printf("%lld\n", A[x]);
	}
	
    return 0;
}