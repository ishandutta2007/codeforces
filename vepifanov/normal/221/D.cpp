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
vi v[100001];
int w[100001];
int u[100001];
vii p[100001];
int res[100001];
int o;
     
int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int x;
        scanf ("%d", &x);
        if (x <= n) v[x].pb (i);
    }
    for (int i = 1; i <= n; i++)
        if (sz (v[i]) >= i) {
            v[i].pb (n);
            w[o++] = i;
        }
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        p[a].pb (mp (b, i));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < o; j++)
            while (v[w[j]][u[j]] < i) u[j]++;
        for (int j = 0; j < sz (p[i]); j++) {
            int b = p[i][j].fi;
            int c = p[i][j].se;
            for (int t = 0; t < o; t++)
                if (u[t] + w[t] < sz (v[w[t]]) && v[w[t]][u[t] + w[t] - 1] <= b && v[w[t]][u[t] + w[t]] > b)
                    res[c]++;
        }
    }
    for (int i = 0; i < m; i++) printf ("%d\n", res[i]);
    return 0;
}