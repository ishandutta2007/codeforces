#include <cstdio>
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

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
    re x > 0 ? x : -x;
}

int n;
int m, l, r, k;
string s, a, b;
int was[51][51][201];
int qi[51 * 51 * 201];
int qj[51 * 51 * 201];
int qt[51 * 51 * 201];
int qd[51 * 51 * 201];

int upd (int i, int j, int t, int d) {
    if (!was[i][j][t]) {
        was[i][j][t] = 1;
        qi[r] = i;
        qj[r] = j;
        qt[r] = t;
        qd[r] = d;
        r++;
    }
    re 0;
}

int main() {
    cin >> n >> m >> k; m--; k--;
    cin >> a >> b;
    cin >> s;
    int len = sz (s);
    int d;
    if (b == "head") d = -1; else d = 1;
    l = 0;
    r = 1;
    qi[0] = m;
    qj[0] = k;
    qt[0] = 0;
    qd[0] = d;
    was[m][k][0] = 1;
    while (l < r) {
        int i = qi[l];
        int j = qj[l];
        int t = qt[l];
        int d = qd[l];
        if (t + 1 == len) {
            printf ("Stowaway\n");
            re 0;
        }
        l++;
        if (j + d < 0 || j + d >= n) d = -d;
        if (s[t] == '0') {
            if (i + 1 < n && i + 1 != j && i + 1 != j + d) upd (i + 1, j + d, t + 1, d);
            if (i != j + d) upd (i, j + d, t + 1, d);
            if (i - 1 >= 0 && i - 1 != j && i - 1 != j + d) upd (i - 1, j + d, t + 1, d);
        } else {
            for (int k = 0; k < n; k++)
                if (k != j + d)
                    upd (k, j + d, t + 1, d);
        }
    }
    printf ("Controller %d\n", qt[r - 1] + 1);
    return 0;
}