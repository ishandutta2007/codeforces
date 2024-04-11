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
string s[2000];
int g[2001][2001];

int main () {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> s[i];
    int i1 = n, i2 = 0, j1 = m, j2 = 0;
    int rem = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (s[i][j] == 'w') {
                g[i][j] = 1;
                rem++;
                i1 = min (i1, i);
                i2 = max (i2, i);
                j1 = min (j1, j);
                j2 = max (j2, j);
            }
    for (int i = n - 1; i >= 0; i--)
        for (int j = m - 1; j >= 0; j--)
            g[i][j] += g[i + 1][j] + g[i][j + 1] - g[i + 1][j + 1];
    int k = max (i2 - i1, j2 - j1);
    for (int i = 0; i + k < n; i++)
        for (int j = 0; j + k < m; j++) {
            int tmp = g[i][j] - g[i + k + 1][j] - g[i][j + k + 1] + g[i + k + 1][j + k + 1];
            if (k > 1) tmp -= g[i + 1][j + 1] - g[i + k][j + 1] - g[i + 1][j + k] + g[i + k][j + k];
            if (tmp == rem) {
                for (int a = 0; a <= k; a++)
                    for (int b = 0; b <= k; b++)
                        if (k == 0 || (a % k == 0 || b % k == 0))
                            if (s[a + i][b + j] != 'w')
                                s[a + i][b + j] = '+';
                for (int a = 0; a < n; a++) printf ("%s\n", s[a].c_str ());
                re 0;
            }
        }   
    printf ("-1\n");
    return 0;
}