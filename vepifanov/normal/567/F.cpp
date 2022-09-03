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
#include <cassert>

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
#define prev PREV
#define j0 j1347829
#define j1 j234892
                         
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
int cur[70];
ll res[70][70];
int was[70][70];
vi v[70];
int x[100];
int y[100];
string s[100];

bool check (int a, int b, string s) {
    if (s == "=") re cur[a] == cur[b];
    if (s == "<=") re cur[a] <= cur[b];
    if (s == ">=") re cur[a] >= cur[b];
    if (s == "<") re cur[a] < cur[b];
    if (s == ">") re cur[a] > cur[b];
    re false;
}

int check (int p) {
//  for (int i = 0; i < 2 * n; i++) printf ("%d ", cur[i]);
//  printf ("\n");
    for (int i = 0; i < sz (v[p]); i++) {
        int j = v[p][i];
//      printf ("%d %d %s = %d %d\n", x[j], y[j], s[j].c_str(), cur[x[j]], cur[y[j]]);
        if (!check(x[j], y[j], s[j])) re 0;
    }
    re 1;
}

ll go (int i, int l, int r) {
    if (i == n) re 1;
    if (was[l][r]) re res[l][r];
    was[l][r] = 1;
    ll ans = 0;
    cur[l] = cur[l + 1] = i;
    if (check (l) && check (l + 1)) ans += go (i + 1, l + 2, r);
    cur[l] = cur[l + 1] = n;
    if (i + 1 < n) {
        cur[l] = cur[r] = i;
        if (check (l) && check (r)) ans += go (i + 1, l + 1, r - 1);
        cur[l] = cur[r] = n;
    
        cur[r - 1] = cur[r] = i;
        if (check (r - 1) && check (r)) ans += go (i + 1, l, r - 2);
        cur[r - 1] = cur[r] = n;    
    }
//  printf ("%d %d = %I64d\n", l, r, ans);
    re res[l][r] = ans;
}

int main () {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x[i] >> s[i] >> y[i]; x[i]--; y[i]--;
        v[x[i]].pb (i);
        v[y[i]].pb (i);
    }
    for (int i = 0; i < 2 * n; i++) cur[i] = n;
    cout << go (0, 0, 2 * n - 1) << endl;
    return 0;
}