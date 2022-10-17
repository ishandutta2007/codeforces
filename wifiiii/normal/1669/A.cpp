#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int x;
        cin >> x;
        cout << "Division ";
        if(x <= 1399) {
            cout << 4;
        } else if(x <= 1599) {
            cout << 3;
        } else if(x <= 1899) {
            cout << 2;
        } else {
            cout << 1;
        }
        cout << '\n';
    }
}