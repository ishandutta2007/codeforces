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
int g[20][20];
long long res[1 << 19][19];
int A[19], B[19], C[19];

int main() {
	int n, m;
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf ("%d%d", &a, &b); a--; b--;
		g[a][b] = g[b][a] = 1;
	}
	long long ans = 0;
	int j, q;
	for (int s = n - 1; s >= 0; s--) {
		int nn = 1 << s;
		int NN = 2 * nn;
		res[nn][s] = 1;
		for (int i = nn + 1; i < NN; i++) {
			int a = 0;
			for (int j = 0; j <= s; j++)
				if ((i >> j) & 1) {
					C[a] = i ^ (1 << j);
					A[a++] = j;
				}
			A[a] = -1;
			for (int* J = A, *k = C; *J != -1; J++, k++) {
				j = *J;
				res[i][j] = 0;
				for (int* K = A; *K != -1; K++) {
					q = *K;
					if (g[j][q] && res[*k][q]) res[i][j] += res[*k][q];
				}
				if (g[j][s] && res[i][j]) ans += res[i][j];
			}
		}
	}
	cout << (ans - m) / 2 << endl;
	return 0;
}