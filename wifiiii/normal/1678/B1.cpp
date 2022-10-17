#include "bits/stdc++.h"
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
        vector<int> a;
        for(int i = 0, j = 0; i < n; i = j) {
            while(j < n && s[i] == s[j]) ++j;
            a.push_back(j - i);
        }
        vector<int> b(a.size());
        int ans = 0;
        for(int i = 0; i < a.size(); ++i) {
            if((a[i] + b[i]) % 2 == 1) {
                b[i + 1] = 1;
                ans += 1;
            }
        }
        cout << ans << '\n';
    }
}