#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<string> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        int ans = 0;
        for(int i = 0; i < 5; ++i) {
            vector<int> b;
            for(int j = 0; j < n; ++j) {
                int cnt = 0;
                for(char c : a[j]) {
                    if(c - 'a' == i) cnt++;
                    else cnt--;
                }
                b.push_back(cnt);
            }
            sort(b.begin(), b.end());
            reverse(b.begin(), b.end());
            int cnt = 0, cur = 0;
            for(int j : b) {
                cur += j;
                if(cur <= 0) break;
                cnt++;
            }
            ans = max(ans, cnt);
        }
        cout << ans << '\n';
    }
}