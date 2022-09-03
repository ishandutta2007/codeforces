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

int LEN = 300;

int n;
int m;
int a[100000], c[100000];
int w[1000], l[1000], q[1000][1000];
int x[100000], y[100000];

int main() {
	scanf ("%d", &n);	
	for (int i = 0; i < n; i++) scanf ("%d%d", &a[i], &c[i]);
	int r = 1;
	l[0] = 1;
	w[0] = a[0];
	q[0][0] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = r - 1; j >= 0; j--)
			if (j == 0 || l[j] >= c[i] || w[j] >= a[i]) {
				int k = l[j];
				while (k > 0 && c[i] && a[q[j][k - 1]] < a[i]) {
					q[j][k] = q[j][k - 1];
					k--;
					c[i]--;
				}
				q[j][k] = i;
				l[j]++;
				w[j] = max (w[j], a[i]);
				break;
			} else c[i] -= l[j];
		if (i % LEN == 0) {
			int m = 0;
			for (int j = 0; j < r; j++) 
				for (int k = 0; k < l[j]; k++)
					x[m++] = q[j][k];
			r = (m + LEN - 1) / LEN;
			for (int j = 0; j < r; j++) {
				l[j] = min (LEN, m);
				w[j] = 0;
				for (int k = 0; k < l[j]; k++) {
					int t = j * LEN + k;
					w[j] = max (w[j], a[x[t]]);
					q[j][k] = x[t];
				}
				m -= l[j];
			}
		}
	}
	int m = 0;
	for (int j = 0; j < r; j++) 
		for (int k = 0; k < l[j]; k++)
			x[m++] = q[j][k];
	for (int i = 0; i < m; i++) printf ("%d ", x[i] + 1);
	printf ("\n");
	return 0;
}