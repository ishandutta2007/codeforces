#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                int dis = max({i + j, n - 1 - i + j, i + m - 1 - j, n - 1 - i + m - 1 - j});
                a.push_back(dis);
            }
        }
        sort(a.begin(), a.end());
        for(int i : a) cout << i << " "; cout << '\n';
    }
}