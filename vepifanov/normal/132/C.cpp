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

string s;

int was[101][101][2];
ii res[101][101][2];

ii go (int i, int j, int d) {
    if (i == m) 
        if (j % 2 == 0)
            re mp (0, 0);
        else
            re mp (-10000, -10000); 
    if (was[i][j][d]) re res[i][j][d];
    was[i][j][d] = 1;
    ii res = mp (-10000, -10000), tmp;
    if (j - int (s[i] != 'T') >= 0) {
        tmp = go (i + 1, j - int (s[i] != 'T'), d ^ 1);
        res.fi = max (res.fi, tmp.fi);
        res.se = max (res.se, tmp.se);
    }
    if (j - int (s[i] != 'F') >= 0) {
        tmp = go (i + 1, j - int (s[i] != 'F'), d);
        if (d) { tmp.fi++; tmp.se--; } else { tmp.fi--; tmp.se++; }
        res.fi = max (res.fi, tmp.fi);
        res.se = max (res.se, tmp.se);
    }
    re ::res[i][j][d] = res;
}

int main () {
    cin >> s >> n;
    m = sz (s);
    ii res = go (0, n, 0);
    printf ("%d\n", max (res.fi, res.se));
    return 0;
}