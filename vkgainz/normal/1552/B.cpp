#include <bits/stdc++.h>
using namespace std;

int win(vector<int> a, vector<int> b) {
    int ans = 0;
    for(int j = 0; j < 5; j++)
        ans += a[j] < b[j];
    return ans;
}

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int ans = 0;
        vector<vector<int>> r(n, vector<int>(5));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 5; j++)
                cin >> r[i][j];
        }
        for(int i = 0; i < n; i++) {
            if(win(r[i], r[ans]) >= 3)
                ans = i;
        }
        int num = 0;
        for(int i = 0; i < n; i++)
            num += (win(r[ans], r[i]) >= 3);
        if(num == n - 1) cout << ans + 1 << "\n";
        else cout << -1 << "\n";
    }
}