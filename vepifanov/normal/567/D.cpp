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
int k;
set<ii> all;
int q;

int get (int x) {
    re (x + 1) / (k + 1);
}

int main () {
    scanf ("%d%d%d", &n, &m, &k);
    scanf ("%d", &q);
    int ans = 0;
    all.insert (mp (0, n - 1));
    ans += get (n);
    for (int i = 0; i < q; i++) {
        int x;
        scanf ("%d", &x); x--;
        auto it = all.lower_bound (mp (x, 1e9));
        it--;
        int a = it->fi;
        int b = it->se;
        all.erase (it);
        ans -= get (b - a + 1);
        if (x > a) {
            ans += get (x - a);
            all.insert (mp (a, x - 1));
        }
        if (x < b) {
            ans += get (b - x);
            all.insert (mp (x + 1, b));
        }                                      
        if (ans < m) {
            printf ("%d\n", i + 1);
            re 0;
        }
    }
    printf ("-1\n");
    return 0;
}