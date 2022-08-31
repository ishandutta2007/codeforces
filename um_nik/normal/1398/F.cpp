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

const int N = (int)1e6 + 7;
char s[N];
int lst[2];
int a[N];
int nxt[N];
int n;
pii ord[N];

int getNext(int p) {
	return nxt[p] == p ? p : nxt[p] = getNext(nxt[p]);
}
void turnOn(int p) {
	nxt[p] = p + 1;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	scanf("%s", s);
	lst[0] = lst[1] = n;
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] != '?')
			lst[(int)(s[i] - '0')] = i;
		a[i] = max(lst[0], lst[1]) - i;
		ord[i] = mp(a[i], i);
	}
	/*
	for (int i = 0; i < n; i++)
		eprintf("%d ", a[i]);
	eprintf("\n");
	*/
	for (int i = 0; i < n; i++)
		nxt[i] = i;
	nxt[n] = n;
	sort(ord, ord + n);
	int l = 0;
	for (int k = 1; k <= n; k++) {
		while(l < n && ord[l].first < k) {
			turnOn(ord[l].second);
			l++;
		}
		int ans = 0;
		int p = 0;
		while(p < n) {
			p = getNext(p);
			if (p == n) break;
			ans++;
			p += k;
		}
		printf("%d ", ans);
	}
	printf("\n");

	return 0;
}