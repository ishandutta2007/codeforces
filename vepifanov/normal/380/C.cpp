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

const int N = 1 << 20;

int n;
int m;
string s;
pair<int, ii> tree[2 * N + 10];

pair<int, ii> add (pair<int, ii> a, pair<int, ii> b) {
    int c = min (a.se.fi, b.se.se);
    re mp (a.fi + b.fi + 2 * c, mp (a.se.fi + b.se.fi - c, a.se.se + b.se.se - c));
}

pair<int, ii> init (int x, int l, int r) {
    if (l == r) {
        tree[x].fi = 0;
        tree[x].se.fi = int (s[l] == '(');
        tree[x].se.se = int (s[l] == ')');
        re tree[x];
    }
    int s = (l + r) / 2;
    re tree[x] = add (init (x * 2 + 1, l, s), init (x * 2 + 2, s + 1, r));
}

pair<int, ii> get (int x, int l, int r, int lc, int rc) {
    if (r < lc || l > rc) re mp (0, mp (0, 0));
    if (l >= lc && r <= rc) re tree[x];
    int s = (l + r) / 2;
    re add (get (x * 2 + 1, l, s, lc, rc), get (x * 2 + 2, s + 1, r, lc, rc));
}

int main () {
    cin >> s;
    m = sz (s);
    init (0, 0, m - 1);
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        printf ("%d\n", get (0, 0, m - 1, a, b).fi);
    }
    return 0;
}