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

const int mod = 12345;

ll n;
int m;

vii v;

int g[123][123], u[123][123], z[123][123];
int was[26], use[26];

int main () {
    cin >> n >> m;
    int K = 1;
    for (int i = 0; i < m; i++) {
        char c;
        int x;
        cin >> c >> x;
        if (was[c - 'A'] == 0) was[c - 'A'] = 1;
        if (x > 1) v.pb (mp (x, c - 'A')); else was[c - 'A'] = 2;
        K *= x;
    }
    for (int i = 0; i < K; i++) {
        vi w;
        int k = i;
        for (int j = 0; j < sz (v); j++) {
            w.pb (k % v[j].fi);
            k /= v[j].fi;
        }
        for (int j = 0; j < 26; j++) {
            if (!was[j]) continue;
            int cur = 0;
            for (int k = sz (v) - 1; k >= 0; k--)
                if (v[k].se == j)
                    cur = (cur * v[k].fi + (w[k] + 1) % v[k].fi);
                else
                    cur = (cur * v[k].fi + w[k]);   
            g[i][cur]++;
        }
    }
    for (int i = 0; i < K; i++)
        u[i][i] = 1;
    while (n) {
        if (n & 1) {
            for (int i = 0; i < K; i++)
                for (int j = 0; j < K; j++) {
                    ll tmp = 0;
                    for (int k = 0; k < K; k++)
                        tmp += u[i][k] * g[k][j];
                    z[i][j] = tmp % mod;
                }
            for (int i = 0; i < K; i++)
                for (int j = 0; j < K; j++)
                    u[i][j] = z[i][j];
        }
        n /= 2;
        for (int i = 0; i < K; i++)
            for (int j = 0; j < K; j++) {
                ll tmp = 0;
                for (int k = 0; k < K; k++)
                    tmp += g[i][k] * g[k][j];
                z[i][j] = tmp % mod;
            }
        for (int i = 0; i < K; i++)
            for (int j = 0; j < K; j++)
                g[i][j] = z[i][j];
    }
    int ans = 0;
    for (int i = 0; i < K; i++) {
        memset (use, 0, sizeof (use));
        int k = i;
        for (int j = 0; j < sz (v); j++) {
            int t = k % v[j].fi;
            k /= v[j].fi;
            if (t == 0) use[v[j].se] = 1;
        }
        int ok = 1;
        for (int j = 0; j < 26; j++)
            if (was[j] == 1 && use[j] == 0)
                ok = 0;
        ans = (ans + ok * u[0][i]) % mod;
    }
    printf ("%d\n", ans);
    return 0;
}