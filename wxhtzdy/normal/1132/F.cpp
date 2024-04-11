#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 1234567
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b)  {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 505;
char s[maxn];
int dp[maxn][maxn];
bool was[maxn][maxn];
int solve(int l, int r) {
    if (was[l][r]) return dp[l][r];
    was[l][r] = true;
    if (l > r) return dp[l][r] = 0;
    if (l == r) return dp[l][r] = 1;
    dp[l][r] = solve(l + 1, r) + 1;
    for (int i = l + 1; i <= r; i++) {
        if (s[l] == s[i]) {
            chkmin(dp[l][r], solve(l + 1, i - 1) + solve(i, r));
        }
    }
    return dp[l][r];
}
int main() {
    int n; scanf("%d %s", &n, s);
    printf("%d\n", solve(0, n - 1));
    return 0;
}