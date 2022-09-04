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
ll k;
int was[200][200];
ll cnt[200][200];
string res;
set<ii> all;
int ct = 0;

ll go (int i, int j) {
    if (i > j) re 1;
    if (was[i][j] == ct) re cnt[i][j];
    was[i][j] = ct;
    ll cur = 0;
    if (res[i] != ')' && ((j - i) & 1)) {
        for (int k = i + 1; k <= j; k++) 
            if (res[k] != '(') {
                ll a = go (i + 1, k - 1), b = go (k + 1, j), c = 0;
                if (a == 0 || b == 0) continue;
                if (a > (::k + 1) / b) c = ::k + 1; else c = a * b;
                cur = min (cur + c, ::k + 1);
                if (cur > ::k) break;
            }
    }
    re cnt[i][j] = cur;
}

int main () {
    cin >> n >> m >> k;
    int l = n + m - 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int x;
            scanf ("%d", &x);
            all.insert (mp (x, i + j));
        }
    res = string (l, '?');
    while (!all.empty ()) {
        int d = all.begin ()->se;
        all.erase (all.begin ());
        if (res[d] == '?') {
            ct++;
            res[d] = '(';
            ll tmp = go (0, l - 1);
            if (tmp < k) {
                k -= tmp;
                res[d] = ')';
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf ("%c", res[i + j]);
        printf ("\n");
    }
    return 0;
}