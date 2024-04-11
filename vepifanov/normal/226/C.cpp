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
ll L, R, k;
ll e[2][2];
ll g[2][2];
ll h[2][2];

int main () {
    cin >> m >> L >> R >> k;
    ll s = 1;
    for (ll i = 1; i * i <= R; i++) {
        ll j = i;
        if (R / j - (L - 1) / j >= k && j > s) s = j;
        j = R / i;
        if (R / j - (L - 1) / j >= k && j > s) s = j;
    }
    e[0][0] = e[1][1] = g[0][1] = g[1][0] = g[1][1] = 1 % m;
    while (s) {
        if (s & 1) {
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++)
                    h[i][j] = ((ll)e[i][0] * g[0][j] + (ll)e[i][1] * g[1][j]) % m;
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++)
                    e[i][j] = h[i][j];
        }
        s /= 2;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                h[i][j] = ((ll)g[i][0] * g[0][j] + (ll)g[i][1] * g[1][j]) % m;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                g[i][j] = h[i][j];
    }
    printf ("%I64d\n", e[1][0]);
    return 0;
}