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
int m, p;

int f1[2][20001];
int f2[2][20001];
int F1[20001];
int x[20001];
int y[20001];

int f (int i, int j) {
    re (x[i] + y[j]) % p;
}

int go (int i1, int j1, int i2, int j2, int isans) {
    int k = (j2 - j1) + (i2 - i1), ii, jj;
    char h = 0;
    int ans = -1;
    if (k == 1) {
        ans = f (i1, j1) + f (i2, j2);
        if (i1 == i2) h = 'S'; else h = 'C';
    } else {
        int k1 = k / 2, k2 = (k + 1) / 2;
        for (int i = i1; i <= i2 && (i - i1) <= k1; i++) {
            int ci = i & 1;
            int pi = 1 - ci;
            for (int j = j1; j <= j2 && (i - i1) + (j - j1) <= k1; j++) {
                if (i == i1 && j == j1)
                    f1[ci][j] = f (i, j);
                else {
                    f1[ci][j] = 0;
                    if (i - 1 >= i1) f1[ci][j] = max (f1[ci][j], f1[pi][j]);
                    if (j - 1 >= j1) f1[ci][j] = max (f1[ci][j], f1[ci][j - 1]);
                    f1[ci][j] += f (i, j);
                }
                if ((i - i1) + (j - j1) == k1) F1[i] = f1[ci][j];
            }
        }   
        for (int i = i2; i >= i1 && (i2 - i) <= k2; i--) {
            int ci = i & 1;
            int pi = 1 - ci;
            for (int j = j2; j >= j1 && (i2 - i) + (j2 - j) <= k2; j--) {
                if (i == i2 && j == j2)
                    f2[ci][j] = f (i, j);
                else {
                    f2[ci][j] = 0;
                    if (i + 1 <= i2) f2[ci][j] = max (f2[ci][j], f2[pi][j]);
                    if (j + 1 <= j2) f2[ci][j] = max (f2[ci][j], f2[ci][j + 1]);
                    f2[ci][j] += f (i, j);
                }
                if ((i - i1) + (j - j1) == k1 && F1[i] + f2[ci][j] - f (i, j) > ans) {
                    ans = F1[i] + f2[ci][j] - f (i, j);
                    ii = i;
                    jj = j;
                }
            }
        }   
    }
    if (isans) cout << ans << endl;
    if (h != 0) printf ("%c", h); else {
        go (i1, j1, ii, jj, 0);
        go (ii, jj, i2, j2, 0);
    }
    re 0;
}

int main () {
    scanf ("%d%d%d", &n, &m, &p);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    for (int i = 0; i < m; i++) scanf ("%d", &y[i]);
    if (n == 1 && m == 1) {
        printf ("%d\n\n", f (0, 0));
        re 0;
    }
    go (0, 0, n - 1, m - 1, 1);
    return 0;
}