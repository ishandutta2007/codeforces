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
int p[100000], w[100001], g[100000], res[100001];

int gp (int x) {
    if (p[x] != x) p[x] = gp (p[x]);
    re p[x];
}

int cool (int x) {
    while (x) {
        if (x % 10 != 4 && x % 10 != 7) re 0;
        x /= 10;
    }
    re 1;
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) p[i] = i;
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        p[gp (a)] = gp (b);
    }
    for (int i = 0; i < n; i++) g[gp (i)]++;
    for (int i = 0; i < n; i++)
        if (p[i] == i)
            w[g[i]]++;
    for (int i = 1; i <= n; i++) res[i] = 1e9;
    res[0] = 0;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; w[i]; j *= 2) {
            int k = min (j, w[i]);
            w[i] -= k;
            for (int t = n - k * i; t >= 0; t--) res[t + k * i] = min (res[t + k * i], res[t] + k);
        }
    int ans = 2e9;
    for (int i = 1; i <= n; i++)
        if (cool (i))
            ans = min (ans, res[i]);
    if (ans > n) ans = 0;
    printf ("%d\n", ans - 1);
    return 0;
}