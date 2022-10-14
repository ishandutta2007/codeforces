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

const int MOD = 1e9 + 7;

ll mul(ll x, ll y) {
    return (x * y) % MOD;
}

const int N = 500050;
int a[N];
int n;

struct Fenwick {
    vector<ll> fenv;

    Fenwick() : fenv(N) {}

    void add(int i, int x) {
        for (; i < N; i |= (i + 1))
            fenv[i] += x;
    }
    ll get(int i) {
        ll r = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1)
            r += fenv[i];
        return r;
    }
} F1, F2;

int main()
{
    startTime = clock();

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    vector<int> xs;
    for (int i = 0; i < n; i++)
        xs.pb(a[i]);
    sort(all(xs));
    xs.erase(unique(all(xs)), xs.end());
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int v = lower_bound(all(xs), a[i]) - xs.begin();
        F1.add(v, i + 1);
        ll S = F1.get(v);
        ans += mul(mul(a[i], n - i), S % MOD);
        ans %= MOD;
    }
    for (int i = n - 1; i >= 0; i--) {
        int v = lower_bound(all(xs), a[i]) - xs.begin();
        ll S = F2.get(v);
        ans += mul(mul(a[i], i + 1), S % MOD);
        ans %= MOD;
        F2.add(v, n - i);
    }
    printf("%lld", ans);

    return 0;
}