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

const string pat = "DIMA";

const int inf = 1e9;

int n;
int m;
int was[1000][1000][4];
int res[1000][1000][4];
string s[1000];

int go (int i, int j, int k) {
    if (i < 0 || j < 0 || i >= n || j >= m || s[i][j] != pat[k]) re -inf;
    if (was[i][j][k] == 1) re inf;
    if (was[i][j][k] == 2) re res[i][j][k];
    was[i][j][k] = 1;
    int cur = 1;
    for (int t = 0; t < 4; t++) {
        int ni = i + int (t == 0) - int (t == 1);
        int nj = j + int (t == 2) - int (t == 3);
        cur = max (cur, go (ni, nj, (k + 1) % 4) + 1);
    }
    was[i][j][k] = 2;
    res[i][j][k] = cur;
    re cur;
}

int main () {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> s[i];
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ans = max (ans, go (i, j, 0));
    if (ans >= inf) printf ("Poor Inna!\n"); else
    if (ans < 4) printf ("Poor Dima!\n"); else printf ("%d\n", ans / 4);
    return 0;
}