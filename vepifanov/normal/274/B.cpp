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
vi w[100000];
ll v[100000];

pair<ll, ll> go (int x, int p) {
    pair<ll, ll> res = mp (0, 0);
    for (int i = 0; i < sz (w[x]); i++)
        if (w[x][i] != p) {
            pair<ll, ll> tmp = go (w[x][i], x);
            res.fi = max (res.fi, tmp.fi);
            res.se = max (res.se, tmp.se);
        }
    if (v[x] + res.fi - res.se < 0) res.fi -= v[x] + res.fi - res.se; else res.se += v[x] + res.fi - res.se;
    re res;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i + 1 < n; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        w[a].pb (b);
        w[b].pb (a);
    }
    for (int i = 0; i < n; i++) scanf ("%I64d", &v[i]);
    pair<ll, ll> res = go (0, -1);
    cout << res.fi + res.se << endl;
    return 0;
}