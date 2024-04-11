#include<bits/stdc++.h>

using namespace std;

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(max(a, b) == max(c, d) && min(a, b) + min(c, d) == max(a, b)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}