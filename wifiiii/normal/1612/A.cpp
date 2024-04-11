#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int x, y;
        cin >> x >> y;
        if((x + y) & 1) {
            cout << -1 << " " << -1 << endl;
        } else {
            int m = (x + y) / 2, p;
            p = min(x, m); x -= p, m -= p;
            p = min(y, m); y -= p, m -= p;
            cout << x << " " << y << endl;
        }
    }
}