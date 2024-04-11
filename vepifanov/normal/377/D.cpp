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

const int N = 1 << 19;

int n;
int m;
ii tree[2 * N + 10];
int add[2 * N + 10];
vector<pair<int, ii> > v[300001];
int A[100000];
int B[100000];
int C[100000];

int push (int x, int l, int r) {
    if (add[x] != 0) {
        tree[x].fi += add[x];
        if (l != r) {
            add[x * 2 + 1] += add[x];
            add[x * 2 + 2] += add[x];
        }
        add[x] = 0;
    }
    re 0;
}

ii upd (int x, int l, int r, int lc, int rc, int y) {
    push (x, l, r);
    if (r < lc || l > rc) re tree[x];
    if (l >= lc && r <= rc) {
        add[x] += y;
        push (x, l, r);
        re tree[x];
    }
    int s = (l + r) / 2;
    re tree[x] = max (upd (x * 2 + 1, l, s, lc, rc, y), upd (x * 2 + 2, s + 1, r, lc, rc, y));
}

int init (int x, int l, int r) {
    tree[x] = mp (0, l);
    if (l != r) {
        int s = (l + r) / 2;
        init (x * 2 + 1, l, s);
        init (x * 2 + 2, s + 1, r);
    }
    re 0;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        int a, b, c;
        scanf ("%d%d%d", &a, &b, &c);
        A[i] = a;
        B[i] = b;
        C[i] = c;
        v[a].pb (mp (1, mp (b, c)));
        v[b + 1].pb (mp (-1, mp (b, c)));
    }
    memset (tree, 0, sizeof (tree));
    memset (add, 0, sizeof (add));
    init (0, 0, N - 1);
    pair<int, ii> ans = mp (0, mp (0, 0));
    for (int i = 1; i <= 300000; i++) {
        for (int j = 0; j < sz (v[i]); j++)
            upd (0, 0, N - 1, v[i][j].se.fi, v[i][j].se.se, v[i][j].fi);
        ii tmp = tree[0];
        ans = max (ans, mp (tmp.fi, mp (i, tmp.se)));
    }
    printf ("%d\n", ans.fi);
    for (int i = 0; i < n; i++)
        if (A[i] <= ans.se.fi && B[i] >= ans.se.fi && B[i] <= ans.se.se && C[i] >= ans.se.se)
            printf ("%d ", i + 1);
    printf ("\n");
    return 0;
}