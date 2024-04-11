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
#define prev PREV
                         
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
char res[101][101];

int main () {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int di = -n + 1; di <= n - 1; di++)
        for (int dj = -n + 1; dj <= n - 1; dj++) {
            res[di + n - 1][dj + n - 1] = '.';
            int bad = 0;
            for (int i = max (-di, 0); i < min (n - di, n) && !bad; i++)
                for (int j = max (-dj, 0); j < min (n - dj, n) && !bad; j++)
                    if (s[i][j] == 'o' && s[i + di][j + dj] == '.')
                        bad = 1;
            if (!bad) {
                for (int i = max (-di, 0); i < min (n - di, n); i++)
                    for (int j = max (-dj, 0); j < min (n - dj, n); j++)
                        if (s[i][j] == 'o' && s[i + di][j + dj] == 'x')
                            s[i + di][j + dj] = '#';
                res[di + n - 1][dj + n - 1] = 'x';
            }
        }
    res[n - 1][n - 1] = 'o';
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (s[i][j] == 'x') {
                printf ("NO\n");
                re 0;
            }
    printf ("YES\n");
    for (int i = 0; i < 2 * n - 1; i++) {
        for (int j = 0; j < 2 * n - 1; j++)
            printf ("%c", res[i][j]);
        printf ("\n");
    }
    return 0;
}