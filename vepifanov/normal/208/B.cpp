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
string s[56];
int was[55][55][55][55];

int can (string a, string b) {
    re int (a[0] == b[0] || a[1] == b[1]);
}

int go (int i, int a, int b, int c) {
    if (i + 1 == n) re 1;
    if (was[i][a][b][c]) re 0;
    was[i][a][b][c] = 1;
    int d = i + 3;
    if (can (s[a], s[b]) && go (i + 1, a, c, d)) re 1;
    if (can (s[a], s[d]) && go (i + 1, b, c, a)) re 1;
    re 0;
}

int main () {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    reverse (s, s + n);
    s[n] = s[n + 1] = s[n + 2] = s[n + 3] = "??";
    if (go (0, 0, 1, 2)) printf ("YES\n"); else printf ("NO\n");
    return 0;
}