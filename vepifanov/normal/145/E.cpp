#include <cstdio>
#include <numeric>
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
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

struct node{
	int a, b, ab, ba;
	node() {}
	node(int A, int B, int AB, int BA) {
		a = A;
		b = B;
		ab = AB;
		ba = BA;
	}
};

int n;
int m;

node tree[2500000];
int rev[2500000];

node un (node x, node y) {
	node z;
	z.a = x.a + y.a;
	z.b = x.b + y.b;
	z.ab = max (x.ab + y.b, x.a + y.ab);
	z.ba = max (x.ba + y.a, x.b + y.ba);
	re z;
}

void upd (int x, int l, int r) {
	swap (tree[x].a, tree[x].b);
	swap (tree[x].ab, tree[x].ba);
	rev[x] = 0;
	if (l != r) rev[x * 2 + 1] ^= 1, rev[x * 2 + 2] ^= 1;
}

char s[1000001];
char w[10];

node init (int x, int l, int r) {
	if (l == r) {
		if (l < n) tree[x] = node (int (s[l] == '4'), int (s[l] == '7'), 1, 1); else tree[x] = node (0, 0, 0, 0);
		re tree[x];
	}	
	int s = (l + r) / 2;
	re tree[x] = un (init (x * 2 + 1, l, s), init (x * 2 + 2, s + 1, r));
}

node add (int x, int l, int r, int lc, int rc) {
	if (rev[x]) upd (x, l, r);
	if (r < lc || l > rc) re tree[x];
	if (l >= lc && r <= rc) {
		upd (x, l, r);
		re tree[x];
	}
	int s = (l + r) / 2;
	re tree[x] = un (add (x * 2 + 1, l, s, lc, rc), add (x * 2 + 2, s + 1, r, lc, rc));
}

int main () {
	scanf ("%d%d\n", &n, &m);
	scanf ("%s\n", s);
	init (0, 0, n);
	for (int i = 0; i < m; i++) {
		scanf ("%s", w);
		if (w[0] == 'c') {
			printf ("%d\n", tree[0].ab);
		} else {
			int l, r;
			scanf ("%d%d", &l, &r); l--; r--;
			add (0, 0, n, l, r);
		}
		scanf ("\n");
	}
	return 0;
}