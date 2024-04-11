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
string s;

int res[151];
int wp[151][151][151], rp[151][151][151];
int wf[151][151], rf[151][151];
int f[151];

int full (int, int);

int pal (int l, int r, int c) {
    if (c < 0) re -1e8;
    if (l > r) re int (c != 0) * -1e8;
    if (c > r - l + 1) re -1e8;
    if (c == 0) re full (l, r);
    if (wp[l][r][c]) re rp[l][r][c];
    wp[l][r][c] = 1;
    int cur = -1e8;
    if (s[l] == s[r]) cur = max (cur, pal (l + 1, r - 1, c - int (l < r) - 1));
    for (int k = l + 1; k <= r; k++) cur = max (cur, full (l, k - 1) + pal (k, r, c));
    for (int k = l; k < r; k++) cur = max (cur, full (k + 1, r) + pal (l, k, c));
    re rp[l][r][c] = cur;
}

int full (int l, int r) {
    if (l > r) re 0;
    if (wf[l][r]) re rf[l][r];
    wf[l][r] = 1;
    int cur = -1e8;
    for (int k = l; k < r; k++) cur = max (cur, full (l, k) + full (k + 1, r));
    for (int k = 1; k <= r - l + 1; k++) 
        if (f[k] >= 0)
            cur = max (cur, pal (l, r, k) + f[k]);
    re rf[l][r] = cur;
}

int main () {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> f[i];
    cin >> s;
    memset (res, 0, sizeof (res));
    for (int i = 1; i <= n; i++) {
        res[i] = res[i - 1];
        for (int j = 0; j < i; j++) res[i] = max (res[i], res[j] + full (j, i - 1));
    }
    printf ("%d\n", res[n]);
    return 0;
}