#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int p = -1, ans = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '0') {
                if(p != -1) {
                    ans += max(0, 3 - (i - p));
                }
                p = i;
            }
        }
        cout << ans << '\n';
    }
}