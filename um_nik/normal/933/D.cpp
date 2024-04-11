#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const ll MOD = (ll)1e9 + 7;
ll add(ll x, ll y) {
	x = (x + y) % MOD;
	if (x < 0) x += MOD;
	return x;
}
ll sub(ll x, ll y) {
	x = (x - y) % MOD;
	if (x < 0) x += MOD;
	return x;
}
ll mult(ll x, ll y) {
	return ((x % MOD) * (y % MOD)) % MOD;
}

ll ANS = 0;

const int N = 100;
ll rev[N];
ll M;

ll get1(ll s) {
	ll res = s - 1;
	res = mult(res, s);
	res = mult(res, 3 * M - 2 * s + 4);
	return mult(res, rev[6]);
}

ll getC0(ll A) {
	ll res = (A * A - 1) % MOD;
	res = mult(res, A * A);
	res = mult(res, 3 * M - 2 * A * A + 4);
	return res;
}
ll getC1(ll A) {
	ll res = 0;
	res = add(res, mult(A * A, 3 * M - 2 * A * A + 4));
	res = add(res, mult(A * A - 1, 3 * M - 2 * A * A + 4));
	res = sub(res, mult(2 * A * A, A * A - 1));
	return res;
}
ll getC2(ll A) {
	ll res = 3 * M - 2 * A * A + 4 - 2 * A * A - 2 * (A * A - 1);
	return (res % MOD + MOD) % MOD;
}

ll getSum2(ll L) {
	ll res = L;
	res = mult(res, L + 1);
	res = mult(res, 2 * L + 1);
	return mult(rev[6], res);
}
ll getSum4(ll L) {
	ll res = L;
	res = mult(res, L + 1);
	res = mult(res, 2 * L + 1);
	res = mult(res, 3 * mult(L, L) + 3 * L - 1);
	return mult(rev[30], res);
}
ll getSum6(ll L) {
	ll res = 1;
	res = sub(res, 3 * L);
	res = add(res, 6 * mult(L, L) * L);
	res = add(res, 3 * mult(mult(L, L), mult(L, L)));
	res = mult(res, L);
	res = mult(res, L + 1);
	res = mult(res, 2 * L + 1);
	return mult(rev[42], res);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	rev[1] = 1;
	for (ll x = 2; x < N; x++) {
		rev[x] = (MOD - rev[MOD % x] * (MOD / x) % MOD) % MOD;
	}

	scanf("%lld", &M);
	ll L = 0;
	for (ll A = (ll)1e6 + 3; A > 0; A--) {
		if (A * A > M) continue;
		ANS = add(ANS, mult(4, sub(get1(M + 1), get1(A * A))));
		while(A * A + (L + 1) * (L + 1) <= M) L++;
		//cerr << A << " " << L << endl;
		//for (ll x = 1; A * A + x * x <= M; x++)
		//	ANS = add(ANS, mult(4, sub(get1(M + 1), get1(A * A + x * x))));
		
		ll cur = mult(L, get1(M + 1));
		ll C0 = getC0(A), C1 = getC1(A), C2 = getC2(A);
		cur = sub(cur, mult(rev[6], mult(C0, L)));
		cur = sub(cur, mult(rev[6], mult(C1, getSum2(L))));
		cur = sub(cur, mult(rev[6], mult(C2, getSum4(L))));
		cur = add(cur, mult(rev[3], getSum6(L)));
		ANS = add(ANS, mult(4, cur));
		
	}
	ANS = add(ANS, get1(M + 1));
	printf("%lld\n", ANS);

	return 0;
}