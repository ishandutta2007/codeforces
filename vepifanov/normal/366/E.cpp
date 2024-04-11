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
int k;
int q;
int a1[10], a2[10], b1[10], b2[10];

int main () {
    scanf ("%d%d%d%d", &n, &m, &k, &q);
    for (int i = 0; i < k; i++) {
        a1[i] = b1[i] = 1e9;
        a2[i] = b2[i] = -1e9;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int x;
            scanf ("%d", &x); x--;
            a1[x] = min (a1[x], i + j);
            a2[x] = max (a2[x], i + j);
            b1[x] = min (b1[x], i - j);
            b2[x] = max (b2[x], i - j);
        }
    int x, y;
    scanf ("%d", &x); x--;
    int ans = 0;
    for (int i = 1; i < q; i++) {
        scanf ("%d", &y); y--;
        ans = max (ans, abs (a2[x] - a1[y]));
        ans = max (ans, abs (b2[x] - b1[y]));
        ans = max (ans, abs (a2[y] - a1[x]));
        ans = max (ans, abs (b2[y] - b1[x]));
        x = y;
    }
    printf ("%d\n", ans);
    return 0;
}