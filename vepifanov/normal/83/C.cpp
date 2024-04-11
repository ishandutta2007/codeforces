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
int m, k;
int si, sj, ti, tj;
int was[50][50];
string g[50], res[50][50];
ii q[2500];
int x[50][50];
int can[27];
string ANS;
int ans;

int go () {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            was[i][j] = 0;
        }
    can[26] = 1;
    int l = 0, r = 1;
    q[0] = mp (si, sj);
    was[si][sj] = 1;
    while (l < r) {
        int i = q[l].fi;
        int j = q[l].se;
        if (i == ti && j == tj) break;
        l++;
        for (int t = 0; t < 4; t++) {
            int ni = i + int (t == 0) - int (t == 1);
            int nj = j + int (t == 2) - int (t == 3);
            if (ni >= 0 && nj >= 0 && ni < n && nj < m && can[x[ni][nj]]) {
                if (!was[ni][nj]) {
                    was[ni][nj] = was[i][j] + 1;
                    q[r++] = mp (ni, nj);
                }
            }
        }
    }
    if (!was[ti][tj] || was[ti][tj] > ans) re 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            res[i][j] = "";
    was[si][sj] = 1;
    res[si][sj] = "S";
    for (int l = 0; l < r; l++) {
        int i = q[l].fi;
        int j = q[l].se;
        if (i == ti && j == tj) break;
        for (int t = 0; t < 4; t++) {
            int ni = i + int (t == 0) - int (t == 1);
            int nj = j + int (t == 2) - int (t == 3);
            if (ni >= 0 && nj >= 0 && ni < n && nj < m && can[x[ni][nj]] && was[ni][nj] == was[i][j] + 1) {
                string tmp = res[i][j] + g[ni][nj];
                if (res[ni][nj] == "" || res[ni][nj] > tmp)
                    res[ni][nj] = tmp;
            }
        }
    }
    if (was[ti][tj] < ans) { ans = was[ti][tj]; ANS = res[ti][tj]; } else
    if (was[ti][tj] == ans) ANS = min (ANS, res[ti][tj]);
    re 0;
}

int main () {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> g[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (g[i][j] == 'S') {
                x[i][j] = 26;
                si = i;
                sj = j;
            } else
            if (g[i][j] == 'T') {
                x[i][j] = 26;
                ti = i;
                tj = j;
            } else x[i][j] = g[i][j] - 'a';
    ans = 1e9;
    ANS = "";
    for (int a = 0; a < 26; a++) {
        can[a] = 1;
        if (k == 1) go (); else
        for (int b = a + 1; b < 26; b++) {
            can[b] = 1;
            if (k == 2) go (); else
            for (int c = b + 1; c < 26; c++) {
                can[c] = 1;
                if (k == 3) go (); else
                for (int d = c + 1; d < 26; d++) {
                    can[d] = 1;
                    go ();
                    can[d] = 0;
                }
                can[c] = 0;
            }
            can[b] = 0;
        }
        can[a] = 0;
    }
    if (ANS == "") printf ("-1\n"); else printf ("%s\n", ANS.substr (1, sz (ANS) - 2).c_str ());
    return 0;
}