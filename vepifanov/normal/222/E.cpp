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

ll n;
int m, k;
string s;
int g[53][53];
int e[53][53];
int h[53][53];

int get (char c) {
    if (c >= 'a' && c <= 'z') re c - 'a' + 1;
    re c - 'A' + 27;
}

int main () {
    scanf ("%I64d%d%d", &n, &m, &k);
    for (int i = 0; i <= m; i++)
        for (int j = 1; j <= m; j++)
            g[i][j] = 1;    
    for (int i = 0; i < k; i++) {
        cin >> s;
        int a = get (s[0]), b = get (s[1]);
        g[a][b] = 0;
    }
    for (int i = 0; i <= m; i++) e[i][i] = 1;
    while (n) {
        if (n & 1) {
            for (int i = 0; i <= m; i++)
                for (int j = 0; j <= m; j++) {
                    ll tmp = 0;
                    for (int k = 0; k <= m; k++)
                        (tmp += (ll)e[i][k] * g[k][j]) %= mod;
                    h[i][j] = tmp % mod;    
                }
            for (int i = 0; i <= m; i++)
                for (int j = 0; j <= m; j++)
                    e[i][j] = h[i][j];
        }
        n /= 2;
        for (int i = 0; i <= m; i++)
            for (int j = 0; j <= m; j++) {
                ll tmp = 0;
                for (int k = 0; k <= m; k++)
                    (tmp += (ll)g[i][k] * g[k][j]) %= mod;
                h[i][j] = tmp % mod;    
            }
        for (int i = 0; i <= m; i++)
            for (int j = 0; j <= m; j++)
                g[i][j] = h[i][j];
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) (ans += e[0][i]) %= mod;
    printf ("%d\n", ans);
    return 0;
}