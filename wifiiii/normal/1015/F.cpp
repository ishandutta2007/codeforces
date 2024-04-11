#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define al(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pc(x) __builtin_popcount(x)
#define pb push_back

// dp[n][j][k]: already put 1 to n, prefix sum = j, current match position = k (n <= 200, j <= 100, k <= 200)
const int mod = 1e9+7;
ll dp[205][105][205];
const int maxn = 205;
int f[maxn], nxt[maxn][2], mp[256];
void getf(string s) {
    for(char &c : s) c = mp[c];
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
            while(tmp && s[tmp]!=j) tmp=f[tmp-1];
            if(s[tmp]==j) nxt[i][j]=tmp+1;
            else nxt[i][j]=0;
        }
    }
}
int main() {
    mp['('] = 0, mp[')'] = 1;
    int n;
    cin >> n;
    string s;
    cin >> s;
    getf(s);
    dp[0][0][0] = 1;
    for(int i=0;i<2*n;++i) {
        for(int j=0;j<=n;++j) {
            for(int k=0;k<s.size();++k) {
                if(!dp[i][j][k]) continue;
                // put (
                int nxt_j = j + 1, nxt_k = nxt[k][0];
                (dp[i+1][nxt_j][nxt_k] += dp[i][j][k]) %= mod;
                // put ')
                nxt_j = j - 1, nxt_k = nxt[k][1];
                if(nxt_j >= 0) (dp[i+1][nxt_j][nxt_k] += dp[i][j][k]) %= mod;
            }
            // k == s.size()
            (dp[i+1][j+1][s.size()] += dp[i][j][s.size()]) %= mod;
            if(j - 1 >= 0) (dp[i+1][j-1][s.size()] += dp[i][j][s.size()]) %= mod;
        }
    }
    cout << dp[2*n][0][s.size()] << endl;
}