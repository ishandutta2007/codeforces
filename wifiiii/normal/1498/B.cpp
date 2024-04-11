#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, w;
        cin >> n >> w;
        vector<int> cnt(25);
        for(int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            cnt[31 - __builtin_clz(x)]++;
        }
        int ans = 0;
        int f = 1;
        while(f) {
            f = 0;
            int res = w;
            for(int i = 20; i >= 0; --i) {
                while(cnt[i] && res >= 1 << i) {
                    f = 1;
                    --cnt[i];
                    res -= 1 << i;
                }
            }
            ++ans;
        }
        cout << ans - 1 << endl;
    }
}