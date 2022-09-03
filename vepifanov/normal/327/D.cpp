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
vector<pair<char, ii> > res;
string s[500];

int go (int i, int j, int f) {
    if (i < 0 || j < 0 || i >= n || j >= m || s[i][j] == '#') re 0;
    s[i][j] = '#';
    res.pb (mp ('B', mp (i + 1, j + 1)));
    for (int t = 0; t < 4; t++) {
        int ni = i - int (t == 0) + int (t == 1);
        int nj = j - int (t == 2) + int (t == 3);
        go (ni, nj, 1);
    }
    if (f) {
        res.pb (mp ('D', mp (i + 1, j + 1)));
        res.pb (mp ('R', mp (i + 1, j + 1)));
    }   
    re 0;
}

int main () {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            go (i, j, 0);
    printf ("%d\n", sz (res));
    for (int i = 0; i < sz (res); i++)
        printf ("%c %d %d\n", res[i].fi, res[i].se.fi, res[i].se.se);
    return 0;
}