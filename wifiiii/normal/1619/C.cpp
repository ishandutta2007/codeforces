#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string a, b;
        cin >> a >> b;
        string ans;
        int p = b.size() - 1, ok = 1;
        for(int i = a.size() - 1; i >= 0; --i) {
            if(p < 0) {
                ok = 0;
                break;
            }
            int x = a[i] - '0', y = b[p] - '0';
            if(y < x) {
                if(!p || b[p-1] != '1') {
                    ok = 0;
                    break;
                }
                ans += '0' + (y + 10 - x);
                p -= 2;
            } else {
                ans += '0' + (y - x);
                --p;
            }
        }
        while(p >= 0) {
            ans += b[p--];
        }
        if(!ok) cout << -1 << '\n';
        else {
            while(!ans.empty() && ans.back() == '0') ans.pop_back();
            if(ans.empty()) cout << -1 << '\n';
            else {
                reverse(ans.begin(), ans.end());
                cout << ans << '\n';
            }
        }
    }
}