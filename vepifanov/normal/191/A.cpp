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
ii g[500000];
int res[26];
int w[500000];

int main () {
    scanf ("%d\n", &n);
    for (int i = 0; i < n; i++) {
        char s[15];
        scanf ("%s\n", s);
        int m = strlen (s);
        g[i].fi = s[0] - 'a';
        g[i].se = s[m - 1] - 'a';
        w[i] = m;
    }
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) res[j] = -1e9;
        res[i] = 0;
        for (int j = 0; j < n; j++) {
            res[g[j].se] = max (res[g[j].se], res[g[j].fi] + w[j]);
            if (g[j].se == i) ans = max (ans, res[g[j].se]);
        }
    }
    printf ("%d\n", ans);
    return 0;
}