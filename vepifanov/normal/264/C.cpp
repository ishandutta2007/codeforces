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
int x[100000];
int y[100000];
ll res[100000];
int q;

int main () {
    scanf ("%d%d", &n, &q);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &y[i]);
        y[i]--;
    }
    for (int i = 0; i < q; i++) {
        int a, b;
        scanf ("%d%d", &a, &b);
        for (int j = 0; j < n; j++) res[j] = -1e18;
        ll r1 = 0, r2 = 0, ans = 0;
        int c1 = n, c2 = n;
        for (int j = 0; j < n; j++) {
            ll cur = max ((ll)b * x[j], res[y[j]] + (ll)a * x[j]);
            if (c1 != y[j]) cur = max (cur, r1 + (ll)b * x[j]);
            if (c2 != y[j]) cur = max (cur, r2 + (ll)b * x[j]);
            res[y[j]] = max (res[y[j]], cur);
            if (c1 == y[j]) r1 = max (r1, cur); else
            if (c2 == y[j]) {
                r2 = max (r2, cur);
                if (r2 > r1) {
                    swap (r1, r2);
                    swap (c1, c2);
                }
            } else
            if (cur > r1) {
                r2 = r1;
                c2 = c1;
                r1 = cur;
                c1 = y[j];
            } else
            if (cur > r2) {
                r2 = cur;
                c2 = y[j];
            }
            ans = max (ans, cur);
        }
        printf ("%I64d\n", ans);
    }
    return 0;
}