#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, c;
        cin >> n >> c;
        vector<int> cnt(c + 1);
        for(int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            cnt[x] += 1;
        }
        for(int i = 1; i <= c; ++i) cnt[i] += cnt[i - 1];
        int ok = cnt[1] > 0;
        for(int i = 1; i <= c; ++i) {
            if(cnt[i] == cnt[i - 1]) continue;
            for(int j = 1; i * j <= c; ++j) {
                int l = i * j, r = min(c, i * j + i - 1);
                if(cnt[r] != cnt[l - 1]) {
                    if(cnt[j] == cnt[j - 1]) ok = 0;
                }
            }
        }
        cout << (ok ? "Yes" : "No") << '\n';
    }
}