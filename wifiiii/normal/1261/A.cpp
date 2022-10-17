#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        string target;
        --k;
        for(int i = 0; i < k; ++i) target += "()";
        target += string((n - 2 * k) / 2, '(') + string((n - 2 * k) / 2, ')');
        vector<pair<int,int>> ans;
        for(int i = 0; i < n; ++i) {
            for(int j = i; j < n; ++j) {
                if(s[j] == target[i]) {
                    reverse(s.begin() + i, s.begin() + j + 1);
                    ans.push_back({i, j});
                    break;
                }
            }
        }
        cout << ans.size() << endl;
        for(auto [l, r] : ans) {
            cout << l + 1 << " " << r + 1 << endl;
        }
    }
}