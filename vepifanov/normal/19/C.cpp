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
int x[100001], p[100001], next[100001];
long long y[100001], pw[100001];
ii all[2000000];

bool myless (int i, int j) {
	return x[i] < x[j] || x[i] == x[j] && i < j;
}

int main() {
	int n;
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &x[i]);
		p[i] = i;
	}
	y[n] = 0;
	long long base = 1;
	for (int i = n - 1; i >= 0; i--) {
		base *= 999983;
		pw[n - i] = base;
		y[i] = y[i + 1] + x[i] * base;
	}
	sort (p, p + n, myless);
	for (int i = 0; i < n; i++)
		if (i + 1 < n && x[p[i + 1]] == x[p[i]])
			next[p[i]] = p[i + 1];
		else
			next[p[i]] = -1;
	int o = 0;
	for (int i = 0; i < n; i++) {
		int j = next[i];
		while (j != -1) {
			int l = j - i;
			if (i - l + 1 >= 0 && (y[i - l + 1] - y[i + 1]) == (y[i + 1] - y[j + 1]) * pw[l]) {
				all[o] = mp (l, i + 1);
				o++;
			}
			j = next[j];
		}
	}
	sort (all, all + o);
	int k = 0;
	for (int i = 0; i < o; i++)
		if (all[i].second - all[i].first >= k)
			k = all[i].second;
	printf ("%d\n", n - k);
	for (int i = k; i < n; i++) printf ("%d ", x[i]);
	return 0;
}