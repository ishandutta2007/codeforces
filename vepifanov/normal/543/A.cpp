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

int n;
int m;
int b;
int mod;

int x[500];
int res[501][501];

int main () {
    scanf ("%d%d%d%d", &n, &m, &b, &mod);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    memset (res, 0, sizeof (res));
    res[0][0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k + x[i] <= b; k++)
                (res[j + 1][k + x[i]] += res[j][k]) %= mod;
    int ans = 0;
    for (int i = 0; i <= b; i++)
        (ans += res[m][i]) %= mod;
    printf ("%d\n", ans);
    return 0;
}