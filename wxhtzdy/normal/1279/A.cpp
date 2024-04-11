#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--) {
        long long a, b, c;
        cin >> a >> b >> c;
        bool ok = 1;
        if (a >= b + c + 2) ok = 0;
        if (b >= a + c + 2) ok = 0;
        if (c >= a + b + 2) ok = 0;
        if (ok) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    return 0;
}