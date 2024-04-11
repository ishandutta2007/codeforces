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
        int k;
        cin >> k;
        vector<int> a(26);
        for(int i = 0; i < k; ++i) {
            char c;
            cin >> c;
            a[c - 'a'] = 1;
        }
        int p = 0, ret = 0;
        for(int i = 0; i < n; ++i) {
            if(a[s[i] - 'a']) {
                ret = max(ret, i - p);
                p = i;
            }
        }
        cout << ret << '\n';
    }
}