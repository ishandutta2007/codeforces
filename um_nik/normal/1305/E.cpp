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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

double startTime;
double getCurrentTime() {
	return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}

const int N = 5050;
int n;
int a[N];

int check() {
	if (a[0] <= 0) return -1;
	for (int i = 1; i < n; i++)
		if (a[i] <= a[i - 1])
			return -1;
	if (a[n - 1] > (int)1e9) return -1;
	set<int> setik;
	for (int i = 0; i < n; i++)
		setik.insert(a[i]);
	int res = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			if (setik.count(a[i] + a[j]))
				res++;
	eprintf("check = %d\n", res);
	return res;
}

int main()
{
	startTime = (double)clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int m;
	scanf("%d%d", &n, &m);

	int s = 0;
	int k = 2;
	while(s < m) {
		if (k >= n) {
			printf("-1\n");
			return 0;
		}
		s += k / 2;
		k++;
	}
	s -= m;
	for (int i = 0; i < k; i++)
		a[i] = i + 1;
	a[k - 1] += 2 * s;

	int d = a[k - 1] + 1;
	for (int i = k; i < n; i++)
		a[i] = d * (n + n + i);


	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
//	if (check() != m) throw;

	return 0;
}