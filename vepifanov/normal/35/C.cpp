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
int x[10], y[10];

int main() {
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	scanf ("%d%d%d", &n, &m, &k);
	for (int i = 0; i < k; i++) scanf ("%d%d", &x[i], &y[i]);
	int ans = -1, ax = 0, ay = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			int cur = n + m;
			for (int l = 0; l < k; l++) cur = min (cur, abs (x[l] - i) + abs (y[l] - j));
			if (ans < cur) {
				ans = cur;
				ax = i;
				ay = j;
			}
		}
	printf ("%d %d\n", ax, ay);	
	return 0;
}