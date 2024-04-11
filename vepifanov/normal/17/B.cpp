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
int q[1000], res[1000];

int main() {
	int n, r = 0;
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &q[i]);
		if (q[i] > q[r]) r = i;
		res[i] = -1;
	}
	scanf ("%d", &m);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf ("%d%d%d", &a, &b, &c); a--; b--;
		if (res[b] == -1 || res[b] > c) res[b] = c;
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (r != i) {
			if (res[i] == -1) {
				printf ("-1\n");
				return 0;
			}
			ans += res[i];
		}
	printf ("%d\n", ans);
	return 0;
}