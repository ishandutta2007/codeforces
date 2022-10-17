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
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        if(is_sorted(a.begin(), a.end())) {
            cout << 0 << '\n';
            continue;
        }
        if(a[n - 2] > a[n - 1] || a[n - 1] < 0) {
            cout << -1 << '\n';
            continue;
        }
        vector<tuple<int,int,int>> ans;
        cout << n - 2 << '\n';
        for(int i = n - 2; i >= 1; --i) {
            cout << i << ' ' << i + 1 << ' ' << n << '\n';
        }
    }
}