#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair<int, int> ii;
typedef long long ll;
typedef pair<ll, ll> pll;
 
#define X first
#define Y second
 
const int N = 5e5 + 10;
const ll MOD = 1e9 + 7;
 
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll BASE = (rng() % (MOD - 1000100)) + 1000100;
 
int n, a[N];
 
map<ll, int> ma[N];
ll s[2][N];
ll DP(int L, int R) {
    if (L == R) return 0;
 
    int cen = (L + R) / 2;


    for(int i = 0; i <= R - L + 1; i++) 
        ma[i].clear();
 
    ll ans = 0;
 
    int top = 0;
    s[0][0] = -1;
    for(int i = cen; i >= L; i--) {
        if (a[i] == s[0][top]) {
            top--;
        } else {
            s[0][++top] = a[i];
            s[1][top] = (s[1][top - 1] * BASE + a[i]) % MOD;
        }
        ma[top][(s[1][top] * BASE + n + 1) % MOD]++;
    }
    top = 0;
    for(int i = cen + 1; i <= R; i++) {
        if (a[i] == s[0][top]) {
            top--;
        } else {
            s[0][++top] = a[i];
            s[1][top] = (s[1][top - 1] * BASE + a[i]) % MOD;
        }
        ans += ma[top][(s[1][top] * BASE + n + 1) % MOD];
    }
 
    ans += DP(L, cen);
    ans += DP(cen + 1, R);
    return ans;
 
}
ll solve() {
    return DP(1, n);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int test;
 
    cin >> test;
    while (test--) {
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
 
        cout << solve() << '\n';
    }
 
}