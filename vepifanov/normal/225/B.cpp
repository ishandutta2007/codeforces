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
int m, k = 0;
ll x[100];
vi y;

int main () {
    scanf ("%d%d", &n, &m);
    x[1] = 1;
    for (int i = 2; ; i++) {
        for (int j = 1; j <= m && i - j >= 0; j++) x[i] += x[i - j];
        if (x[i] > n) break;
        k = i;
    }
    for (int i = k; i >= 1 && x[i] > 0; i--)
        if (x[i] <= n) {
            y.pb (i);
            n -= x[i];
        }
    if (sz (y) == 1) y.pb (0);
    reverse (all (y));
    printf ("%d\n", sz (y));
    for (int i = 0; i < sz (y); i++) printf ("%I64d ", x[y[i]]);
    return 0;
}