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

const int mod = 1000000000 + 7;

int n;
int m;
int was[700][700][2][2], res[700][700][2][2];
int p[700], q[700];
string s;

int go (int i, int j, int a, int b) {
    if (i >= j) re 1;
    if (was[i][j][a][b]) re res[i][j][a][b];
    was[i][j][a][b] = 1;
    if (a) res[i][j][a][b] = ((ll)go (i + 1, p[i] - 1, 1, 0) * go (p[i] + 1, j, 0, 0) + (ll)2 * go (i + 1, p[i] - 1, 0, 1) * go (p[i] + 1, j, 1, 0)) % mod; else
    if (b) res[i][j][a][b] = ((ll)go (i, p[j] - 1, 0, 0) * go (p[j] + 1, j - 1, 0, 1) + (ll)2 * go (i, p[j] - 1, 0, 1) * go (p[j] + 1, j - 1, 1, 0)) % mod; else
    res[i][j][a][b] = ((ll)2 * go (i, p[j] - 1, 0, 0) * go (p[j] + 1, j - 1, 0, 1) + (ll)2 * go (i, p[j] - 1, 0, 1) * go (p[j] + 1, j - 1, 1, 0)) % mod;
    re res[i][j][a][b];
}

int main () {
    cin >> s;
    int r = 0;
    for (int i = 0; i < sz (s); i++)
        if (s[i] == '(')
            q[r++] = i;
        else {
            p[q[--r]] = i;
            p[i] = q[r];
        }   
    printf ("%d\n", go (0, sz (s) - 1, 0, 0));
    return 0;
}