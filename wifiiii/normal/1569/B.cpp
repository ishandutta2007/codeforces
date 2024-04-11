#include <bits/stdc++.h>
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
        vector<vector<char>> ans(n, vector<char>(n, '='));
        vector<int> p;
        for(int i = 0; i < n; ++i) if(s[i] == '2') p.push_back(i);
        if(p.size() == 1 || p.size() == 2) {
            cout << "NO" << endl;
            continue;
        }
        for(int i = 0; i < p.size(); ++i) {
            ans[p[i]][p[(i+1)%p.size()]]='+';
            ans[p[(i+1)%p.size()]][p[i]]='-';
        }
        cout << "YES" << endl;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(i == j) cout << 'X';
                else cout << ans[i][j];
            }
            cout << endl;
        }
    }
}