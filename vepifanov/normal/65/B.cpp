#include <cstdio>
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

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
    re x > 0 ? x : -x;
}

const int p10[4] = {1, 10, 100, 1000};

int n;
int m;
int res[1001][2012];
int was[1001][2012];
int next[1001][2012];
int a[1000];

int get (int x, int i) {
    re (x / p10[i]) % 10;
}

int go (int i, int x) {
    if (i == n) re 0;
    if (was[i][x]) re res[i][x];
    was[i][x] = 1;
    res[i][x] = 1e9;
    if (a[i] >= x && a[i] <= 2011 && go (i + 1, a[i]) < res[i][x]) {
        res[i][x] = go (i + 1, a[i]);
        next[i][x] = a[i];
    }
    for (int j = 0; j < 4; j++)
        for (int k = 0; k < 10; k++) {
            int y = a[i] - p10[j] * get (a[i], j) + p10[j] * k;
            if (y >= x && y <= 2011 && go (i + 1, y) + 1 < res[i][x]) {
                res[i][x] = go (i + 1, y) + 1;
                next[i][x] = y;
            }
        }
    re res[i][x];
}

int out (int i, int x) {
    if (i > 0) printf ("%d\n", x);
    if (i < n) out (i + 1, next[i][x]);
    re 0;
}

int main() {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%d", &a[i]);
    if (go (0, 1000) > 10000) printf ("No solution\n"); else out (0, 1000);
    return 0;
}