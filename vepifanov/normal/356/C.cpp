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

const int inf = 1e9;

int n;
int m;
int cnt[5];

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf ("%d", &x);
        cnt[x]++;
    }
    int ans = inf;
    if (2 * cnt[2] + cnt[1] <= cnt[3]) ans = min (ans, 2 * cnt[2] + cnt[1]);
    for (int t = 1; t <= cnt[2]; t++)
        if (2 * (cnt[2] - t) + cnt[1] <= 2 * t + cnt[3] && 2 * (cnt[2] - t) + cnt[1] + cnt[4] >= t)
            ans = min (ans, max (t, 2 * (cnt[2] - t) + cnt[1]));
    for (int t = 1; t <= cnt[1]; t++)
        if (cnt[1] - t <= 3 * t + 2 * cnt[2] + cnt[3] && cnt[1] - t + cnt[4] >= cnt[2] + 2 * t)
            ans = min (ans, max (cnt[2] + 2 * t, cnt[1] - t));
    if (ans == inf) ans = -1;
    printf ("%d\n", ans);
    return 0;
}