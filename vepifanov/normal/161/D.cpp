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

int cnt[50000][501];
vi v[50000];

ll ans = 0;

int go (int x, int p) {
    cnt[x][0] = 1;
    for (int i = 0; i < sz (v[x]); i++) {
        int y = v[x][i];
        if (y == p) continue;
        go (y, x);
        for (int j = 0; j < m; j++) ans += (ll)cnt[x][j] * cnt[y][m - j - 1];
        for (int j = 0; j < m; j++) cnt[x][j + 1] += cnt[y][j];
    }
    re 0;
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i + 1 < n; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        v[a].pb (b);
        v[b].pb (a);
    }
    memset (cnt, 0, sizeof (cnt));
    ans = 0;
    go (0, -1);
    cout << ans << endl;
    return 0;
}