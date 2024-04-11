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
vi v[100000];
int q[100001];
int was[100001];

int go (int x, int p, int k) {
    if (x == 0) {
        if (k != n) re 0;
        int ok = 0;
        for (int i = 0; i < sz (v[0]); i++)
            if (v[0][i] == p)
                ok = 1;
        re ok;
    }   
    was[x] = 1;
    q[k] = x;
    for (int i = 0; i < sz (v[x]); i++) {
        int y = v[x][i];
        int ok = 0;
        for (int j = 0; j < sz (v[y]); j++)
            if (v[y][j] == p)
                ok = 1;
        if (ok && !was[y])
            if (go (y, x, k + 1))
                re 1;
    }
    was[x] = 0;
    re 0;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < 2 * n; i++) {
        int a, b;
        scanf ("%d%d", &a, &b); a--; b--;
        v[a].pb (b);
        v[b].pb (a);
    }
    for (int i = 0; i < n; i++)
        if (sz (v[i]) != 4) {
            printf ("-1\n");
            re 0;
        }
    q[0] = 0;
    for (int i = 0; i < sz (v[0]); i++)
        if (go (v[0][i], 0, 1)) {
            for (int j = 0; j < n; j++) printf ("%d ", q[j] + 1);
            printf ("\n");
            re 0;
        }
    printf ("-1\n");
    return 0;
}