#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string a, b, c;
        cin >> a >> b >> c;
        int ok = 1;
        for(int i = 0; i < c.size(); ++i) {
            if(a[i] == c[i] || b[i] == c[i]) {

            } else {
                ok = 0;
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
}