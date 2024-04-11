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
char x[2500][2500];
string s[2500];
short f[2500][2500][4];

ll ans;

int go (int i1, int j1, int i2, int j2) {
    if (i1 == i2 && j1 == j2) {
        if (k == 0) ans += int (x[i1][j1] == 0);
        if (k == 1) ans += int (x[i1][j1] == 1);
        re 0;
    }
    int t;
    int **a;
    int **b;
    if (i2 - i1 > j2 - j1) {
        int is = (i1 + i2) / 2;
        go (i1, j1, is, j2);
        go (is + 1, j1, i2, j2);
        t = j2 - j1 + 1;
        a = new int*[t];
        b = new int*[t];
        for (int j = 0; j < t; j++) {
            a[j] = new int[k + 1];
            int r = 0;
            int i = f[is][j + j1][1];
            while (r < k + 1 && i >= i1) {
                a[j][r++] = is - i;
                if (i == 0) break;
                i = f[i - 1][j + j1][1];
            }
            while (r < k + 1) a[j][r++] = is - i1 + 1;
        }
        for (int j = 0; j < t; j++) {
            b[j] = new int[k + 1];
            int r = 0;
            int i = f[is + 1][j + j1][3];
            while (r < k + 1 && i <= i2) {
                b[j][r++] = i - is - 1;
                if (i + 1 == n) break;
                i = f[i + 1][j + j1][3];
            }
            while (r < k + 1) b[j][r++] = i2 - is;
        }
    } else {
        int js = (j1 + j2) / 2;
        go (i1, j1, i2, js);
        go (i1, js + 1, i2, j2);
        t = i2 - i1 + 1;
        a = new int*[t];
        b = new int*[t];
        for (int i = 0; i < t; i++) {
            a[i] = new int[k + 1];
            int r = 0;
            int j = f[i + i1][js][0];
            while (r < k + 1 && j >= j1) {
                a[i][r++] = js - j;
                if (j == 0) break;
                j = f[i + i1][j - 1][0];
            }
            while (r < k + 1) a[i][r++] = js - j1 + 1;
        }
        for (int i = 0; i < t; i++) {
            b[i] = new int[k + 1];
            int r = 0;
            int j = f[i + i1][js + 1][2];
            while (r < k + 1 && j <= j2) {
                b[i][r++] = j - js - 1;
                if (j + 1 == m) break;
                j = f[i + i1][j + 1][2];
            }
            while (r < k + 1) b[i][r++] = j2 - js;
        }
    }   
    int *c = new int[k + 1];
    int *d = new int[k + 1];
    int *e = new int[k + 1];
    for (int ja = 0; ja < t; ja++) {
        for (int jb = ja; jb < t; jb++) {
            if (jb == ja) {
                for (int i = 0; i <= k; i++) {
                    c[i] = a[ja][i];
                    d[i] = b[ja][i];
                }
            } else {
                {
                    int r = 0, s = 0, o = 0;
                    while (r < k + 1)
                        if (c[s] <= a[jb][o])
                            e[r++] = c[s++];
                        else
                            e[r++] = a[jb][o++];
                    for (int i = 0; i <= k; i++)
                        c[i] = e[i];
                }
                {
                    int r = 0, s = 0, o = 0;
                    while (r < k + 1)
                        if (d[s] <= b[jb][o])
                            e[r++] = d[s++];
                        else
                            e[r++] = b[jb][o++];
                    for (int i = 0; i <= k; i++)
                        d[i] = e[i];
                }
            }
            for (int r = 0; r <= k; r++) {
                int c1, c2;
                if (r == 0) c1 = c[0]; else c1 = c[r] - c[r - 1];
                if (r == k) c2 = d[0]; else c2 = d[k - r] - d[k - r - 1];
                ans += c1 * c2;
            }
        }
    }
    delete [] c;
    delete [] d;
    delete [] e;
    for (int i = 0; i < t; i++) {
        delete [] a[i];
        delete [] b[i];
    }
    delete [] a;
    delete [] b;
    re 0;
}

int main () {
    scanf ("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            x[i][j] = s[i][j] - '0';
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            f[i][j][0] = f[i][j][1] = -1;
            if (x[i][j]) {
                f[i][j][0] = j;
                f[i][j][1] = i;
            } else {
                if (j > 0) f[i][j][0] = f[i][j - 1][0];
                if (i > 0) f[i][j][1] = f[i - 1][j][1];
            }
        }
    for (int i = n - 1; i >= 0; i--)
        for (int j = m - 1; j >= 0; j--) {
            f[i][j][2] = m;
            f[i][j][3] = n;
            if (x[i][j]) {
                f[i][j][2] = j;
                f[i][j][3] = i;
            } else {
                if (j + 1 < m) f[i][j][2] = f[i][j + 1][2];
                if (i + 1 < n) f[i][j][3] = f[i + 1][j][3];
            }
        }
    ans = 0;
    go (0, 0, n - 1, m - 1);
    cout << ans << endl;
    cerr << clock () << endl;
    return 0;
}