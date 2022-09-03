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

vi res;
vii v[100000];

int go (int x, int p, int f) {
    int cur = 0;
    for (int i = 0; i < sz (v[x]); i++) {
        int y = v[x][i].fi;
        int z = v[x][i].se;
        if (y == p) continue;
        cur |= go (y, x, z);
    }
    if (f && !cur) {
        res.pb (x + 1);
        cur = 1;
    }
    re cur;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        scanf ("%d%d%d", &a, &b, &c); a--; b--; c--;
        v[a].pb (mp (b, c));
        v[b].pb (mp (a, c));
    }
    go (0, 0, 0);
    sort (all (res));
    printf ("%d\n", sz (res));
    for (int i = 0; i < sz (res); i++)
        printf ("%d ", res[i]);
    printf ("\n");  
    return 0;
}