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
#define prev PREV
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

const int N = 600;

int n;
int m;
ld res[N + 1];
ld prob[N + 1];
ld sum[100001];
ld f[100001];

int main () {
    scanf ("%d%d", &n, &m);
    f[0] = 0;
    for (int i = 1; i <= n; i++) f[i] = f[i - 1] + log (i + 0.0);
    prob[1] = 1;
    int last = 1;
    for (int i = 0; i <= n; i++) {
        ld tmp = 0;
        for (int j = min (N, last + 1); j >= 1; j--) {
            tmp += res[j];
            res[j] = j / (j + 1.0) * (res[j] + (j + 1) * prob[j] / 2) + (res[j - 1] + (j - 1) * prob[j - 1]) / j;
            prob[j] = prob[j] * j / (j + 1) + prob[j - 1] / j;
            if (res[j] > 1e-18 || prob[j] > 1e-18) last = max (last, j);
        }
        sum[i] = tmp;
    }
    if (m == 1) printf ("%.10f\n", (D)sum[n]); else {
        ld ans = 0;
        for (int i = 0; i <= n; i++) {
            ld tmp = f[n] - f[i] - f[n - i] + log (1.0 / m) * i + log ((m - 1.0) / m) * (n - i);
            ans += exp (tmp) * sum[i] * m;
        }                        
        printf ("%.10f\n", (D)ans);
    }
    cerr << clock () << endl;
    return 0;
}