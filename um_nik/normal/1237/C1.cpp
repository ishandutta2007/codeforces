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
#include <queue>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 100100;
int n;
int a[N][3];

int solve(vector<int> p, int k) {
	int m = (int)p.size();
	if (m == 0) return -1;
	if (m == 1) return p[0];
	map<int, vector<int>> mp;
	int w = -1;
	for (int id : p) {
		mp[a[id][k]].push_back(id);
	}
	for (auto t : mp) {
		vector<int> q = t.second;
		int z = solve(q, k + 1);
		if (z == -1) continue;
		if (w == -1) {
			w = z;
		} else {
			printf("%d %d\n", w + 1, z + 1);
			w = -1;
		}
	}
	return w;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d", &a[i][j]);
	vector<int> p;
	for (int i = 0; i < n; i++)
		p.push_back(i);
	if (solve(p, 0) != -1) throw;
	
	return 0;
}