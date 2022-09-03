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
int m, k;

int res[10];

int main () {
    cin >> n >> m >> k;
    int dr = 0, dg = 0, cr = 0, cg = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        vi v;
        for (int j = 0; j < m; j++)
            if (s[j] == 'R' || s[j] == 'G')
                v.pb (j);
        if (sz (v) == 0) continue;
        if (sz (v) == 1 || sz (v) == 2 && s[v[0]] == s[v[1]]) {
            if (sz (v) < m) {
                if (s[v[0]] == 'R') cr = dr = 1; else cg = dg = 1;
            }
        } else {
            cr = cg = 1;
            int t = v[1] - v[0] - 1;
            for (int j = 0; j < 10; j++, t /= 2) (res[j] += t % 2) %= k + 1;
        }
    }
    int ok = 0;
    for (int i = 0; i < 10; i++)
        if (res[i] != 0)
            ok = 1;
    if (cg && (ok || !cr)) {
        if (dr) printf ("Draw\n"); else printf ("First\n");
    } else {
        if (dg) printf ("Draw\n"); else printf ("Second");
    }
    return 0;
}