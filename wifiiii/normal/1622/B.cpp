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
        string s;
        cin >> s;
        vector<vector<int>> ord(2);
        for(int i = 0; i < n; ++i) {
            ord[s[i] - '0'].push_back(i);
        }
        int cnt = 0;
        vector<int> ans(n);
        for(int i = 0; i < 2; ++i) {
            sort(ord[i].begin(), ord[i].end(), [&](int i, int j) {return a[i] < a[j];});
            for(int j : ord[i]) ans[j] = ++cnt;
        }
        for(int i : ans) cout << i << " "; cout << '\n';
    }
}