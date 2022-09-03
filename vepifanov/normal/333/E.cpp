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
typedef unsigned int ui;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

const int inf = 2e9;
const int LEN = 30;

int n;
int m;
int p[3000];
int x[3000];
int y[3000];
ui d[3000][3000];
ui v[3000*2999/2 + 1];
int o = 0;
int w[3000][3000 / LEN];

int can (ui s) {
    memset (w, 0, sizeof (w));
    int T = (n + LEN - 1) / LEN;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (d[i][j] >= s)
                w[i][j / LEN] |= 1 << (j % LEN);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (d[i][j] >= s)
                for (int k = j / LEN; k < T; k++)
                    if (w[i][k] & w[j][k])
                        re 1;
    re 0;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) p[i] = i;
    random_shuffle (p, p + n);
    for (int i = 0; i < n; i++) {
        scanf ("%d%d", &x[p[i]], &y[p[i]]);
        x[p[i]] *= 2;
        y[p[i]] *= 2;
        d[p[i]][p[i]] = 0;
    }   
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            ui tmp = sqr (x[i] - x[j]);
            tmp += sqr (y[i] - y[j]);
            d[i][j] = d[j][i] = tmp;
            v[o++] = tmp;
        }
    v[o++] = 0;
    sort (v, v + o);
    o = unique (v, v + o) - v;
    int l = 0, r = o;
    while (r - l > 1) {
        int s = (l + r) / 2;
        if (can (v[s])) l = s; else r = s;
    }
    printf ("%.10f\n", sqrt (v[l] + 0.0) / 4);
    cerr << clock () << endl;
    return 0;
}