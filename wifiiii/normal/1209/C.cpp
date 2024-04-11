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
        string s;
        cin >> s;
        string ans(n, '2');
        int pre_max = 0, pre_min_2 = 255;
        vector<int> suf_min(n);
        suf_min[n - 1] = s[n - 1];
        for(int i = n - 2; i >= 0; --i) {
            suf_min[i] = min<int>(suf_min[i + 1], s[i]);
        }
        string p;
        for(int i = 0; i < n; ++i) {
            if(s[i] >= pre_max && (i + 1 == n || s[i] <= suf_min[i + 1]) && s[i] <= pre_min_2) {
                ans[i] = '1';
                p += s[i];
                pre_max = max<int>(pre_max, s[i]);
            } else {
                pre_min_2 = min<int>(pre_min_2, s[i]);
            }
        }
        int ok = 1;
        for(int i = 0; i < n; ++i) {
            if(ans[i] == '2') {
                if(!p.empty() && s[i] < p.back()) ok = 0;
                p += s[i];
            }
        }
        if(ok) cout << ans << '\n';
        else cout << "-\n";
    }
}