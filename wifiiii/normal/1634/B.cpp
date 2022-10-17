#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        ll y;
        cin >> n >> x >> y;
        x &= 1, y &= 1;
        for(int i = 0; i < n; ++i) {
            int z;
            cin >> z;
            z &= 1;
            x += z;
        }
        x &= 1;
        if(x == y) cout << "Alice\n";
        else cout << "Bob\n";
    }
}