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
                         
typedef long long ll;
typedef vector<int> vi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

int n;
int m, p;

vi v, w;
int u[300][300];
vi g[600];
int cp[600], cq[600];
int res[600][600];
int was[600][600];

int power (int a, int b) {
    int c = 1;
    while (b) {
        if (b & 1) c = ((ll)c * a) % p;
        b /= 2;
        a = ((ll)a * a) % p;
    }
    re c;
}

int go (int x, int z) {
    if (x == z) re 1;
    if (was[x][z]) re res[x][z];
    was[x][z] = 1;
    ll cur = 0;
    for (int i = 0; i < sz (g[x]); i++)
        cur += go (g[x][i], z);
    re res[x][z] = cur % p;
}

int main () {
    scanf ("%d%d%d", &n, &m, &p);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        cp[a]++;
        cq[b]++;
        g[a].pb (b);    
    }
    int res = 1;
    for (int i = 0; i < n; i++)
        if (cq[i] == 0 && cp[i] == 0) {
            if ((sz (v) ^ sz (w)) & 1)
                res = p - res;
        } else
        if (cq[i] == 0) v.pb (i); else
        if (cp[i] == 0) w.pb (i);
    m = sz (v);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            u[i][j] = go (v[i], w[j]);
    for (int i = 0; i < m; i++) {
        for (int j = i; j < m; j++)
            if (u[j][i] != 0) {
                for (int k = i; k < m; k++)
                    swap (u[i][k], u[j][k]);
                if (i != j) res = (p - res) % p;
                break;
            }
        res = ((ll)res * u[i][i]) % p;
        if (!u[i][i]) break;
        for (int j = i + 1; j < m; j++)
            if (u[j][i]) {
                int tmp = ((ll)u[j][i] * power (u[i][i], p - 2)) % p;
                for (int k = i; k < m; k++)
                    u[j][k] = (u[j][k] - ((ll)u[i][k] * tmp) % p + p) % p;
            }
    }
    printf ("%d\n", res);
    return 0;
}