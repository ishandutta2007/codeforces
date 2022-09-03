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

double sum[100000];
double last[100000];
double res[100000];
int cnt[100000];

vector<pair<int, double> > v[100000];

bool l1 (int i, int j) {
    double a = (sum[i] + 2 * last[i]) * cnt[j];
    double b = (sum[j] + 2 * last[j]) * cnt[i];
//  printf ("%d %d = %.5f %.5f\n", i + 1, j + 1, a, b);
//  double a = sum[i];
//  double b = sum[j];
    re a < b - 1e-8 || abs (a - b) < 1e-8 && i < j;
}

double go (int x, int p) {
    res[x] = 0;
    sum[x] = 0;
    cnt[x] = 1;
    vi w;
    for (int i = 0; i < sz (v[x]); i++) {
        int y = v[x][i].fi;
        double z = v[x][i].se;
        if (y == p) continue;
        go (y, x);
        last[y] = z;
        cnt[x] += cnt[y];
        sum[x] += sum[y] + 2 * z;
        w.pb (y);
    }
    sort (all (w), l1);
    double cur = 0;
    for (int i = 0; i < sz (w); i++) {
        int y = w[i];
//      printf ("%d - %d\n", x + 1, y + 1);
        res[x] += res[y] + (cur + last[y]) * cnt[y];
        cur += 2 * last[y] + sum[y];
    }
    re res[x];
}

int main () {
    scanf ("%d", &n);
    for (int i = 1; i < n; i++) {
        int a, b;
        double c;
        scanf ("%d%d%lf", &a, &b, &c); a--; b--;
        v[a].pb (mp (b, c));
        v[b].pb (mp (a, c));
    }
    printf ("%.10f\n", go (0, 0) / (n - 1));
    return 0;
}