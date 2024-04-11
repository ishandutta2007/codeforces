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
int x[100000];
ii y[100000];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    m = 0;
    for (int i = 0; i < n; i++) {
        if (m >= 2 && x[i] == y[m - 1].fi && x[i] == y[m - 2].fi) continue;
        y[m++] = mp (x[i], i + 1);
    }
    n = m;
    int s1 = 0, s2 = 0;
    for (int i = 0; i + 1 < n; i++) {
        s1 += int (y[i].fi > y[i + 1].fi);
        s2 += int (y[i].fi < y[i + 1].fi);
    }
    for (int i = 0; i < n; i++)
        for (int j = 1; j <= 2 && i + j < n; j++) {
            if (y[i].fi == y[i + j].fi) continue;
            int t1 = s1, t2 = s2;
            for (int k = max (0, i - 1); k < min (n, i + j + 1); k++) {
                t1 -= int (y[k].fi > y[k + 1].fi);
                t2 -= int (y[k].fi < y[k + 1].fi);
            }
            swap (y[i], y[i + j]);
            for (int k = max (0, i - 1); k < min (n, i + j + 1); k++) {
                t1 += int (y[k].fi > y[k + 1].fi);
                t2 += int (y[k].fi < y[k + 1].fi);
            }
            swap (y[i], y[i + j]);
            if (t1 != 0 && t2 != 0) {
                printf ("%d %d\n", y[i].se, y[i + j].se);
                re 0;
            }
        }   
    printf ("-1\n");
    return 0;
}