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

const int mod = 1000000000 + 7;
const int inf = 1e9 + 1;

int n;
int m;

int sum[1 << 24];
int res[1 << 24];
int x[24], y[2];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    scanf ("%d", &m);
    for (int i = 0; i < m; i++) scanf ("%d", &y[i]);
    sort (y, y + m);
    res[0] = 1;
    sum[0] = 0;
    for (int i = 1; i < (1 << n); i++) {
        int j = 0, k = i;
        while (!(k & 1)) {
            k >>= 1;
            j++;
        }
        sum[i] = min (inf, sum[i - (1 << j)] + x[j]);
        int ok = 1;
        for (int j = 0; j < m; j++)
            if (sum[i] == y[j])
                ok = 0;
        if (ok) {
            ll tmp = 0;
            for (int j = 0; j < n; j++)
                if ((i >> j) & 1)
                    tmp += res[i - (1 << j)];
            res[i] = tmp % mod;
        }
    }
    cout << res[(1 << n) - 1] << endl;
    return 0;
}