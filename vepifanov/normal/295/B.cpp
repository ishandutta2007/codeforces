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
int g[500][500];
int x[500];
ll res[500];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf ("%d", &g[i][j]);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &x[i]);
        x[i]--;
    }   
    for (int k = n - 1; k >= 0; k--) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                g[x[i]][x[j]] = min (g[x[i]][x[j]], g[x[i]][x[k]] + g[x[k]][x[j]]);
        ll ans = 0;
        for (int i = k; i < n; i++)
            for (int j = k; j < n; j++)
                ans += g[x[i]][x[j]];
        res[k] = ans;
    }
    for (int i = 0; i < n; i++) printf ("%I64d ", res[i]);
    printf ("\n");
    return 0;
}