#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <sstream>
#include <cmath>
#include <ctime>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forv(i, v) forn(i, v.size())
#define all(v) v.begin(), v.end()
#define mp make_pair

const int MAXN = 1e6 + 100;

int sf[MAXN];
int n;
vector<int> a;
int dp[MAXN];

void rec(const vector<int>& d, const vector<int>& p, int pos, int val, int n, int& upd) {
    if (pos == (int)d.size()) {
        if (val < n) upd = max(upd, dp[val] + 1);
        return;
    }
    forn(i, p[pos] + 1) {
        rec(d, p, pos + 1, val, n, upd);
        val *= d[pos];
    }
}

int main() {
#ifdef NEREVAR_PROJECT
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n;
    a = vector<int>(n);
    forn(i, n) scanf("%d", &a[i]);
    forn(i, MAXN) sf[i] = i;
    for (int i = 2; i < MAXN; i++) {
        if (sf[i] == i) {
            for (int j = i + i; j < MAXN; j += i) {
                sf[j] = min(sf[j], i);
            }
        }
    }
    int ans = 0;
    forn(i, n) {
        vector<int> d, p;
        int x = a[i];
        while (x > 1) {
            int c = 0;
            int f = sf[x];
            while (x % f == 0) {
                c++;
                x /= f;
            }
            d.push_back(f);
            p.push_back(c);
        }
        dp[a[i]] = 1;
        rec(d, p, 0, 1, a[i], dp[a[i]]);
        ans = max(ans, dp[a[i]]);
        //cerr << a[i] << " " << dp[a[i]] << endl;
    }
    cout << ans << endl;
    return 0;
}