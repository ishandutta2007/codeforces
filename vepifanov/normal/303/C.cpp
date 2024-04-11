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

const int MAX = 1000000;

int n;
int m;
int v[1000001][5];
int l[1000001];
int f[1000001];
int w[1000001];
int u[1000001];
int q[5];
int x[5000];

int add (int d, int k) {
    if (l[d] <= m) {
        for (int t = 0; t < l[d]; t++)
            if (v[d][t] == k)
                re 0;
        v[d][l[d]++] = k;
    }
    re 0;
}

int main () {
//  printf ("5000 4\n");
//  for (int i = 0; i < 5000; i++) printf ("%d ", rand () % 1000 * 1000 + rand () % 1001);
//  printf ("\n");
//  re 0;
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    sort (x, x + n);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            add (x[j] - x[i], j);
    for (int i = 2; i <= MAX; i++)
        if (!f[i])
            for (int j = i; j <= MAX; j += i) {
                f[j] = 1;
                w[j] = i;
            }
    for (int i = 2; i <= MAX; i++) {
        u[i] = i;
        while (u[i] % w[i] == 0) u[i] /= w[i];
    }
    int ans = MAX + 1;
    for (int i = MAX; i >= 1; i--) {
        if (l[i] <= m) ans = i;
        if (l[i] == 0) continue;
        int j = i, o = 0;
        for (int t = 0; t < l[i]; t++) q[o++] = v[i][t];
        while (j > 1) {
            int k = i / w[j];
            for (int t = 0; t < o; t++) 
                add (k, q[t]);
            j = u[j];
        }
    }
    printf ("%d\n", ans);
    cerr << clock () << endl;
    return 0;
}