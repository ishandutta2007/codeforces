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

const int N = 250050;
vector<vector<int>> a;
int b[N];
int n, m;

void check(int p) {
	if (p == n) {
		printf("Yes\n");
		for (int i = 0; i < m; i++) {
			if (b[i] == 0) b[i] = 1;
			printf("%d ", b[i]);
		}
		printf("\n");
		exit(0);
	}
	vector<int> fr;
	int mistakes = 0;
	for (int i = 0; i < m; i++) {
		if (b[i] == 0) {
			fr.push_back(i);
		} else if (b[i] != a[p][i])
			mistakes++;
	}
	if (mistakes > 2) return;
	int k = (int)fr.size();
	if (mistakes + k <= 2) {
		check(p + 1);
		return;
	}
	for (int mask = 0; mask < (1 << k); mask++) {
		int ppc = mistakes;
		for (int i = 0; i < k; i++) {
			if ((mask >> i) & 1) {
				ppc++;
			} else {
				b[fr[i]] = a[p][fr[i]];
			}
		}
		if (ppc == 2) check(p + 1);
		for (int i = 0; i < k; i++)
			b[fr[i]] = 0;
	}
}

void trySolve(int p, int q) {
	vector<int> bad;
	for (int i = 0; i < m; i++) {
		if (a[p][i] != a[q][i])
			bad.push_back(i);
	}
	int k = (int)bad.size();
	assert(k == 3 || k == 4);
	vector<int> ids = {p, q};
	for (int id : ids)
		for (int mask = 0; mask < (1 << k); mask++) {
			vector<int> mist;
			for (int i = 0; i < k; i++) {
				if ((mask >> i) & 1)
					mist.push_back(bad[i]);
			}
			if ((int)mist.size() != 2) continue;
			for (int i = 0; i < m; i++) {
				if (i == mist[0] || i == mist[1]) {
					b[i] = 0;
				} else {
					b[i] = a[id][i];
				}
			}
			check(0);
		}
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	a = vector<vector<int>>(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &a[i][j]);
	for (int i = 1; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < m; j++) {
			cnt += (int)(a[0][j] != a[i][j]);
		}
		if (cnt > 4) {
			printf("No\n");
			return 0;
		}
		if (cnt <= 2) continue;
		trySolve(0, i);
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	for (int i = 0; i < m; i++)
		printf("%d ", a[0][i]);
	printf("\n");

	return 0;
}