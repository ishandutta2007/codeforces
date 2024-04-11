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

const int N = 200050;
const int MOD = 998244353;
int n;
char s[N];

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	scanf("%s", s);
	bool same = true;
	for(int i = 0; i < n; i++)
		same &= (s[i] == s[0]);
	if(same) {
		printf("%lld\n", (n * 1ll * (n + 1)) / 2);
		return 0;
	}
	int cntL = 0;
	while(cntL < n && s[cntL] == s[0]) cntL++;
	int cntR = 0;
	while(cntR < n && s[n - cntR - 1] == s[n - 1]) cntR++;
	if(s[0] == s[n - 1]) {
		printf("%lld\n", ((cntL + 1) * 1ll * (cntR + 1)) % MOD);
	} else {
		printf("%d\n", cntL + cntR + 1);
	}

	return 0;
}