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

int main () {
    scanf ("%d", &n);
    int x1 = 1e9, y1 = 1e9, x2 = -1e9, y2 = -1e9;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        int x3, y3, x4, y4;
        scanf ("%d%d%d%d", &x3, &y3, &x4, &y4);
        x1 = min (x1, x3);
        y1 = min (y1, y3);
        x2 = max (x2, x4);
        y2 = max (y2, y4);
        sum += (ll)(x4 - x3) * (y4 - y3);
    }
    if (x2 - x1 == y2 - y1 && sum == (ll)(x2 - x1) * (y2 - y1)) printf ("YES\n"); else printf ("NO\n");
    return 0;
}