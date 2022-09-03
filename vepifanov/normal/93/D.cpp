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

int g[17][17];
int e[17][17];
int z[17][17];

int forb (int a, int b) {
    if (a == b || a == 0 && b == 1 || a == 1 && b == 0 || a == 2 && b == 3 || a == 3 && b == 2) re 1;
    re 0;
}

int forb (int a, int b, int c) {
    if (a == 3 && b == 0 && c == 2 || a == 2 && b == 0 && c == 3) re 1;
    re 0;
}

int power (int x, int y) {
    int z = 1;
    while (y) {
        if (y & 1) z = ((ll)z * x) % mod;
        x = ((ll)x * x) % mod;
        y /= 2;
    }
    re z;
}

int go (int x, int t) {
    if (x == 0) re 0;
    int ans = 3;
    if (t) (ans += go ((x + 1) / 2, 0)) %= mod;
    memset (g, 0, sizeof (g));
    for (int a = 0; a < 4; a++)
        for (int b = 0; b < 4; b++)
            if (!forb (a, b)) {
                g[a * 4 + b][16] = 1;
                for (int c = 0; c < 4; c++)
                    if (!forb (b, c) && !forb (a, b, c))
                        g[a * 4 + b][b * 4 + c] = 1;
            }
    g[16][16] = 1;
    memset (e, 0, sizeof (e));
    for (int i = 0; i < 17; i++) e[i][i] = 1;
    x--;
    while (x) {
        if (x & 1) {
            for (int i = 0; i < 17; i++)
                for (int j = 0; j < 17; j++) {
                    z[i][j] = 0;
                    for (int k = 0; k < 17; k++)
                        z[i][j] = (z[i][j] + (ll)e[i][k] * g[k][j]) % mod;
                }
            for (int i = 0; i < 17; i++)
                for (int j = 0; j < 17; j++) 
                    e[i][j] = z[i][j];
        }
        x /= 2;
        for (int i = 0; i < 17; i++)
            for (int j = 0; j < 17; j++) {
                z[i][j] = 0;
                for (int k = 0; k < 17; k++)
                    z[i][j] = (z[i][j] + (ll)g[i][k] * g[k][j]) % mod;
            }
        for (int i = 0; i < 17; i++)
            for (int j = 0; j < 17; j++) 
                g[i][j] = z[i][j];
    }
    for (int i = 0; i < 17; i++) (ans += e[i][16]) %= mod;
    if (t) ans = ((ll)ans * power (2, mod - 2)) % mod;
    re ans;
}

int main () {
    scanf ("%d%d", &n, &m);
    printf ("%d\n", (go (m, 1) - go (n - 1, 1) + mod) % mod);
    return 0;
}