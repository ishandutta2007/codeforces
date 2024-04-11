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

const int mod = 1000000000 + 7;

int n;
int m;
vi v, w;
int was[2000][2000];
int res[2000][2000];
int f[100001];
int rf[100001];

int cool (int x) {
    while (x) {
        if (x % 10 != 4 && x % 10 != 7) re 0;
        x /= 10;
    }
    re 1;
}

int cnk (int n, int k) {
    if (n < 0 || k < 0 || k > n) re 0;
    re (((ll)f[n] * rf[k]) % mod * rf[n - k]) % mod;
}

int power (int a, int b) {
    int c = 1;
    while (b) {
        if (b & 1) c = ((ll)c * a) % mod;
        a = ((ll)a * a) % mod;
        b /= 2;
    }
    re c;
}

int calc (int i, int j) {
    if (j < 0) re 0;
    if (i == sz (w)) re int (j == 0);
    if (was[i][j]) re res[i][j];
    was[i][j] = 1;
    re res[i][j] = ((ll)calc (i + 1, j - 1) * w[i] + calc (i + 1, j)) % mod;
}

int main () {
    f[0] = rf[0] = 1;
    for (int i = 1; i <= 100000; i++) {
        f[i] = ((ll)f[i - 1] * i) % mod;
        rf[i] = power (f[i], mod - 2);
    }
    cin >> n >> m;
    int rest = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (cool (x)) v.pb (x); else rest++;
    }
    sort (all (v));
    int cur = 0;
    for (int i = 0; i < sz (v); i++) {
        if (i > 0 && v[i - 1] != v[i]) cur = 0;
        cur++;
        if (i + 1 == sz (v) || v[i + 1] != v[i]) w.pb (cur);
    }
    int ans = 0;
    for (int i = 0; i <= sz (w) && i <= m; i++) ans = (ans + ((ll)cnk (rest, m - i) * calc (0, i))) % mod;
    printf ("%d\n", ans);
    return 0;
}