#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> a;
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            if(s[i] == '*') {
                a.push_back(cnt);
                cnt = 0;
            } else {
                ++cnt;
            }
        }
        if(a.empty()) {
            cout << 0 << '\n';
            continue;
        }
        a.erase(a.begin());
        ll ans = 0;
        for(int i = 0; i < a.size(); ++i) {
            ans += min(i, (int)a.size() - 1 - i) * a[i] + a[i];
        }
        cout << ans << '\n';
    }
}