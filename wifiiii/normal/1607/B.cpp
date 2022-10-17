#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll x, y;
        cin >> x >> y;
        if(x % 2 == 0) {
            if(y % 4 == 1) cout << x - y << endl;
            else if(y % 4 == 2) cout << x + 1 << endl;
            else if(y % 4 == 3) cout << x + y + 1 << endl;
            else if(y % 4 == 0) cout << x << endl;
        } else {
            if(y % 4 == 1) cout << x + y << endl;
            else if(y % 4 == 2) cout << x - 1 << endl;
            else if(y % 4 == 3) cout << x - y - 1 << endl;
            else if(y % 4 == 0) cout << x << endl;
        }
    }
}