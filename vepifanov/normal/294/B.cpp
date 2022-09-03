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
vi v[2];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf ("%d%d", &a, &b);
        v[a - 1].pb (b);
    }
    sort (all (v[0]));
    sort (all (v[1]));
    int ans = 1e9;
    for (int a = 0; a <= sz (v[0]); a++)
        for (int b = 0; b <= sz (v[1]); b++) {
            int x = 0, y = sz (v[0]) - a + (sz (v[1]) - b) * 2;
            for (int t = 0; t < a; t++) x += v[0][t];
            for (int t = 0; t < b; t++) x += v[1][t];
            if (x <= y) ans = min (ans, y);
        }
    printf ("%d\n", ans);
    return 0;
}