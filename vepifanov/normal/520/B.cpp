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
int was[10001];
int d[10001];
int q[10001];

int main () {
    cin >> n >> m;
    int ans = 1e9, l = 0, r = 1;
    q[0] = n;
    was[n] = 1;
    while (l < r) {
        int x = q[l++];
        if (x > 1 && !was[x - 1]) {
            was[x - 1] = 1;
            d[x - 1] = d[x] + 1;
            q[r++] = x - 1;
        }
        if (x * 2 <= m && !was[x * 2]) {
            was[x * 2] = 1;
            d[x * 2] = d[x] + 1;
            q[r++] = x * 2;
        } else 
        if (x * 2 > m)
            ans = min (ans, d[x] + 1 + (x * 2 - m));
    }
    if (was[m]) ans = min (ans, d[m]);
    printf ("%d\n", ans);
    return 0;
}