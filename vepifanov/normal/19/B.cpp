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
long long res[2001][2001];
int t[2000], c[2000];

int main() {
	int n;
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%d%d", &t[i], &c[i]);
		t[i]++;
	}
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			res[i][j] = -1;
	res[0][0] = 0;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++) {
			if (res[i][j] == -1) continue;
			if (res[i + 1][j] == -1 || res[i + 1][j] > res[i][j]) res[i + 1][j] = res[i][j];
			if (i == n) continue;
			int k = min (n, j + t[i]);
			if (res[i + 1][k] == -1 || res[i + 1][k] > res[i][j] + c[i]) res[i + 1][k] = res[i][j] + c[i];
		}
	printf ("%I64d\n", res[n][n]);
	return 0;
}