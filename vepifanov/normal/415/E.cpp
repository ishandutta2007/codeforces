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
int m;
int x[1 << 20];
int y[1 << 20];
ll res[20];
ll all[20];
int q;

int build (int i, int l, int r) {
    if (l == r) re 0;
    int s = (l + r) / 2;
    build (i + 1, l, s);
    build (i + 1, s + 1, r);
    int a = l, b = s + 1, c = l;
    while (a <= s || b <= r) {
        int A = a, B = b;
        int cur;
        if (a <= s && (b > r || x[a] <= x[b])) cur = x[a]; else cur = x[b];
        while (A <= s && x[A] == cur) A++;
        while (B <= r && x[B] == cur) B++;
        res[i] += (ll)(s - A + 1) * (B - b);
        all[i] += (ll)(s - A + 1) * (B - b);
        all[i] += (ll)(A - a) * (r - B + 1);
        while (a < A) { y[c++] = cur; a++; }
        while (b < B) { y[c++] = cur; b++; }
    }
    for (int i = l; i <= r; i++)
        x[i] = y[i];
    re 0;
}

int main () {
    scanf ("%d", &n);
    m = 1 << n;
    for (int i = 0; i < m; i++) scanf ("%d", &x[i]);
    build (0, 0, m - 1);
    scanf ("%d", &q);
    for (int i = 0; i < q; i++) {
        int x;
        scanf ("%d", &x);
        for (int j = n - x; j < n; j++)
            res[j] = all[j] - res[j];
        ll ans = 0;
        for (int j = 0; j < n; j++) ans += res[j];
        printf ("%I64d\n", ans);
    }
    return 0;
}