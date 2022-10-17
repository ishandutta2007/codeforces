#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int x, y;
        cin >> x >> y;
        if(x > y) {
            cout << x+y << '\n';
        } else {
            cout << y-(y/2)%(x/2) << '\n';
        }
    }
}