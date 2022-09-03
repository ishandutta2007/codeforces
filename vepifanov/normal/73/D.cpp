#include <cstdio>
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

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
    re x > 0 ? x : -x;
}

int n;
int m, k, a, b;
int was[1000000];
vi v[1000000];

int go (int x) {
    was[x] = 1;
    int y = 1;
    for (int i = 0; i < sz (v[x]); i++)
        if (!was[v[x][i]])
            y += go (v[x][i]);
    re y;
}

int main() {
    scanf ("%d%d%d", &n, &m, &k);   
    for (int i = 0; i < m; i++) {
        scanf ("%d%d", &a, &b); a--; b--;
        v[a].pb (b);
        v[b].pb (a);
    }
    int r = 0, s = 0;
    for (int i = 0; i < n; i++)
        if (!was[i]) {
            int x = go (i);
            r++;
            s += min (x, k);
        }   
    if (k == 1) printf ("%d\n", max (r - 2, 0)); else printf ("%d\n", max (r - s / 2 - 1, 0));
    return 0;
}