#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a > b) swap(a, b);
        int n = 2 * (b - a);
        if(a > n / 2 || b <= n / 2 || c > n) {
            cout << -1 << endl;
            continue;
        }
        if(c > n / 2) cout << c - n / 2 << endl;
        else cout << c + n / 2 << endl;
    }
}