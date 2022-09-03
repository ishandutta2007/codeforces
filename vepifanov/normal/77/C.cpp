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
int m, s;
vector<pair<ll, int> > v[200000];
int k[200000];

ll go (int x, int p) {
    k[x]--;
    for (int i = 0; i < sz (v[x]); i++) {
        int y = v[x][i].se;
        if (k[y] > 0 && y != p) v[x][i].fi = go (y, x); else v[x][i].fi = -1;
    }
    sort (all (v[x]));
    reverse (all (v[x]));
    ll cur = 0;
    for (int i = 0; i < sz (v[x]) && k[x] > 0; i++) {
        if (v[x][i].fi < 0) continue;
        cur += v[x][i].fi + 2;
        k[x]--;
    }   
    for (int i = 0; i < sz (v[x]); i++) {
        int y = v[x][i].se;
        if (y == p) continue;
        int tmp = min (k[x], k[y]);
        k[x] -= tmp;
        k[y] -= tmp;
        cur += 2 * tmp;
    }
    re cur;
}

int main() {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%d", &k[i]);
    for (int i = 0; i + 1 < n; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        v[a].pb (mp (0, b));
        v[b].pb (mp (0, a));
    }
    scanf ("%d", &s); s--;
    k[s]++;
    cout << go (s, s) << endl;
    return 0;
}