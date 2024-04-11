#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string a, b;
        cin >> a >> b;
        if(b == "a") {
            cout << 1 << '\n';
        } else if(find(b.begin(), b.end(), 'a') != b.end()
               && find(a.begin(), a.end(), 'a') != a.end()) {
            cout << -1 << '\n';
        } else {
            cout << (1ll << count(a.begin(), a.end(), 'a')) << '\n';
        }
    }
}