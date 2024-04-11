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
string s[2];
int was[2][200000];
int d[2][200000];
ii q[400000];

int main () {
    cin >> n >> m;
    cin >> s[0] >> s[1];
    int l = 0, r = 1;
    q[0] = mp (0, 0);
    was[0][0] = 1;
    while (l < r) {
        int i = q[l].fi;
        int j = q[l].se;
        if (j >= n) {
            printf ("YES\n");
            re 0;
        }
        l++;
        if (d[i][j] <= j && s[i][j] == '-') {
            if (j > 0 && !was[i][j - 1]) {
                was[i][j - 1] = 1;
                d[i][j - 1] = d[i][j] + 1;
                q[r++] = mp (i, j - 1);
            }
            if (!was[i][j + 1]) {
                was[i][j + 1] = 1;
                d[i][j + 1] = d[i][j] + 1;
                q[r++] = mp (i, j + 1);
            }
            if (!was[1 - i][j + m]) {
                was[1 - i][j + m] = 1;
                d[1 - i][j + m] = d[i][j] + 1;
                q[r++] = mp (1 - i, j + m);
            }
        }
    }
    printf ("NO\n");
    return 0;
}