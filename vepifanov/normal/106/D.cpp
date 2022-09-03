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

const int di[4] = {-1, 0, 1, 0};
const int dj[4] = {0, -1, 0, 1};

int n;
int m, k;

char w[1001][1001];
int g[1001][1001][4];
char t[100000];
int l[100000];

int get (char x) {
    if (x == 'N') re 0;
    if (x == 'W') re 1;
    if (x == 'S') re 2;
    re 3;
}

int main () {
    scanf ("%d%d\n", &n, &m);   
    for (int i = 0; i < n; i++) scanf ("%s\n", w[i]);
    scanf ("%d\n", &k);
    for (int i = 0; i < k; i++) scanf ("%c %d\n", &t[i], &l[i]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (w[i][j] == '#') continue;
            g[i][j][0] = g[i][j][1] = 1;
            if (i > 0) g[i][j][0] += g[i - 1][j][0];
            if (j > 0) g[i][j][1] += g[i][j - 1][1];
        }
    for (int i = n - 1; i >= 0; i--)
        for (int j = m - 1; j >= 0; j--) {
            if (w[i][j] == '#') continue;
            g[i][j][2] = g[i][j][3] = 1;
            if (i + 1 < n) g[i][j][2] += g[i + 1][j][2];
            if (j + 1 < m) g[i][j][3] += g[i][j + 1][3];
        }
    string res = "";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (w[i][j] >= 'A' && w[i][j] <= 'Z') {
                int ci = i, cj = j, ok = 1;
                for (int p = 0; p < k; p++) {
                    int t = get (::t[p]);
                    if (g[ci][cj][t] >= l[p] + 1) {
                        ci += di[t] * l[p];
                        cj += dj[t] * l[p];
                    } else { ok = 0; break; }
                }
                if (ok) res += w[i][j];
            }
    sort (all (res));
    if (res == "") res = "no solution";
    printf ("%s\n", res.c_str ());
    return 0;
}