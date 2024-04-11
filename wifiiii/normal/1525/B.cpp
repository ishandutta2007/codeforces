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
            --a[i];
        }
        if(is_sorted(a.begin(), a.end())) {
            cout << 0 << '\n';
        } else {
            if(a[0] == 0 || a[n - 1] == n - 1) {
                cout << 1 << '\n';
            } else if(a[0] == n - 1 && a[n - 1] == 0) {
                cout << 3 << '\n';
            } else {
                cout << 2 << '\n';
            }
        }
    }
}