#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        if(a == 0 && b == 0) cout << 0 << endl;
        else if(a == b) cout << 1 << endl;
        else {
            if(a % 2 == b % 2) cout << 2 << endl;
            else cout << -1 << endl;
        }
    }
}