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

const int N = 53;
int n;
string a[N];
bool g[N][N];
bool dp[N][N][N][N];

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			g[i][j] = a[i][0] == a[j][0] || a[i][1] == a[j][1];

	if (n == 1) {
		cout << "YES" << endl;
		return 0;
	}
	if (n == 2) {
		if (g[0][1]) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
		return 0;
	}
	dp[n - 3][n - 3][n - 2][n - 1] = 1;
	for (int p = n - 3; p > 0; p--)
		for (int x = 0; x < n; x++)
			for (int y = 0; y < n; y++)
				for (int z = 0; z < n; z++) {
					if (!dp[p][x][y][z]) continue;
					if (g[p - 1][z]) dp[p - 1][z][x][y] = 1;
					if (g[y][z]) dp[p - 1][p - 1][x][z] = 1;
				}
	for (int x = 0; x < n; x++)
		for (int y = 0; y < n; y++)
			for (int z = 0; z < n; z++) {
				if (g[x][z] && g[y][z] && dp[0][x][y][z]) {
					cout << "YES" << endl;
					return 0;
				}
			}

	cout << "NO" << endl;

	return 0;
}