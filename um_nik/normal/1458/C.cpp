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

struct Item {
	vector<int> p;
	vector<int> add;

	Item() : p({0, 1, 2}), add({0, 0, 0}) {}

	void change(char t) {
		if (t == 'R') {
			add[p[1]]++;
		} else if (t == 'L') {
			add[p[1]]--;
		} else if (t == 'D') {
			add[p[0]]++;
		} else if (t == 'U') {
			add[p[0]]--;
		} else if (t == 'I') {
			swap(p[1], p[2]);
		} else if (t == 'C') {
			swap(p[0], p[2]);
		} else throw;
	}

	vector<int> apply(vector<int> a) {
		vector<int> b(3);
		for (int i = 0; i < 3; i++) {
			//b[p[i]] = a[i] + add[i];
			b[i] = a[p[i]] + add[p[i]];
		}
		return b;
	}
};

const int N = 1010;
const int M = 100100;
int n, m;
int a[N][N];
int b[N][N];
char s[M];

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
			a[i][j]--;
		}
	}
	scanf("%s", s);
	Item I;
	for (int i = 0; i < m; i++) {
		I.change(s[i]);
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			vector<int> c = I.apply({i, j, a[i][j]});
			int x = c[0] % n;
			int y = c[1] % n;
			int w = c[2] % n;
			if (x < 0) x += n;
			if (y < 0) y += n;
			if (w < 0) w += n;
			b[x][y] = w + 1;
		}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
	//printf("\n");
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