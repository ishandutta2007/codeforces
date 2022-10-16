#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
using ll = long long;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int a, b, k; cin >> a >> b >> k;
        const int n = a+b;

    if ((b == 1 || a == 0) && k != 0) {
        cout << "No" << endl;
    } else if (k == 0 || a == 0 || b == 1) {
        cout << "Yes" << endl;
        cout << string(b, '1') << string(a, '0') << endl;
        cout << string(b, '1') << string(a, '0') << endl;
    } else if (k < b) {
        cout << "Yes" << endl;
        string s(a+b, '0'), t(a+b, '0');
        s[0] = t[0] = '1';
        for (int i = 0; i < b-k; ++i) t[n-i] = s[n-i] = '1';
        for (int i = b-k; i < b; ++i) t[n-i] = s[n-i-1] = '1';
        cout << s << endl << t << endl;
    } else if (k <= a + b - 2) {
        cout << "Yes" << endl;
        string s(a+b, '0'), t(a+b, '0');
        s[0] = t[0] = '1';
        t[n-1] = '1';
        for (int i = 2; i < b; ++i) t[n-i] = '1', s[n-i] = '1';
        s[n-k-1] = '1';
        cout << s << endl << t << endl;
    } else {
        cout << "No" << endl;
    }
}