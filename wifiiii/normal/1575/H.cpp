#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 505;
int f[maxn], nxt[maxn][2];
void getf(string s) {
    f[0] = 0;
    for(int i=1;i<s.size();++i) {
        int j = f[i-1];
        while(j && s[i] != s[j]) j = f[j-1];
        if(s[i] == s[j]) f[i] = j + 1;
        else f[i] = 0;
    }
    for(int i=0;i<s.size();++i) {
        for(int j=0;j<2;++j) {
            int tmp=i;
            while(tmp && s[tmp]-'0'!=j) tmp=f[tmp-1];
            if(s[tmp]-'0'==j) nxt[i][j]=tmp+1;
            else nxt[i][j]=0;
        }
    }
}
int dp[maxn][maxn][maxn];
void cmin(int &a, int b) {
    a = min(a, b);
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    getf(t);
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0][0] = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= i; ++j) {
            for(int k = 0; k < m; ++k) {
                if(dp[i][j][k] >= 1e9) continue;
                cmin(dp[i + 1][j + (nxt[k][0] == m)][(nxt[k][0] == m ? f[k] : nxt[k][0])], dp[i][j][k] + (s[i] != '0'));
                cmin(dp[i + 1][j + (nxt[k][1] == m)][(nxt[k][1] == m ? f[k] : nxt[k][1])], dp[i][j][k] + (s[i] != '1'));
            }
        }
    }
    vector<int> ans(n + 1, 1e9);
    for(int j = 0; j <= n; ++j) {
        for(int k = 0; k < t.size(); ++k) {
            ans[j] = min(ans[j], dp[n][j][k]);
        }
    }
    for(int i = 0; i < n - m + 2; ++i) {
        if(ans[i] >= 1e9) cout << -1 << " ";
        else cout << ans[i] << " ";
    }
    cout << endl;
}