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
int k;
string s, t, v;
int p[101];
int res[102][102][102];
int use[102][102][102];
int g[102][102];

int out (int i, int j, int k) {
    if (res[i][j][k] == 0) re 0;
    if (use[i][j][k] == -1) re out (i + 1, j, k);
    if (use[i][j][k] == -2) re out (i, j + 1, k);
    printf ("%c", s[i]);
    out (i + 1, j + 1, use[i][j][k]);
    re 0;
}

int main () {
    cin >> s >> t >> v;
    int ss = sz (s);
    int st = sz (t);
    int sv = sz (v);
    p[0] = -1;
    for (int i = 1; i < sv; i++) {
        int k = p[i - 1];
        while (k >= 0 && v[k + 1] != v[i]) k = p[k];
        if (v[k + 1] == v[i]) k++;
        p[i] = k;
    }
    for (int i = -1; i + 1 < sv; i++)
        for (int c = 0; c < 26; c++) {
            int k = i;
            while (k >= 0 && v[k + 1] - 'A' != c) k = p[k];
            if (v[k + 1] - 'A' == c) k++;
            g[i + 1][c] = k + 1;
        }
    memset (res, 0, sizeof (res));
    for (int i = ss - 1; i >= 0; i--)
        for (int j = st - 1; j >= 0; j--)
            for (int k = 0; k < sv; k++) {
                if (res[i + 1][j][k] > res[i][j][k]) {
                    res[i][j][k] = res[i + 1][j][k];
                    use[i][j][k] = -1;
                }
                if (res[i][j + 1][k] > res[i][j][k]) {
                    res[i][j][k] = res[i][j + 1][k];
                    use[i][j][k] = -2;
                }
                int nk = g[k][s[i] - 'A'];
                if (s[i] == t[j] && nk != sv && res[i + 1][j + 1][nk] + 1 > res[i][j][k]) {
                    res[i][j][k] = res[i + 1][j + 1][nk] + 1;
                    use[i][j][k] = nk;
                }
            }
    int ans = 0, ai = 0, aj = 0;
    for (int i = 0; i < ss; i++)
        for (int j = 0; j < st; j++)
            if (res[i][j][0] > ans) {
                ans = res[i][j][0];
                ai = i;
                aj = j;
            }
    if (ans == 0) printf ("0\n"); else out (ai, aj, 0);
    return 0;
}