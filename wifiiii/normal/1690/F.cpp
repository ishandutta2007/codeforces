#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

vector<int> border(string s) {
    int n = s.size();
    vector<int> f(n); f[0] = 0;
    for(int i = 1; i < n; ++i) {
        int j = f[i-1];
        while(j && s[i] != s[j]) j = f[j - 1];
        if(s[i] == s[j]) f[i] = j + 1;
        else f[i] = 0;
    }
    return f;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        string s;
        cin >> n >> s;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i], --a[i];
        vector<int> vis(n);
        ll ans = 1;
        for(int i = 0; i < n; ++i) {
            if(vis[i]) continue;
            string b;
            int p = i;
            while(!vis[p]) {
                vis[p] = 1;
                b += s[p];
                p = a[p];
            }
            int x = border(b).back();
            int t = b.size();
            if(b.size() % (b.size() - x) == 0) {
                t = b.size() - x;
            }
            ans = lcm(ans, (ll)t);
        }
        cout << ans << '\n';
    }
}