#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        if (s[n - 1] == 'o')
            cout << "FILIPINO" << endl;
        else if (s[n - 1] == 'u')
            cout << "JAPANESE" << endl;
        else
            cout << "KOREAN" << endl;
    }

    return 0;
}