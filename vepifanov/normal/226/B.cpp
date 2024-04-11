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
ll y[100001];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    sort (x, x + n);
    reverse (x, x + n);
    y[n] = 0;
    for (int i = n - 1; i >= 0; i--) y[i] = y[i + 1] + x[i];
    ll ans1 = 0;
    for (int i = 0; i < n; i++) ans1 += (ll)x[i] * i;
    scanf ("%d", &m);
    for (int i = 0; i < m; i++) {
        int k;
        scanf ("%d", &k);
        if (k == 1) { printf ("%I64d ", ans1); continue; }
        ll tmp = 1;
        ll ans = 0;
        for (int j = 0, s = 0; s < n; s += tmp, tmp *= k, j++) {
            int t = min (s + tmp, (ll)n);
            ans += (y[s] - y[t]) * j;
            if (t == n) break;
        }
        printf ("%I64d ", ans);
    }
    printf ("\n");
    return 0;
}