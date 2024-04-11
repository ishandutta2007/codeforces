#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        string s;
        cin >> n >> s;
        string x = s;
        sort(x.begin(), x.end());
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            ans += s[i] != x[i];
        }
        cout << ans << '\n';
    }
}