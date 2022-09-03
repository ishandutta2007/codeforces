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
int m;
bool was[4000][4000], use[4000][4000];
int res[4000][4000];
int x[2000], y[2000];
ll l[2000], r[2000];
int next[4000], num[4000];
vector<pair<ll, int> > v;
                                    
int go (int l, int r) {
    if (l >= r) re 0;
    if (was[l][r]) re res[l][r];
    was[l][r] = 1;
    res[l][r] = go (l + 1, r);
    use[l][r] = 0;
    if (next[l] != -1 && next[l] <= r) {
        int tmp = go (l + 1, next[l] - 1) + go (next[l] + 1, r) + 1;
        if (tmp > res[l][r]) {
            res[l][r] = tmp;
            use[l][r] = 1;
        }
    }
    re res[l][r];
}

int out (int l, int r) {
    if (l >= r) re 0;
    if (!use[l][r]) out (l + 1, r); else {
        printf ("%d ", num[l] + 1);
        out (l + 1, next[l] - 1);
        out (next[l] + 1, r);
    }
    re 0;
}

int main() {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        int c, R;
        scanf ("%d%d", &c, &R);
        l[i] = (ll)(c - R) * 3000000000LL + 1000000001 - R;
        r[i] = (ll)(c + R) * 3000000000LL - (1000000001 - R);
        v.pb (mp (l[i], i));
        v.pb (mp (r[i], i));
    }
    sort (all (v));
    for (int i = 0; i < sz (v); i++) 
        if (v[i].fi == l[v[i].se])
            x[v[i].se] = i;
        else
            y[v[i].se] = i;
    for (int i = 0; i < n; i++) {
        num[x[i]] = i;
        next[x[i]] = y[i];
        next[y[i]] = -1;
    }
    printf ("%d\n", go (0, 2 * n - 1));
    out (0, 2 * n - 1);
    return 0;
}