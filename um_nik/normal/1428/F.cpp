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

const int N = 500500;
int n;
char s[N];
int st[N][2];
int sz;
ll ans;
ll sumAns;

ll getSum(ll k) {
	return k * (k + 1) / 2;
}

void solve(int L) {
	st[sz][0] = 1;
	st[sz][1] = 0;
	sz++;
	if (L == 0) return;
	int val = 0;
	int len = 0;
	while(sz > 0 && val < L) {
		sz--;
		if (st[sz][1] == 0) {
			ans -= (ll)st[sz][0] * val;
			len += st[sz][0];
		} else {
			if (val + st[sz][0] > L) {
				ans -= getSum(L) - getSum(val);
				len += L - val;
				st[sz][0] -= L - val;
				val = L;
				sz++;
				break;
			}
			ans -= getSum(val + st[sz][0]) - getSum(val);
			len += st[sz][0];
			val += st[sz][0];
		}
	}
	assert(len >= L);
	if (len > L) {
		st[sz][0] = len - L;
		st[sz][1] = 0;
		sz++;
		ans += (ll)(len - L) * L;
	}
	st[sz][0] = L;
	st[sz][1] = 1;
	sz++;
	ans += getSum(L);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d %s", &n, s);
	int cur = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == '1') {
			cur++;
		} else {
			cur = 0;
		}
		solve(cur);
		sumAns += ans;
	}
	printf("%lld\n", sumAns);

	return 0;
}