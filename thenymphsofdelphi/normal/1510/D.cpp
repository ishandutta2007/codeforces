/*#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")*/
// only when really needed

/* GNU G++17 7.3.0: No long long for faster code
   GNU G++17 9.2.0 (64 bit, msys 2): Long long only for faster code */
 
#include <bits/stdc++.h>
  
#define for1(i,a,b) for (int i = a; i <= b; i++)
#define for2(i,a,b) for (int i = a; i >= b; i--)
#define int long long

#define sz(a) (int)a.size()
#define pii pair<int,int>
 
/*
__builtin_popcountll(x) : Number of 1-bit
__builtin_ctzll(x) : Number of trailing 0
*/
 
#define PI 3.1415926535897932384626433832795
#define INF 1000000000000000000
#define MOD 1000000007
#define MOD2 1000000009
#define EPS 1e-6

using namespace std;

int a[100005], n, d;
double lg[100005], dp[100005][10];
bool flag[100005][10];
pii pre[100005][10];

signed main() {
    
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> d;
    
    for1(i,1,n) {
        cin >> a[i];
        lg[i] = log2(a[i]);
    }
    
    flag[0][1] = true;
    
    for1(i,1,n) {
        
        for1(j,0,9) {
            dp[i][j] = dp[i - 1][j];
            pre[i][j] = {j, -1};
            flag[i][j] = flag[i - 1][j];
        }
        for1(j,0,9) if (flag[i - 1][j]) {
            if (dp[i - 1][j] + lg[i] > dp[i][j * (a[i] % 10) % 10]) {
                dp[i][j * (a[i] % 10) % 10] = dp[i - 1][j] + lg[i];
                pre[i][j * (a[i] % 10) % 10] = {j, 1};
                flag[i][j * (a[i] % 10) % 10] = true;
            }
        }
        
    }
    
    if (!flag[n][d]) cout << -1;
    else {
        
        vector<int> ans;
        int pos = d;
        for1(i,1,n) {
            auto br = pre[n - i + 1][pos];
            if (br.second == 1) ans.push_back(a[n - i + 1]);
            pos = br.first;
        }
        
        reverse(ans.begin(), ans.end());
        if (sz(ans) == 0) cout << -1;
        else {
            cout << sz(ans) << "\n";
            for (auto i : ans) cout << i << " ";
        }
        
    }
    
}