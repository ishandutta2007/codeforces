#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k1, k2;
        cin >> n >> k1 >> k2;
        if(k1 > k2) swap(k1, k2);
        int W = k1 + (k2 - k1) / 2, B = (n - k2) + (k2 - k1) / 2;
        int w, b;
        cin >> w >> b;
        if(w <= W && b <= B) cout << "YES\n";
        else cout << "NO\n";
    }
}