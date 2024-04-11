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
int f[1 << 12];

ii go (int x) {
    if (2 * x >= m) re mp (0, 0);
    ii a = go (2 * x);
    ii b = go (2 * x + 1);
    a.se += f[2 * x];
    b.se += f[2 * x + 1];
    ii res;
    res.fi = a.fi + b.fi + abs (a.se - b.se);
    res.se = max (a.se, b.se);
    re res;
}

int main () {
    scanf ("%d", &n); n++;
    m = 1 << n;
    for (int i = 2; i < m; i++)
        scanf ("%d", &f[i]);
    ii res = go (1);
    printf ("%d\n", res.fi);
    return 0;
}