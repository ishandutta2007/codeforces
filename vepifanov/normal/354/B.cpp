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
char was[40][1 << 20];
signed char res[40][1 << 20];

int w[40][20][26];
int g[20][20];
string s[20];

int go (int d, int mask) {
    if (d == 2 * n - 2) re 0;
    if (was[d][mask]) re res[d][mask];
    was[d][mask] = 1;
    int cur = 1e9;
    if (d & 1) cur = -1e9;
    for (int c = 0; c < 26; c++) {
        int nmask = 0;
        for (int i = 0; i < n; i++)
            if ((mask >> i) & 1)
                nmask |= w[d][i][c];
        if (nmask != 0) {
            int tmp = go (d + 1, nmask) + int (c == 0) - int (c == 1);
            if (d & 1) cur = max (cur, tmp); else cur = min (cur, tmp);
        }
    }
    re res[d][mask] = cur;
}

int main () {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i][j] = s[i][j] - 'a';
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int c = 0; c < 26; c++)
                for (int t = 0; t < 2; t++) {
                    int ni = i + int (t == 0), nj = j + int (t == 1);
                    if (ni < n && nj < n && g[ni][nj] == c)
                        w[i + j][i][c] |= (1 << ni);
                }
    int cur = go (0, 1) + int (g[0][0] == 0) - int (g[0][0] == 1);
    if (cur > 0) printf ("FIRST\n"); else
    if (cur < 0) printf ("SECOND\n"); else printf ("DRAW\n");
    return 0;
}