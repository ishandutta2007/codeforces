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
        vector<vector<int>> a(2);
        for(int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a[x & 1].push_back(x);
        }
        if(is_sorted(a[0].begin(), a[0].end()) && is_sorted(a[1].begin(), a[1].end())) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}