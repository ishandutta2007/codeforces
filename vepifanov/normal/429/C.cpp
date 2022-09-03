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

set<int> was[25][25][3][25];
int cnt[25];
int now[25];
int x[25];

int go (int i, int rem, int f, int j) {
    if (rem == 1) {
        if (f < 2) re 0;
        if (i + 1 == n) re 1;
        now[x[i]]++;
        re go (i + 1, x[i + 1], 2 * int (x[i + 1] == 1), 1);
    }
    int ch = 0;
    for (int t = 1; t <= n; t++) ch = ch * (cnt[t] + 1) + now[t];
    if (was[i][rem][f][j].find (ch) != was[i][rem][f][j].end ()) re 0;
    if (j >= rem) re 0;
    if (now[j] > 0) {
        now[j]--;
        if (go (i, rem - j, min (2, f + 1), j)) re 1;
        now[j]++;
    }
    if (go (i, rem, f, j + 1)) re 1;
    re 0;
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &x[i]);
        cnt[x[i]]++;
    }
    sort (x, x + n);
    if (x[n - 1] == n && go (0, x[0], 2 * int (x[0] == 1), 1)) printf ("YES\n"); else printf ("NO\n");
    return 0;
}