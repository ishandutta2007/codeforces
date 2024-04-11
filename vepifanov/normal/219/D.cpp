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
int cnt[200000];
vii v[200000];
int res[200000];
int ans;

int go (int x, int p) {
    cnt[x] = 0;
    for (int i = 0; i < sz (v[x]); i++)
        if (v[x][i].fi != p)
            cnt[x] += go (v[x][i].fi, x) + v[x][i].se;
    re cnt[x];
}

int calc (int x, int p, int s) {
    res[x] = s;
    if (s < ans) ans = s;
    for (int i = 0; i < sz (v[x]); i++)
        if (v[x][i].fi != p)
            calc (v[x][i].fi, x, s + 1 - 2 * v[x][i].se);
    re 0;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i + 1 < n; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        v[a].pb (mp (b, 0));
        v[b].pb (mp (a, 1));
    }
    ans = n + 1;
    go (0, 0);
    calc (0, 0, cnt[0]);
    printf ("%d\n", ans);
    for (int i = 0; i < n; i++)
        if (res[i] == ans)
            printf ("%d ", i + 1);
    printf ("\n");
    return 0;
}