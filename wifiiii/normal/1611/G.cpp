#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

template<typename T>
int lis(vector<T> a) {
    vector<T> dp;
    for(auto x : a) {
        auto it = lower_bound(dp.begin(), dp.end(), x); // > : lower, >= : upper
        if(it == dp.end()) dp.push_back(x);
        else *it = x;
    }
    return dp.size();
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<vector<int>>> pos(4, vector<vector<int>>(n + m + 1));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                char c;
                cin >> c;
                int x = i + j + 1, y = i - j + m;
                int p = (((x & 1) << 1) | (y & 1));
                if(c == '1') pos[p][i + j + 1].push_back(i - j + m);
            }
        }
        int ret = 0;
        for(int d = 0; d < 4; ++d) {
            vector<int> b;
            for(int i = 0; i < n + m; ++i) {
                for(int j : pos[d][i]) {
                    b.push_back(j);
                }
            }
            reverse(b.begin(), b.end());
            ret += lis(b);
        }
        cout << ret << '\n';
    }
}