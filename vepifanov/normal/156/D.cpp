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
int m, k;
int was[100000];
vi v[100000];

int go (int x) {
    int y = 1;
    was[x] = 1;
    for (int i = 0; i < sz (v[x]); i++)
        if (!was[v[x][i]])
            y += go (v[x][i]);
    re y;
}

int main () {
    scanf ("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        v[a].pb (b);
        v[b].pb (a);
    }
    int r = 0;
    int ans = 1;
    memset (was, 0, sizeof (was));
    for (int i = 0; i < n; i++)
        if (!was[i]) {
            int j = go (i);
            ans = ((ll)ans * j) % k;
            r++;
        }
    if (r == 1) 
        ans = 1; 
    else
        for (int i = 0; i < r - 2; i++) ans = ((ll)ans * n) % k;
    printf ("%d\n", ans % k);
    return 0;
}