#include <cstdio>
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

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
    re x > 0 ? x : -x;
}

int n;
int m;
int sa[100001], sb[100001], a[100001], b[100001], can[100001];

int main() {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf ("%d", &b[i]);
    sa[n] = sb[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        sa[i] = sa[i + 1] + a[i];
        sb[i] = sb[i + 1] + b[i];
    }
    memset (can, 0, sizeof (can));
    int res = 2e9, ri = 0;
    for (int i = 0; i < n; i++) {
        int cur = sb[i + 1] - sa[i + 1];
        if (cur < res) {
            res = cur;
            ri = i;
        }
    }
    for (int i = 0; i < n; i++) {
        int tmp;
        if (i <= ri) tmp = (sa[i] - sa[ri + 1]) - (sb[i] - sb[ri + 1]); else tmp = (sb[ri + 1] - sb[i]) - (sa[ri + 1] - sa[i]);
        if (tmp >= 0) can[i] = 1;
    }
    res = 2e9; ri = 0;
    for (int i = 0; i < n; i++) {
        int cur = (sa[i + 1] + a[0]) - sb[i];
        if (cur < res) {
            res = cur;
            ri = i;
        }
    }
    for (int i = 0; i < n; i++) {
        int tmp;
        if (i < ri) tmp = (sa[0] - sa[i + 1] + sa[ri + 1]) - (sb[0] - sb[i] + sb[ri]); else tmp = (sa[ri + 1] - sa[i + 1]) - (sb[ri] - sb[i]);
        if (tmp >= 0) can[i] = 1;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) ans += can[i];
    printf ("%d\n", ans);
    for (int i = 0; i < n; i++) 
        if (can[i]) printf ("%d ", i + 1);
    printf ("\n");
    return 0;
}