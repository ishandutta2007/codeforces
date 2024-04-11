#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int a, b, k;
    cin >> a >> b >> k;
    if(b == 1 || a == 0 || k == 0) {
        if(k != 0) cout << "No" << endl;
        else {
            cout << "Yes" << endl;
            cout << string(b, '1') << string(a, '0') << endl;
            cout << string(b, '1') << string(a, '0') << endl;
        }
        return 0;
    }
    if(a + b <= k + 1) return cout << "No" << endl, 0;
    cout << "Yes" << endl;
    // 11000
    // 10001
    string x = string(a + b, '0'), y = x;
    x.back() = '0'; y.back() = '1';
    x[a + b - 1 - k] = '1'; y[a + b - 1 - k] = '0'; // a + b > k + 1
    x[0] = y[0] = '1';
    int cnt = 2;
    for(int i = 1; i < a + b && cnt != b; ++i) {
        if(i == a + b - 1 - k) continue;
        ++cnt;
        x[i] = y[i] = '1';
    }
    cout << x << endl;
    cout << y << endl;
}