#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        if(k & 1) for(char &c : s) c ^= 1;
        vector<int> a(n);
        for(int i = 0; i + 1 < n; ++i) {
            if(s[i] == '0' && k) a[i] = 1, --k;
        }
        a.back() = k;
        for(int i = 0; i < n; ++i) {
            if(a[i] & 1) s[i] ^= 1;
            cout << s[i];
        }
        cout << '\n';
        for(int i : a) cout << i << ' '; cout << '\n';
    }
}