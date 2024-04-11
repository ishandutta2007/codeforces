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

const int N = 105;
int n;
int k;
char s[N];

int main()
{
	startTime = clock();

    scanf("%d%d", &n, &k);
    scanf("%s", s);
    int st = 0, fs = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'G') {
            st = i;
        } else if (s[i] == 'T') {
            fs = i;
        }
    }
    if (st > fs) swap(st, fs);
    if ((fs - st) % k > 0) {
        printf("NO\n");
        return 0;
    }
    while (st < fs) {
        if (s[st + k] != '#') {
            st += k;
        } else break;
    }
    printf(st >= fs ? "YES" : "NO");
	return 0;
}