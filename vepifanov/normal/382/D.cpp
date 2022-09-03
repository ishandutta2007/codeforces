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
int was[2000][2000];
int d[2000][2000];
string s[2000];
int bad = 0;

int calc (int i, int j) {
    if (s[i][j] == '#') re 0;
    if (was[i][j] == 1) bad = 1;
    if (was[i][j]) re d[i][j];
    was[i][j] = 1;
    d[i][j] = calc (i - int (s[i][j] == '^') + int (s[i][j] == 'v'), j - int (s[i][j] == '<') + int (s[i][j] == '>')) + 1;
    was[i][j] = 2;
    re d[i][j];
}

int go (int i, int j) {
    if (s[i][j] == '#') re 1;
    if (was[i][j]) re 0;
    was[i][j] = 1;
    re go (i - int (s[i][j] == '^') + int (s[i][j] == 'v'), j - int (s[i][j] == '<') + int (s[i][j] == '>'));
}

int main () {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> s[i];
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ans = max (ans, d[i][j] = calc (i, j));
    int ok = 0;
    memset (was, 0, sizeof (was));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (d[i][j] == ans)
                ok += go (i, j);
    ans *= 2;
    if (ok < 2 && ans > 0) ans--;
    if (bad) ans = -1;
    printf ("%d\n", ans);
    return 0;
}