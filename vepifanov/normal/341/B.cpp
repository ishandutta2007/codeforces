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

#define filename ""

const double pi = 2 * asin (1.0);

int n;
int m;
int x[100002];
int y[100002];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    y[0] = 0;
    for (int i = 1; i <= n + 1; i++) y[i] = n + 1;
    for (int i = 0; i < n; i++) {
        int l = 0, r = i + 1;
        while (r - l > 1) {
            int s = (l + r) / 2;
            if (y[s] <= x[i]) l = s; else r = s;
        }
        y[l + 1] = min (y[l + 1], x[i]);
    }
    int ans = 0;
    while (y[ans + 1] <= n) ans++;
    printf ("%d\n", ans);
    return 0;
}