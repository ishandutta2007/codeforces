#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int maxn = 1005;
int dp[1005][1005][2][2];
int solve(int a, int b, int c, int d) {
    if(a == 0 && b == 0 && c == 0) return 0;
    if(dp[a][b][c][d] != -1) return dp[a][b][c][d];
    int res = a + 2 * b + c, ret = 1e9;
    // 1. a = a - 1
    if(a > 0) {
        ret = min(ret, res - solve(a-1,b,c,0));
    }
    // 2. b = b - 1, a = a + 1
    if(b > 0) {
        ret = min(ret, res - solve(a+1,b-1,c,0));
    }
    // 3. c = c - 1
    if(c > 0) {
        ret = min(ret, res - solve(a,b,0,0));
    }
    if(d == 0 && a > 0) {
        ret = min(ret, res - solve(a,b,c,1));
    }
    return dp[a][b][c][d] = ret;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(dp, -1, sizeof(dp));
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int a = 0, b = 0, c = 0;
        int l = 0, r = s.size() - 1;
        while(l < r) {
            if(s[l] != s[r]) a += 1;
            if(s[l] == s[r] && s[l] == '0') b += 1;
            ++l, --r;
        }
        if(l == r && s[l] == '0') c += 1;
        int alice = solve(a, b, c, 0), bob = a + c + 2 * b - alice;
        if(alice > bob) cout << "BOB" << '\n';
        else if(alice < bob) cout << "ALICE" << '\n';
        else cout << "DRAW" << '\n';
    }
}
// dp[a][b][0/1][0/1]
//
//
// 00001
//