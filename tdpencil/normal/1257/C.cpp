#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define f first
#define s second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main() {
    // first brute force over every rectangle    
    int tt; cin >> tt;

    while(tt--) {
        int n; cin >> n;
        vector<int> a(n);
        for(auto &i : a)
            cin >> i;

        vector<vector<int>> c(n + 1);
        for(int i = 0; i < n; ++i)
            c[a[i]].push_back(i);
        int ans=2e9;
        for(int i = 0; i <= n; ++i) {
            for(int j = 1; j < sz(c[i]); ++j) {
                ans=min(ans,c[i][j]-c[i][j-1]+1);
            }
        }
        cout << (ans==int(2e9)?-1:ans) << "\n";
    }

}