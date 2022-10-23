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
#include <array>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
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

const int N = 200200;
int n;
ll a[N];

void solve() {
	int p, q;
	scanf("%d%d", &n, &q);
	p = q - 1;
	a[0] = 0;
	for (int i = 0; i < n; i++) {
		ll x;
		scanf("%lld", &x);
		a[i + 1] = a[i] + x;
	}
	while(p > 0 && q < n) {
		bool fnd = false;
		int l = p, r = q;
		while(l > 0 && r < n) {
			l--;
			r++;
			if (a[l] < a[p]) {
				p = l;
				fnd = true;
				break;
			}
			if (a[r] > a[q]) {
				q = r;
				fnd = true;
				break;
			}
			if (a[l] > a[q]) l = -1;
			if (a[r] < a[p]) r = n + 1;
			if (l == 0 || r == n) {
				printf("YES\n");
				return;
			}
		}
		if (fnd) continue;
		if (l != -1) {
			while(l > 0) {
				l--;
				if (a[l] < a[p]) {
					p = l;
					fnd = true;
					break;
				}
				if (a[l] > a[q]) l = -1;
			}
			if (l == 0) {
				printf("YES\n");
				return;
			}
		}
		if (r != n + 1) {
			while(r < n) {
				r++;
				if (a[r] > a[q]) {
					q = r;
					fnd = true;
					break;
				}
				if (a[r] < a[p]) r = n + 1;
			}
			if (r == n) {
				printf("YES\n");
				return;
			}
		}
		if (fnd) continue;
		printf("NO\n");
		return;
	}
	printf("YES\n");
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}