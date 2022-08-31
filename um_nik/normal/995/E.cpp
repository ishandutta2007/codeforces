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

ll p;
ll add(ll x, ll y) {
	x += y;
	if (x >= p) return x - p;
	return x;
}
ll sub(ll x, ll y) {
	x -= y;
	if (x < 0) return x + p;
	return x;
}
ll mult(ll x, ll y) {
	return (x * y) % p;
}
ll bin_pow(ll x, ll pw) {
	if (pw == 0) return 1;
	if (pw & 1) return mult(x, bin_pow(x, pw - 1));
	return bin_pow(mult(x, x), pw / 2);
}
ll rev(ll x) {
	return bin_pow(x, p - 2);
}

const int L = 17 * 2;
const int N = (int)2e6 + 5;
ll a[N], b[N];
int aSz, bSz;

int ans[300];
int ansSz;
int res[300];
int resSz;

bool brute(ll X, ll W) {
	if (resSz >= L) {
		if (W == -1)
			a[aSz++] = X;
		return X == W;
	}
	for (int d = -1; d <= 1; d += 2) {
		res[resSz++] = (3 - d) / 2;
		res[resSz++] = 3;
		if (brute(rev((X + p + d) % p), W)) return true;
		resSz -= 2;
	}
	return false;
}

void genAll(ll X) {
	aSz = 0;
	resSz = 0;
	brute(X, -1);
	resSz = 0;
	res[resSz++] = 3;
	brute(rev(X), -1);
}

bool findWant(ll X, ll W) {
	resSz = 0;
	if (brute(X, W)) return true;
	resSz = 0;
	res[resSz++] = 3;
	if (brute(rev(X), W)) return true;
	return false;
}

void printAns(ll x, ll wx, ll y, ll wy) {
//	cerr << x << " " << wx << " " << y << " " << wy << endl;
	ansSz = 0;
	if (!findWant(x, wx)) throw;
	for (int i = 0; i < resSz; i++)
		ans[ansSz++] = res[i];
	while(wx > wy) {
		ans[ansSz++] = 2;
		wx--;
	}
	while(wx < wy) {
		ans[ansSz++] = 1;
		wx++;
	}
	if (!findWant(y, wy)) throw;
	for (int i = resSz - 1; i >= 0; i--) {
		int t = res[i];
		if (t != 3) t ^= 3;
		ans[ansSz++] = t;
	}
	printf("%d\n", ansSz);
	for (int i = 0; i < ansSz; i++)
		printf("%d ", ans[i]);
	printf("\n");
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ll x, y;
	scanf("%lld%lld%lld", &x, &y, &p);
	genAll(y);
	swap(a, b);
	swap(aSz, bSz);
	genAll(x);

//	cerr << "here" << endl;
	
	sort(a, a + aSz);
	sort(b, b + bSz);

//	cerr << aSz << " " << bSz << endl;

	int p1 = 0, p2 = 0;
	while(p1 < aSz && p2 < bSz) {
		if (abs(a[p1] - b[p2]) <= 125) {
			printAns(x, a[p1], y, b[p2]);
			return 0;
		}
		if (a[p1] < b[p2])
			p1++;
		else
			p2++;
	}
	throw;

	return 0;
}