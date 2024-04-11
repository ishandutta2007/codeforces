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
#define prev PREV
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

const int mod = 1000*1000*1000+7;

int n;
int m;
vi v[100000];
int p[100000];
int was[100000];
int col[100000];
int ea[100000];
int eb[100000];
int ec[100000];
vi w;

int gp (int x) {
    if (p[x] != x) p[x] = gp (p[x]);
    re p[x];
}

int go (int x, int c) {
    if (was[x]) re int (col[x] != c);
    col[x] = c;
    was[x] = 1;
    for (int i = 0; i < sz (v[x]); i++)
        if (go (v[x][i], 1 - c))
            re 1;
    re 0;
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) p[i] = i;
    for (int i = 0; i < m; i++) {
        scanf ("%d%d%d", &ea[i], &eb[i], &ec[i]); ea[i]--; eb[i]--;
        if (ec[i]) {
            int a = gp (ea[i]);
            int b = gp (eb[i]);
            p[a] = b;
        }
    }
    for (int i = 0; i < m; i++)
        if (!ec[i]) {
            int a = gp (ea[i]);
            int b = gp (eb[i]);
            v[a].pb (b);
            v[b].pb (a);
        }
    for (int i = 0; i < n; i++) w.pb (gp (i));
    int ans = 1;
    for (int i = 0; i < n; i++)
        if (!was[gp (i)]) {
            if (go (gp (i), 0)) {
                ans = 0;
                break;
            }
            if (i != 0) ans = (ans * 2) % mod;
        }
    cout << ans << endl;
    return 0;
}