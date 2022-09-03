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

int n;
ll m;

int f[2][100001];
int x[100000];
vii v;

int get (int t, int x) {
    x++;
    int y = 0;
    while (x > 0) {
        y += f[t][x];
        x = (x & (x + 1)) - 1;
    }
    re y;
}

int get (int t, int l, int r) {
    re get (t, r) - get (t, l - 1);
}

int add (int t, int x, int y) { 
    x++;
    while (x <= n) {
        f[t][x] += y;
        x |= x + 1;
    }
    re 0;
}

int main () {
    scanf ("%d%I64d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &x[i]);
        v.pb (mp (x[i], i));
    }
    sort (all (v));
    for (int i = 0; i < n; i++) x[v[i].se] = i;
    ll cur = 0, ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        cur += get (1, 0, x[i] - 1);
        add (1, x[i], 1);
    }
    int pos = 0;
    for (int i = 0; i + 1 < n; i++) {
        cur += get (0, x[i] + 1, n - 1);
        cur += get (1, 0, x[i] - 1);
        add (0, x[i], 1);
        while (pos < n && (pos <= i || cur > m)) {
            cur -= get (0, x[pos] + 1, n - 1);
            cur -= get (1, 0, x[pos] - 1);
            add (1, x[pos], -1);
            pos++;
        }
        if (pos < n) ans += n - pos;
    }
    cout << ans << endl;
    return 0;
}