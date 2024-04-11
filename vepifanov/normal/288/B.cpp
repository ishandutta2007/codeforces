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
int m, k;
int p[8], was[8];
vi v[8];

int dfs (int x) {
    if (was[x]) re 0;
    was[x] = 1;
    int ans = 1;
    for (int i = 0; i < sz (v[x]); i++) ans += dfs (v[x][i]);
    re ans;
}

int go (int i) {
    if (i == k) {
        memset (was, 0, sizeof (was));
        for (int j = 0; j < k; j++) v[j].clear ();
        for (int j = 0; j < k; j++) v[p[j]].pb (j);
        re int (dfs (0) == k);
    }
    int ans = 0;
    for (int t = 0; t < k; t++) {
        p[i] = t;
        if (i == 0 || t != i) ans = (ans + go (i + 1)) % mod;
    }
    re ans;
}

int main () {
    scanf ("%d%d", &n, &k);
    int ans = go (0);
    for (int i = k; i < n; i++) ans = ((ll)ans * (n - k)) % mod;
    printf ("%d\n", ans);
    return 0;
}