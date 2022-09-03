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

const int N = 100100;
const int K = 100;
const int mod = 1000000000 + 7;

int n;
int m;
int c[N + 1][K + 1];
int sum[K + 1][N + 1];
int x[N + 1];
int y[K + 1][N + 1];

int main () {
    for (int i = 0; i <= N; i++)    
        for (int j = 0; j <= min (i, K); j++)
            if (i == 0 || j % i == 0)
                c[i][j] = 1;
            else    
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    for (int i = 0; i < m; i++) {
        int l, r, k;
        scanf ("%d%d%d", &l, &r, &k); l--;
        int s = r - l - 1;
        y[k][l] += 1;
        for (int t = 0; t <= k; t++)             
            y[k - t][r] = (y[k - t][r] - c[s + t][t] + mod) % mod;
    }
    for (int t = K; t >= 0; t--) {
        int tmp = 0;
        for (int i = 0; i < n; i++) {
            tmp = (tmp + y[t][i]) % mod;
            if (t == 0)
                x[i] = (x[i] + tmp) % mod;
            else    
                y[t - 1][i] = (y[t - 1][i] + tmp) % mod;
        }
    }
    for (int i = 0; i < n; i++) printf ("%d ", x[i]);
    printf ("\n");
    return 0;
}