#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        vector<int> a(3);
        for(int i = 0; i < 3; ++i) cin >> a[i];
        for(int i = 0; i < 3; ++i) {
            int mx = 0;
            for(int j = 0; j < 3; ++j) {
                if(i == j) continue;
                mx = max(mx, a[j]);
            }
            cout << max(0, mx - a[i] + 1) << ' ';
        }
        cout << '\n';
    }
}