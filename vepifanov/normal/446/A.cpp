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
#include <cassert>

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
#define j0 j1347829
#define j1 j234892
                         
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
int res[100002][2];
int x[100002];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
    int ans = min (2, n), cur = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int t = 0; t < 2; t++) {
            res[i][t] = 1;
            if (i + 1 < n && x[i] < x[i + 1]) res[i][t] += res[i + 1][t]; 
        }   
        if (i + 2 < n && x[i] + 2 <= x[i + 2]) res[i][1] = max (res[i][1], res[i + 2][0] + 2);
        ans = max (ans, max (res[i][0], res[i][1]));
        cur = max (cur, res[i][0]);
    }
    if (cur < n) cur++;
    ans = max (ans, cur);
    printf ("%d\n", ans);
    return 0;
}