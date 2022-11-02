#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
 
using namespace std;
 
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
 
#define equal equalll
#define less lesss

const int N = 201;
const int MAXA = 500;
const int SUM = 1111;
const int INF = 1e9 + 19;
const int BASE = 1e9 + 7;

int f[N][SUM], ff[N][SUM], a[N];
int n, k;

void add(int &x, int y) {
	x += y;
	if (x >= BASE) x -= BASE;
}
 
int main() {
	// freopen("input.txt", "r", stdin);
	scanf("%d%d", &n, &k);
	// n = 200; k = 1000;
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	// for (int i = 0; i < n; i++) a[i] = 500;
	sort(a, a + n);
	reverse(a, a + n);
	for (int i = 0; i < n; i++) a[i] = a[i] - a[i + 1];
	f[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			for (int x = 0; x <= k; x++) {
				if (f[j][x] != 0) {
					int nx = x + a[i] * (j + 1);
					if (nx <= k) add(ff[j + 1][nx], f[j][x]);
					if (j > 0) {
						// assert(x >= a[i]);
						nx = x + a[i] * (j - 1);
						int cur = (f[j][x] * 1LL * j) % BASE;
						if (nx <= k) add(ff[j - 1][nx], cur);
					}
					int cur = (f[j][x] * 1LL * (j + 1)) % BASE;
					nx = x + a[i] * j;
					if (nx <= k) add(ff[j][nx], cur);
				}
			}
		}
		swap(f, ff);
		for (int j = 0; j <= i; j++) for (int x = 0; x <= k; x++) ff[j][x] = 0;
	}
	int ans = 0;
	for (int i = 0; i <= k; i++) add(ans, f[0][i]);
	cout << ans << endl;
	cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl;
}