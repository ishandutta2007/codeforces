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
int x[10], y[10];
string s, t;

int main () {
    cin >> s >> t;
    for (int i = 0; i < sz (s); i++) x[s[i] - '0']++;
    for (int i = 0; i < sz (t); i++) y[t[i] - '0']++;
    int ans = 1e9;
    if (x[0] != 0) ans = min (ans, y[0] / x[0]);
    if (x[1] != 0) ans = min (ans, y[1] / x[1]);
    if (x[2] + x[5] != 0) ans = min (ans, (y[2] + y[5]) / (x[2] + x[5]));
    if (x[3] != 0) ans = min (ans, y[3] / x[3]);
    if (x[4] != 0) ans = min (ans, y[4] / x[4]);
    if (x[6] + x[9] != 0) ans = min (ans, (y[6] + y[9]) / (x[6] + x[9]));
    if (x[7] != 0) ans = min (ans, y[7] / x[7]);
    if (x[8] != 0) ans = min (ans, y[8] / x[8]);
    printf ("%d\n", ans);
    return 0;
}