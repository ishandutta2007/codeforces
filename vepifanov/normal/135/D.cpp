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
int ct;
char w[1001][1001];
int was[1001][1001], was2[1001][1001], use[1001][1001];
vii q;
int bad;

int go2 (int i, int j) {
    if (i < 0 || j < 0 || i >= n || j >= m) re 0;
    if (was2[i][j] == ct || use[i][j] != ct) re 0;
    if (w[i][j] == '0') re 0;
    was2[i][j] = ct;
    int tmp = 1;
    for (int t = 0; t < 4; t++) {
        int ni = i + int (t == 0) - int (t == 1);
        int nj = j + int (t == 2) - int (t == 3);
        tmp += go2 (ni, nj);
    }
    re tmp;
}

int go (int i, int j) {
    if (i < 0 || j < 0 || i >= n || j >= m) {
        bad = 1;
        re 0;
    }   
    if (was[i][j]) re 0;
    if (w[i][j] == '1') {
        if (use[i][j] != ct) {
            use[i][j] = ct;
            q.pb (mp (i, j));
        }
        re 0;
    }
    was[i][j] = 1;
    for (int t = 0; t < 8; t++) {
        int ni = i + int (t == 3 || t == 4 || t == 5) - int (t == 0 || t == 1 || t == 7);
        int nj = j + int (t == 1 || t == 2 || t == 3) - int (t == 5 || t == 6 || t == 7);
        go (ni, nj);
    }
    re 0;
}

int main () {
    scanf ("%d%d", &n, &m);
    gets (w[0]);
    for (int i = 0; i < n; i++) gets (w[i]);
    int ans = 0;
    for (int i = 0; i + 1 < n; i++)
        for (int j = 0; j + 1 < m; j++)
            if (w[i][j] == '1' && w[i + 1][j] == '1' && w[i][j + 1] == '1' && w[i + 1][j + 1] == '1')
                ans = 4;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (w[i][j] == '0' && !was[i][j]) {
                bad = 0;
                ct++;
                q.clear ();
                go (i, j);
                if (!bad && sz (q) > ans && go2 (q[0].fi, q[0].se) == sz (q)) {
                    int ok = 1;
                    for (int k = 0; k < sz (q); k++) {
                        int tmp = 0;
                        for (int t = 0; t < 4; t++) {
                            int ni = q[k].fi + int (t == 0) - int (t == 1);
                            int nj = q[k].se + int (t == 2) - int (t == 3);
                            if (ni >= 0 && nj >= 0 && ni < n && nj < m && use[ni][nj] == ct) tmp++;
                        }
                        if (tmp != 2) { ok = 0; break; }
                    }
                    if (ok) ans = max (ans, sz (q));
                }
            }
    printf ("%d\n", ans);
    return 0;
}