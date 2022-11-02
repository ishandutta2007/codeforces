#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define piii pair <int, pii>
#define xx first
#define yy second
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
#define pis pair <int, string>
using namespace std;

const int N = 2000100, mod = 1e9 + 7;
char s[N];
LL sum[N], pos[N], dp[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    scanf ("%s", s + 1);
    LL res = 0;
    int l = strlen (s + 1);
    for (int i = 1; i <= l; i++) {
        s[i] -= 'a';
        if (!pos[s[i]]) dp[i] = (dp[i - 1] * 2 + 1) % mod;
        else dp[i] = (dp[i - 1] * 2 - dp[pos[s[i]] - 1] + mod) % mod;
        pos[s[i]] = i;
    }
    for (int i = l + 1; i <= l + n; i++) {
        int p = 0;
        for (int j = 0; j < k; j++) {
            if (!pos[j]) { p = j; break; }
            else if (pos[j] < pos[p]) p = j;
        }
        if (!pos[p]) dp[i] = (dp[i - 1] * 2 + 1) % mod;
        else dp[i] = (dp[i - 1] * 2 - dp[pos[p] - 1] + mod) % mod;
        pos[p] = i;
    }
    cout << (dp[n + l] + 1) % mod << endl;
}