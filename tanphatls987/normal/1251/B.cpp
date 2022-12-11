#include <bits/stdc++.h>

using namespace std;

int main() {
    int test;
    cin >> test;
    while (test--) {
        int h[2], sum = 0;
        h[0] = h[1] = 0;
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            string s;
            cin >> s;
            sum += count(s.begin(), s.end(), '1');
            h[s.length() % 2]++;
        }
        if (sum % 2 == 0 || h[1]) cout << n << '\n';
        else cout << n - 1 << '\n';
    }
}