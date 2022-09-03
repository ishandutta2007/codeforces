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
string s[50];
int was[50][50][4][3];
int use[50][50];

int go (int i, int j, int d, int s) {
    if (i < 0 || j < 0 || i >= n || j >= m || ::s[i][j] == 'W' || s > 2 || was[i][j][d][s]) re 0;
    was[i][j][d][s] = 1;
    int cur = 1 - use[i][j];
    use[i][j] = 1;
    re cur + go (i - 1, j, 0, s + int (d != 0)) + go (i, j - 1, 1, s + int (d != 1)) + go (i + 1, j, 2, s + int (d != 2)) + go (i, j + 1, 3, s + int (d != 3));
}

int main () {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> s[i];
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (s[i][j] == 'B')
                cnt++;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (s[i][j] == 'B') {
                memset (was, 0, sizeof (was));
                memset (use, 0, sizeof (use));
                if (go (i, j, -1, 0) != cnt) {
                    printf ("NO\n");
                    re 0;
                }
            }
    printf ("YES\n");
    return 0;
}