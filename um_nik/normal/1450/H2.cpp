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
#include <chrono>
#include <random>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}


const ll MOD = 998244353;
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
ll bin_pow(ll x, ll p) {
	if (p == 0) return 1;
	if (p & 1) return mult(x, bin_pow(x, p - 1));
	return bin_pow(mult(x, x), p / 2);
}
ll rev(ll x) {
	return bin_pow(x, MOD - 2);
}


const int N = 200200;
const int B = 200;
ll f[N], rf[N];
char s[N];
int a[N];
int n, m;
int bal = 0, q;

void setPoint(int p, int x) {
	if (p & 1) x *= -1;
	if (a[p] == 0)
		q--;
	else
		bal -= a[p];
	a[p] = x;
	if (a[p] == 0)
		q++;
	else
		bal += a[p];
}

ll getC(int n, int k) {
	if (k < 0 || k > n) return 0;
	return mult(f[n], mult(rf[k], rf[n - k]));
}

struct Item {
	int n, k;
	ll sumEven, sumOdd;
	ll sumEvenAr, sumOddAr;

	Item() : n(), k(), sumEven(), sumOdd(), sumEvenAr(), sumOddAr() {}
	Item(int _n, int _k, ll _sumEven, ll _sumOdd, ll _sumEvenAr, ll _sumOddAr) :
		n(_n), k(_k), sumEven(_sumEven), sumOdd(_sumOdd),
		sumEvenAr(_sumEvenAr), sumOddAr(_sumOddAr) {}

	void moveLeft() {
		assert(k > 0);
		ll C = getC(n, k);
		if (k % 2 == 1) {
			sumOdd = sub(sumOdd, C);
			sumOddAr = sub(sumOddAr, mult(C, k));
		} else {
			sumEven = sub(sumEven, C);
			sumEvenAr = sub(sumEvenAr, mult(C, k));
		}
		k--;
	}
	void moveRight() {
		assert(k < n);
		k++;
		ll C = getC(n, k);
		if (k % 2 == 1) {
			sumOdd = add(sumOdd, C);
			sumOddAr = add(sumOddAr, mult(C, k));
		} else {
			sumEven = add(sumEven, C);
			sumEvenAr = add(sumEvenAr, mult(C, k));
		}
	}
	void moveDown() {
		ll nSumOdd = 0, nSumEven = 0, nSumOddAr = 0, nSumEvenAr = 0;
		nSumOdd = nSumEven = add(sumOdd, sumEven);
		nSumEvenAr = add(add(sumEvenAr, sumOddAr), sumOdd);
		nSumOddAr = add(add(sumEvenAr, sumOddAr), sumEven);
		ll C = getC(n, k);
		if (k % 2 == 0) {
			nSumOdd = sub(nSumOdd, C);
			nSumOddAr = sub(nSumOddAr, mult(C, k + 1));
		} else {
			nSumEven = sub(nSumEven, C);
			nSumEvenAr = sub(nSumEvenAr, mult(C, k + 1));
		}
		n++;
		sumEven = nSumEven;
		sumOdd = nSumOdd;
		sumEvenAr = nSumEvenAr;
		sumOddAr = nSumOddAr;
	}
};

vector<Item> items[N / B + 3];

Item getItem(int n, int k) {
	Item I = items[n / B][k / B];
	while(I.n < n) I.moveDown();
	while(I.k < k) I.moveRight();
	return I;
}

ll getAns() {
	ll ans = 0;
	for (int it = -1; it <= 1; it += 2) {
		int t = bal * it + q;
		if (t <= 0) continue;
		assert(t % 2 == 0);
		Item I = getItem(q, min(q, t / 2));
		if ((t / 2) % 2 == 0) {
			ans = add(ans, mult(t, I.sumEven));
			ans = sub(ans, mult(2, I.sumEvenAr));
		} else {
			ans = add(ans, mult(t, I.sumOdd));
			ans = sub(ans, mult(2, I.sumOddAr));
		}
	}
	return mult(ans, rev(bin_pow(2, q + 1)));
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	f[0] = 1;
	for (int i = 1; i < N; i++)
		f[i] = mult(f[i - 1], i);
	rf[N - 1] = rev(f[N - 1]);
	for (int i = N - 1; i > 0; i--)
		rf[i - 1] = mult(rf[i], i);

	for (int n = 0; n < N; n += B) {
		Item I = Item(n, 0, 1, 0, 0, 0);
		for (int k = 0; k <= n; k++) {
			if (k % B == 0) items[n / B].push_back(I);
			if (k == n) break;
			I.moveRight();
		}
	}

//	eprintf("time = %.5lf\n", getCurrentTime());
//	return 0;

	scanf("%d %d %s", &n, &m, s);
	q = n;
	for (int i = 0; i < n; i++) {
		int x = 0;
		if (s[i] == 'b')
			x = 1;
		if (s[i] == 'w')
			x = -1;
		setPoint(i, x);
	}
	printf("%lld\n", getAns());
	while(m--) {
		int p;
		char c;
		scanf("%d %c", &p, &c);
		p--;
		int x = 0;
		if (c == 'b')
			x = 1;
		if (c == 'w')
			x = -1;
		setPoint(p, x);
		printf("%lld\n", getAns());
	}

	return 0;
}