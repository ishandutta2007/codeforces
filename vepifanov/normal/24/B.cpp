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

const int pts[10] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};

int n;
int m, r;
int sum[1000], a[1000], b[1000];
string name[1000];
int g[1000][50];
map<string, int> all;

bool myless1 (int i, int j) {
	if (sum[i] != sum[j]) return sum[i] > sum[j];
	for (int k = 0; k < 50; k++)
		if (g[i][k] != g[j][k])
			return g[i][k] > g[j][k];
	return false;
}

bool myless2 (int i, int j) {
	if (g[i][0] != g[j][0]) return g[i][0] > g[j][0];
	if (sum[i] != sum[j]) return sum[i] > sum[j];
	for (int k = 1; k < 50; k++)
		if (g[i][k] != g[j][k])
			return g[i][k] > g[j][k];
	return false;
}

int get (string s) {
	if (all.count (s)) return all[s];
	a[r] = r;
	b[r] = r;
	all[s] = r;
	name[r] = s;
	r++;
	return r - 1;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		for (int j = 0; j < m; j++) {
			string s;
			cin >> s;
			int x = get (s);
			if (j < 10) sum[x] += pts[j];
			g[x][j]++;
		}
	}
	sort (a, a + r, myless1);
	sort (b, b + r, myless2);
	cout << name[a[0]] << endl;
	cout << name[b[0]] << endl;
	return 0;
}