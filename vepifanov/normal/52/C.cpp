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
int m, N;
ll tree[1000000], add[1000000];
char w[100];

ll put (int x, int l, int r, int lc, int rc, int k) {
	if (r < lc || l > rc) re tree[x] + add[x];
	if (l >= lc && r <= rc) {
		add[x] += k;
		re tree[x] + add[x];
	}
	int s = (l + r) / 2;
	tree[x] = min (put (x * 2, l, s, lc, rc, k), put (x * 2 + 1, s + 1, r, lc, rc, k));
	re tree[x] + add[x];
}

ll get (int x, int l, int r, int lc, int rc) {
	if (r < lc || l > rc) re 1e15;
	if (l >= lc && r <= rc) re tree[x] + add[x];
	int s = (l + r) / 2;
	re min (get (x * 2, l, s, lc, rc), get (x * 2 + 1, s + 1, r, lc, rc)) + add[x]; 
}                    

ll get2 (int a, int b) {
	if (a <= b) re get (1, 0, N, a, b);
	re min (get (1, 0, N, 0, b), get (1, 0, N, a, n - 1));
}

ll put2 (int a, int b, int c) {
	if (a <= b) re put (1, 0, N, a, b, c);
	re min (put (1, 0, N, 0, b, c), put (1, 0, N, a, n - 1, c));
}

int main() {
	scanf ("%d", &n);
	memset (tree, 0, sizeof (tree));
	memset (add, 0, sizeof (add));
	N = n;
	while (N & (N - 1)) N++;
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x);
		put (1, 0, N, i, i, x);
	}
	scanf ("%d", &m);
	gets (w);
	for (int i = 0; i < m; i++) {
		gets (w);
		stringstream in (w);
		int a, b, c;
		in >> a >> b;
		if (in >> c) {
			put2 (a, b, c);
		} else {
			printf ("%I64d\n", get2 (a, b));
		}
	}
	return 0;
}