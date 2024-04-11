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
pair<ii, ii> v[3000];
vi w;
int p[1001];

int gp (int x) {
    if (p[x] == x) re p[x];
    re p[x] = gp (p[x]);
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf ("%d%d%d%d", &v[i].se.fi, &v[i].se.se, &v[i].fi.se, &v[i].fi.fi);
        w.pb (v[i].fi.se);
    }
    sort (v, v + m);
    int ans = 0;
    for (int i = 0; i < sz (w); i++) {
        int cur = 1e9;
        for (int j = 1; j <= n; j++) p[j] = j;
        for (int j = m - 1; j >= 0; j--) {
            if (v[j].fi.se > w[i]) continue;
            cur = min (cur, v[j].fi.fi - w[i] + 1);
            if (cur < 0) break;
            int a = gp (v[j].se.fi);
            int b = gp (v[j].se.se);
            if (a != b) {
                if (rand () & 1)
                    p[a] = b;
                else
                    p[b] = a;   
                if (gp (1) == gp (n)) {
                    ans = max (ans, cur);
                    break;
                }
            }
        }
    }
    if (ans == 0) printf ("Nice work, Dima!\n"); else printf ("%d\n", ans);
    return 0;
}