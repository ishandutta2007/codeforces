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

const int LEN = 300;

int n;
int m;
pair<pair<ii, ii>, int> v[200000];

int cnt[1000001];
int l, r;
ll sum;
int x[200000];
ll res[200000];

int go (int p, int q) {
    while (r < q) {
        r++;
        sum += (ll)(cnt[x[r]] * 2 + 1) * x[r];
        cnt[x[r]]++;
    }
    while (l > p) {
        l--;
        sum += (ll)(cnt[x[l]] * 2 + 1) * x[l];
        cnt[x[l]]++;
    }
    while (r > q) {
        cnt[x[r]]--;
        sum -= (ll)(cnt[x[r]] * 2 + 1) * x[r];
        r--;
    }
    while (l < p) {
        cnt[x[l]]--;
        sum -= (ll)(cnt[x[l]] * 2 + 1) * x[l];
        l++;
    }
    re 0;
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    for (int i = 0; i < m; i++) {
        scanf ("%d%d", &v[i].fi.se.fi, &v[i].fi.se.se); v[i].fi.se.fi--; v[i].fi.se.se--;
        v[i].fi.fi.fi = v[i].fi.se.fi / LEN;
        v[i].fi.fi.se = v[i].fi.se.se;
        v[i].se = i;
    }
    sort (v, v + m);
    l = r = 0;
    sum = x[0];
    cnt[x[0]]++;
    for (int i = 0; i < m; i++) {
        go (v[i].fi.se.fi, v[i].fi.se.se);
        res[v[i].se] = sum;
    }
    for (int i = 0; i < m; i++) printf ("%I64d\n", res[i]);
    return 0;
}