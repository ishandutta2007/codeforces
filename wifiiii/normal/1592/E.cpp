#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    vector<int> h(n);
    vector<vector<int>> pre(2, vector<int>(1 << 20, -2));
    for(int i = 19; i >= 0; --i) {
        vector<int> nh(n);
        int lst = -1, cur = 0;
        for(int j = 0; j < n; ++j) {
            cur ^= a[j] >> i & 1;
            nh[j] = h[j] * 2 + cur;
            if(a[j] >> i & 1) {
                if(pre[1 ^ (j & 1)][h[j]] != -2) {
                    ans = max(ans, j - pre[1 ^ (j & 1)][h[j]] + 1);
                }
                if(pre[j & 1][j ? h[j - 1] : 0] == -2) {
                    pre[j & 1][j ? h[j - 1] : 0] = j;
                }
            } else {
                for(int k = lst + 1; k < j; ++k) {
                    pre[k & 1][k ? h[k - 1] : 0] = -2;
                }
                lst = j;
            }
        }
        for(int k = lst + 1; k < n; ++k) {
            pre[k & 1][k ? h[k - 1] : 0] = -2;
        }
        h = nh;
    }
    cout << ans << '\n';
}