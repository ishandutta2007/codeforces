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

const int inf = 1e9;

int n;
int m;
int a[3000];
int b[3000];
int c[3000];
int res[3001][4];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf ("%d", &b[i]);
    for (int i = 0; i < n; i++) scanf ("%d", &c[i]);
    res[0][0] = res[0][1] = -inf;
    res[0][2] = res[0][3] = 0;
    for (int i = 0; i < n; i++) {
        res[i + 1][0] = max (res[i][2], res[i][3]) + a[i];
        res[i + 1][1] = max (res[i][0], res[i][1]) + b[i];
        res[i + 1][2] = max (res[i][0], res[i][1]) + c[i];
        res[i + 1][3] = max (res[i][2], res[i][3]) + b[i];
    }
    printf ("%d\n", max (res[n][0], res[n][1]));
    return 0;
}