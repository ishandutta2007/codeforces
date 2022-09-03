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

const int mod = 1e9 + 7;

int n;
int m;
int k, d;
int was[101][2];
int res[101][2];

int go (int n, int f) {
    if (n < 0) re 0;
    if (n == 0) re f;
    if (was[n][f]) re res[n][f];
    was[n][f] = 1;
    int cur = 0;
    for (int t = 1; t <= k; t++)
        cur = (cur + go (n - t, f | int (t >= d))) % mod;
    re res[n][f] = cur;
}

int main () {
    scanf ("%d%d%d", &n, &k, &d);
    printf ("%d\n", go (n, 0));
    return 0;
}