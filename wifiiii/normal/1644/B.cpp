#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        set<vector<int>> vis;
        vector<int> a(n);
        iota(a.begin(), a.end(), 1);
        auto check = [&]() {
            for(int i = 2; i < n; ++i) {
                if(a[i - 1] + a[i - 2] == a[i]) return 0;
            }
            return 1;
        };
        for(int i = 0; i < n; ++i) {
            shuffle(a.begin(), a.end(), mrand);
            while(vis.count(a) || !check()) shuffle(a.begin(), a.end(), mrand);
            for(int j : a) cout << j << ' '; cout << '\n';
            vis.insert(a);
        }
    }
}