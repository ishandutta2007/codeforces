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
int m, k;
int use[35][35];
map<string, ii> all;

int main() {
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		string s;
		cin >> s;
		if (s == "+1") {
			int x, y;
			cin >> x >> y >> s;
			while (use[x][y]) {
				if (y < m) y++; else
				if (x < n) { x++; y = 1; } else break;
			}
			if (!use[x][y]) {
				use[x][y] = 1;
				all[s] = mp (x, y);
			}
		} else {
			cin >> s;
			if (all.count (s)) {
				use[all[s].fi][all[s].se] = 0;
				printf ("%d %d\n", all[s].fi, all[s].se);
				all.erase (s);
			} else printf ("-1 -1\n");
		}
	}
	
	return 0;
}