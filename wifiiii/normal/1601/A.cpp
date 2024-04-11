#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        vector<int> ans(n + 1);
        int tot = 0;
        for(int i = 0; i < 30; ++i) {
            int cnt = 0;
            for(int j = 0; j < n; ++j) {
                if(a[j] >> i & 1) ++cnt;
            }
            if(cnt) ++tot;
            for(int j = 1; j * j <= cnt; ++j) {
                if(cnt % j == 0) {
                    ans[j] += 1;
                    if(j * j != cnt) ans[cnt / j] += 1;
                }
            }
        }
        for(int i = 1; i <= n; ++i) if(ans[i] == tot) cout << i << " ";
        cout << endl;
    }
}