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

const int N = 13;
const int M = (int)1e4 + 3;

int n, m;
int x[N];
int a[N][M];
char s[M];


int main()
{
	startTime = clock();

	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
			scanf("%d", x + i);
		for (int i = 0; i < n; i++) {
			scanf("%s", s);
			for (int j = 0; j < m; j++)
				a[i][j] = s[j] - '0';
		}
		long long mx = -1e18;
		vector<int> perm(m);
		for (int mask = 0; mask < (1 << n); mask++) {
			vector<int> coeff(m);
			ll total = 0;
			for (int i = 0; i < n; i++) {
				if (mask & (1 << i)) {
					total -= x[i];
					for (int j = 0; j < m; j++)
						if (a[i][j])
							coeff[j]++;
				} else {
					total += x[i];
					for (int j = 0; j < m; j++)
						if (a[i][j])
							coeff[j]--;
				}
			}
			vector<int> ord(m);
			iota(ord.begin(), ord.end(), 0);
			sort(ord.begin(), ord.end(), [&](int i, int j) {
				return coeff[i] < coeff[j];
			});
			for (int i = 0; i < m; i++)
				total += (i + 1) * coeff[ord[i]];
			if (total > mx) {
				mx = total;
				perm = ord;
			}
		}
		vector<int> ans(m);
		for (int i = 0; i < m; i++)
			ans[perm[i]] = i;
		for (int i = 0; i < m; i++)
			printf("%d ", ans[i] + 1);
		printf("\n");
	}	
}