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
string s, a, b;

ll h[2001], f[2001], v[2001001];
int ca[2001], cb[2001];
set<ll> all;

int main () {
    cin >> s >> a >> b;
    n = sz (s);
    f[0] = 1;
    for (int i = 0; i < n; i++) f[i + 1] = f[i] * 17239;
    h[n] = 0;
    for (int i = n - 1; i >= 0; i--) h[i] = h[i + 1] * 17239 + s[i];
    for (int i = 0; i + sz (a) <= n; i++)
        if (s.substr (i, sz (a)) == a)
            ca[i] = 1;
    for (int i = sz (b); i <= n; i++)
        if (s.substr (i - sz (b), sz (b)) == b)
            cb[i] = 1;
    for (int i = 0; i < n; i++)
        for (int j = i + max (sz (a), sz (b)); j <= n; j++)
            if (ca[i] && cb[j])
                v[m++] = h[i] - h[j] * f[j - i];
    sort (v, v + m);
    printf ("%d\n", unique (v, v + m) - v);
    return 0;
}