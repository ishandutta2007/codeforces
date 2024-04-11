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
int next[5000000][2];
ll x[100002];
ll l[100002];
ll r[100002];
int o;

int add (ll x) {
    int y = 0;
    for (int i = 40; i >= 0; i--) {
        int c = (x >> i) & 1;
        if (next[y][c] == 0) next[y][c] = o++;
        y = next[y][c];
    }
    re 0;
}

ll get (ll x) {
    int y = 0;
    ll z = 0;
    for (int i = 40; i >= 0; i--) {
        int c = 1 - ((x >> i) & 1);
        if (next[y][c] != 0) {
            z |= (ll)1 << i;
            y = next[y][c];
        } else y = next[y][1 - c];
    }
    re z;
}

int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++) scanf ("%I64d", &x[i]);
    l[0] = 0;
    r[n + 1] = 0;
    for (int i = 1; i <= n; i++) {
        l[i] = l[i - 1] ^ x[i];
        r[n - i + 1] = r[n - i + 2] ^ x[n - i + 1];
    }
    ll ans = 0;
    o = 1;
    for (int i = 1; i <= n + 1; i++) {
        add (l[i - 1]);
        ans = max (ans, get (r[i]));
    }
    cout << ans << endl;
    return 0;
}