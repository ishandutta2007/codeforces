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
int p[50000];
vi v[50000];

int go (int x, int l) {
	p[x] = l;
	for (int i = 0; i < sz (v[x]); i++)
		if (l != v[x][i])
			go (v[x][i], x);
	re 0;
}

int main() {
	int x, y;
	scanf ("%d%d%d", &n, &x, &y); x--; y--;
	for (int i = 0; i < n; i++)
		if (i != x) {
			int z;
			scanf ("%d", &z); z--;
			v[i].pb (z);
			v[z].pb (i);
		}
	go (y, -1);
	for (int i = 0; i < n; i++)
		if (i != y) printf ("%d ", p[i] + 1);
	return 0;
}