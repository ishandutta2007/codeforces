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
int t, T, x, cost;

ll get (int k) {
    re (ll)cost * k + int ((ll)(T - t) * k < m) * (ll)(m - (ll)(T - t) * (k - 1)) * x;
}

int main () {
    scanf ("%d%d", &n, &m);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        scanf ("%d%d%d%d", &t, &T, &x, &cost);
        if (T <= t) ans += cost + (ll)x * m; else ans += min (get (1), get ((m - 1) / (T - t) + 1));
    }
    cout << ans << endl;
    return 0;
}