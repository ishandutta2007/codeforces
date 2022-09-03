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
int k;
ll m;
int was[61][2][65];
ll res[61][2][65];

ll go (ll s, int i, int f, int j) {
    if (i < 0) re int (j == 0);
    if (was[i][f][j]) re res[i][f][j];
    was[i][f][j] = 1;
    int c = (s >> i) & 1;
    ll cur = go (s, i - 1, f | c, j);
    if (j > 0 && (f || c == 1)) cur += go (s, i - 1, f, j - 1);
    re res[i][f][j] = cur;
}

ll calc (ll s, int k) {
    memset (was, 0, sizeof (was));  
    re go (s, 60, 0, k);
}

int main () {
    cin >> m >> k;
    ll l = 0, r = 1e18;
    while (r - l > 1) {
        ll s = (l + r) / 2;
        if (calc (2 * s, k) - calc (s, k) >= m) r = s; else l = s;
    }
    cout << r << endl;
    return 0;
}