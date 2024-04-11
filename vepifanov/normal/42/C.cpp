#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
	re x > 0 ? x : -x;
}

int n;
int m;
int x[4], y[4];

int main() {
        for (int i = 0; i < 4; i++) scanf ("%d", &x[i]);
	while (true) {
		int ok = 1;
		for (int i = 0; i < 4; i++) ok &= int (x[i] == 1);
		if (ok) break;
//		for (int i = 0; i < 4; i++) printf ("%d ", x[i]);
//		printf ("\n");
		for (int i = 0; i < 4; i++)
			if (x[i] % 2 == 0 && x[(i + 1) % 4] % 2 == 0) {
				printf ("/%d\n", i + 1);
				x[i] /= 2;
				x[(i + 1) % 4] /= 2;
				ok = 1;
				break;
			}
		if (!ok) {
			long long res = 1e15;
			int ai = -1, aj = -1, ak = -1;
			for (int i = 0; i < 4; i++)
				for (int j = -1; j < 4; j++) {
					for (int l = 0; l < 4; l++)
						y[l] = x[l];
					y[i]++; y[(i + 1) % 4]++;
					if (j != -1) { y[j]++; y[(j + 1) % 4]++; }
					while (true) {
						int ok2 = 0;
						for (int k = 0; k < 4; k++)
							if (y[k] % 2 == 0 && y[(k + 1) % 4] % 2 == 0) {
								ok2 = 1;
								y[k] /= 2;
								y[(k + 1) % 4] /= 2;
								break;
							}
						if (!ok2) break;
					}
					long long tmp = 0;
					int ok2 = 0;
					for (int l = 0; l < 4; l++) { tmp += y[l]; ok2 |= int (x[l] != y[l]); }
					if (ok2 && tmp < res) { res = tmp; ai = i; aj = j; }
				}
			x[ai]++; x[(ai + 1) % 4]++;
			printf ("+%d\n", ai + 1);
			if (aj != -1) { x[aj]++; x[(aj + 1) % 4]++; printf ("+%d\n", aj + 1); }
		}
	}
	return 0;
}