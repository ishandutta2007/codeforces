#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <deque>
#include <queue>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <cassert>
#include <functional>
#include <numeric>

using namespace std;

#ifdef __WIN32__
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#ifdef __WIN32__
    #define ULLD "%I64u"
#else
    #define ULLD "%llu"
#endif

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define j0 j5743892
#define j1 j542893
                         
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<class T> T gcd(T a, T b) { re a ? gcd (b % a, a) : b; }
template<class T> T sqr(T a) { re a * a; }

#define filename ""

int n;
int m;
unordered_map<int, int> all[301];
int x[301];
int y[301];

int go (int i, int j) {
    if (i == n) re int (j != 1) * 1e9;
    if (all[i].find (j) != all[i].end ()) re all[i][j];
    re all[i][j] = min (go (i + 1, j), go (i + 1, gcd (j, x[i])) + y[i]);
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    for (int i = 0; i < n; i++) scanf ("%d", &y[i]);
    int tmp = go (0, 0);
    if (tmp > 5e8) tmp = -1;
    printf ("%d\n", tmp);
    return 0;
}