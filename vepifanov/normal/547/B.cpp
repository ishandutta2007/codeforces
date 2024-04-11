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
#define prev PREV
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

int n;
int m;
int res[200000];
ii tree[1 << 20];
int a[200000];

ii build (int x, int l, int r) {
    if (l == r) re tree[x] = mp (a[l], l);
    int s = (l + r) / 2;
    re tree[x] = min (build (x * 2 + 1, l, s), build (x * 2 + 2, s + 1, r));
}

ii get (int x, int l, int r, int lc, int rc) {
    if (r < lc || l > rc) re mp (1e9, 0);
    if (l >= lc && r <= rc) re tree[x];
    int s = (l + r) / 2;
    re min (get (x * 2 + 1, l, s, lc, rc), get (x * 2 + 2, s + 1, r, lc, rc));
}

int go (int l, int r) {
    if (l > r) re 0;
    ii p = get (0, 0, n - 1, l, r);
    res[r - l] = max (res[r - l], p.fi);
    go (l, p.se - 1);
    go (p.se + 1, r);
    re 0;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%d", &a[i]);
    build (0, 0, n - 1);
    go (0, n - 1);
    for (int i = n - 1; i > 0; i--) res[i - 1] = max (res[i - 1], res[i]);
    for (int i = 0; i < n; i++) printf ("%d ", res[i]);
    printf ("\n");
    return 0;
}