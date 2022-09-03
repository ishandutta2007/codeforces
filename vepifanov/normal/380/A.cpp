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

const int N = 100000;

int n;
int m;
vi v;
int t[100000];
int x[100000];
int y[100000];
ll z[100000];
ll f[100000];
int res[100000];

int main () {
    scanf ("%d", &n);
    ll R = 0;
    for (int i = 0; i < n; i++) {
        scanf ("%d%d", &t[i], &x[i]);
        f[i] = R;
        if (t[i] == 2) {
            scanf ("%d", &y[i]);
            for (int a = 0; a < y[i] && sz (v) < N; a++)
                for (int b = 0; b < x[i] && sz (v) < N; b++)
                    v.pb (v[b]);
            R += x[i] * y[i];
        } else {
            if (sz (v) < N) v.pb (x[i]);
            R++;
        }
    }
    scanf ("%d", &m);
    for (int i = 0; i < m; i++) scanf ("%I64d", &z[i]);
    int o = m;
    for (int i = n - 1; i >= 0; i--)
        while (o > 0 && z[o - 1] > f[i]) {
            if (t[i] == 1) res[o - 1] = x[i]; else res[o - 1] = v[(z[o - 1] - f[i] - 1) % x[i]];
            o--;
        }
    for (int i = 0; i < m; i++) printf ("%d ", res[i]);
    printf ("\n");
    return 0;
}