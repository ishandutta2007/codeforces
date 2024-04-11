#include <iostream>
#include <sstream>
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

const int N = 1e5;
const int C = 100;

long long f[N][2];
long long s, x, a[N], b[N];

int main() {
	// freopen("input.txt", "r", stdin);
	cin >> x >> s;
	long long ss = s;
	long long xx = x;
	for (int i = 0; i < C; i++) {
		a[i] = s % 2;
		s /= 2;
		b[i] = x % 2;
		x /= 2;
	}
	f[0][0] = 1;
	for (int i = 0; i < C; i++) {
		for (int j = 0; j < 2; j++) {
			if (f[i][j] != 0) {
				for (int u = 0; u < 2; u++) {
					for (int v = 0; v < 2; v++) {
						int x = (u ^ v);
						int y = (u + v + j) % 2;
						int z = (u + v + j) / 2;
						if ((x == a[i]) && (y == b[i])) {
							f[i + 1][z] += f[i][j];
						}
					}
				}
			}
		}
	}
	long long ans = f[C][0];
	if (ss == xx) {
		assert(ans >= 2);
		ans -= 2;
	}
	cout << ans << endl;
	return 0;	
}