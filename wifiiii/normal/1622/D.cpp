#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 5005;
const int mod = 998244353;
ll comb[maxn][maxn];
void init(int n) {
    for(int i=0;i<=n;++i) comb[i][0]=1;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=i;++j)
            comb[i][j]=(comb[i-1][j]+comb[i-1][j-1])%mod;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, k;
    cin >> n >> k;
    init(n);
    string s;
    cin >> s;
    if(k == 0 || count(s.begin(), s.end(), '1') < k) {
        cout << 1 << '\n';
        return 0;
    }
    vector<int> pos;
    for(int i = 0; i < n; ++i) {
        if(s[i] == '1') {
            pos.push_back(i);
        }
    }
    ll ans = 1;
    for(int i = 0; i < pos.size(); ++i) {
        int p = pos[i], l = i ? pos[i - 1] + 1 : 0, r = i + k < pos.size() ? pos[i + k] - 1 : n - 1, c = min(k, (int)pos.size() - i);
        for(int j = l; j <= r; ++j) {
            if(j == p) continue;
            ans += comb[r - j][c - 1];
        }
    }
    ans %= mod;
    cout << ans << '\n';
}