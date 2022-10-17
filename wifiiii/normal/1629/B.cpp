#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int l, r, k;
        cin >> l >> r >> k;
        if(l == r) {
            cout << (l > 1 ? "YES" : "NO") << '\n';
        } else if((r - l + 1) & 1) {
            if(l % 2 == 0) {
                cout << (k >= (r - l) / 2 ? "YES" : "NO") << '\n';
            } else {
                cout << (k >= (r - l) / 2 + 1 ? "YES" : "NO") << '\n';
            }
        } else {
            cout << (k >= (r - l + 1) / 2 ? "YES" : "NO") << '\n';
        }
    }
}