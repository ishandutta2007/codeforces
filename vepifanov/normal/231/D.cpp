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
int m, x, y, z, xx, yy, zz, a1, a2, a3, a4, a5, a6;

int main () {
    cin >> x >> y >> z >> xx >> yy >> zz >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
    int ans = 0;
    if (y < 0) ans += a1;
    if (y > yy) ans += a2;
    if (z < 0) ans += a3;
    if (z > zz) ans += a4;
    if (x < 0) ans += a5;
    if (x > xx) ans += a6;
    printf ("%d\n", ans);
    return 0;
}