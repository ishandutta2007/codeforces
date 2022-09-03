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
#include <cassert>

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
#define j0 j1347829
#define j1 j234892
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

const int mod = 1001000027;
const int N = 100000;

int n;
int m;
ll d[2][N];
int mark[N];
int cnt[2][N];
set<pair<ll, int> > all;
vii v[2][N];
int ea[N];
int eb[N];
int ec[N];
int S, T;

int go (int t, int S) {
    for (int i = 0; i < n; i++) {
        d[t][i] = 1e18;
        mark[i] = 0;
        cnt[t][i] = 0;
    }
    all.clear ();
    d[t][S] = 0;
    mark[S] = 1;
    cnt[t][S] = 1;
    all.insert (mp (0, S));
    while (!all.empty ()) {
        int x = all.begin ()->se;
        all.erase (all.begin ());
        for (int i = 0; i < sz (v[t][x]); i++) {
            int y = v[t][x][i].fi;
            int z = v[t][x][i].se;
            if (d[t][x] + z < d[t][y]) {
                if (mark[y]) all.erase (mp (d[t][y], y));
                mark[y] = 1;
                d[t][y] = d[t][x] + z;
                cnt[t][y] = cnt[t][x];
                all.insert (mp (d[t][y], y));
            } else
            if (d[t][x] + z == d[t][y])
                cnt[t][y] = (cnt[t][y] + cnt[t][x]) % mod;
        }
    }
    re 0;
}

int main () {
/*    int x = 1001000000;
    while (true) {
        x++;
        int ok = 1;
        for (int i = 2; i * i <= x; i++)
            if (x % i == 0)
                ok = 0;
        if (ok) break;
    }
    cout << x << endl;*/
    scanf ("%d%d%d%d", &n, &m, &S, &T); S--; T--;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf ("%d%d%d", &a, &b, &c); a--; b--;
        v[0][a].pb (mp (b, c));
        v[1][b].pb (mp (a, c));
        ea[i] = a;
        eb[i] = b;
        ec[i] = c;
    }
    go (0, S);
    go (1, T);
    for (int i = 0; i < m; i++) {
        int a = ea[i];
        int b = eb[i];
        int c = ec[i];
        if (d[0][a] + c + d[1][b] == d[0][T]) {
            if (((ll)cnt[0][a] * cnt[1][b]) % mod == cnt[0][T]) {
                printf ("YES\n");
                continue;
            }
        }
        if ((d[0][T] - d[0][a] - d[1][b] - 1) > 0) {
            printf ("CAN %d\n", (int)(c - (d[0][T] - d[0][a] - d[1][b] - 1)));
            continue;
        }
        printf ("NO\n");
    }
    return 0;
}