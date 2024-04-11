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

const int N = 200200;
string a[N];
string ans[N];
string cur[N];
char ALP[] = "AGCT";
int n, m;
int bestScore;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cur[i] = a[i];
	}
	bestScore = n * m + 1;

	for (int xx = 0; xx < 4; xx++)
		for (int yy = 0; yy < xx; yy++) {
			int score = 0;
			int x = xx;
			int y = yy;
			int u = 0;
			while(u == x || u == y) u++;
			int w = x ^ y ^ u;
			for (int i = 0; i < n; i++) {
				swap(x, u);
				swap(y, w);
				int s1 = 0, s2 = 0;
				string p1, p2;
				p1.resize(m);
				p2.resize(m);
				for (int j = 0; j < m; j++) {
					swap(x, y);
					p1[j] = ALP[x];
					p2[j] = ALP[y];
					if (p1[j] != a[i][j]) s1++;
					if (p2[j] != a[i][j]) s2++;
				}
				if (s2 < s1) {
					swap(s1, s2);
					swap(p1, p2);
				}
				score += s1;
				for (int j = 0; j < m; j++)
					cur[i][j] = p1[j];
			}
			if (score < bestScore) {
				bestScore = score;
				for (int i = 0; i < n; i++)
					ans[i] = cur[i];
			}

			score = 0;
			x = xx;
			y = yy;
			u = 0;
			while(u == x || u == y) u++;
			w = x ^ y ^ u;
			for (int i = 0; i < m; i++) {
				swap(x, u);
				swap(y, w);
				int s1 = 0, s2 = 0;
				string p1, p2;
				p1.resize(n);
				p2.resize(n);
				for (int j = 0; j < n; j++) {
					swap(x, y);
					p1[j] = ALP[x];
					p2[j] = ALP[y];
					if (p1[j] != a[j][i]) s1++;
					if (p2[j] != a[j][i]) s2++;
				}
				if (s2 < s1) {
					swap(s1, s2);
					swap(p1, p2);
				}
				score += s1;
				for (int j = 0; j < n; j++)
					cur[j][i] = p1[j];
			}
			if (score < bestScore) {
				bestScore = score;
				for (int i = 0; i < n; i++)
					ans[i] = cur[i];
			}
		}
//	cerr << bestScore << endl;
	for (int i = 0; i < n; i++)
		cout << ans[i] << "\n";

	return 0;
}