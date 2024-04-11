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

const ll inf = 4e18;

int n;
int m;
int x[100];
int f[100];
int mask[100];
vii v;
int b;
ll res[1 << 20];

int main () {
    scanf ("%d%d%d", &n, &m, &b);
    for (int i = 0; i < n; i++) {
        int t;
        scanf ("%d%d%d", &x[i], &f[i], &t);
        for (int j = 0; j < t; j++) {
            int x;
            scanf ("%d", &x); x--;
            mask[i] |= 1 << x;
        }
        v.pb (mp (f[i], i));
    }
    sort (all (v));
    for (int i = 0; i < (1 << m); i++) res[i] = inf;
    res[0] = 0;
    ll ans = inf;
    for (int i = 0; i < n; i++) {
        int j = v[i].se;
        int cmask = (1 << m) - 1 - mask[j];
        int ccost = x[j];
        for (int k = (1 << m) - 1; k >= 0; k--)
            res[k] = min (res[k], res[k & cmask] + ccost);
        ans = min (ans, res[(1 << m) - 1] + (ll)f[j] * b);
    }
    if (ans > inf / 2) ans = -1;
    cout << ans << endl;
//  cerr << clock () << endl;
    return 0;
}