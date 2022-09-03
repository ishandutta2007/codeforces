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
int g[1000][1000];
bitset<1000> w[1000];

int can (int h) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            w[i][j] = int (g[i][j] >= h);
    for (int j = 0; j < m; j++) {
        bitset<1000> cur;
        for (int i = 0; i < n; i++)
            if (w[i][j]) {
                if ((cur & w[i]).count () >= 2) re 1;
                cur = cur | w[i];
            }
    }
    re 0;
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf ("%d", &g[i][j]);
    int l = 0, r = 1e9 + 1;
    while (r - l > 1) {
        int s = (l + r) / 2;
        if (can (s)) l = s; else r = s;
    }
    printf ("%d\n", l);
    return 0;
}