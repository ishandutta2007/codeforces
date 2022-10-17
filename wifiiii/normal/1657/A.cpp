#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    // freopen("in.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--) {
        int x, y;
        cin >> x >> y;
        if(x == 0 && y == 0) {
            cout << 0 << '\n';
            continue;
        }
        int z = x * x + y * y;
        int k = sqrt(z);
        if(k * k == z) {
            cout << 1 << '\n';
        } else {
            cout << 2 << '\n';
        }
    }
}