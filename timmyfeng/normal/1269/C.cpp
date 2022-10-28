#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int n, k;
    string s;
    cin >> n >> k >> s;
    string t = s.substr(0, k);
    for (int i = k; i < n; i++) {
        t += t[i - k];
    }
    if (t < s) {
        for (int i = k - 1; i >= 0; i--) {
            if (t[i] == '9') {
                t[i] = '0';
            } else {
                t[i]++;
                break;
            }
        }
        for (int i = k; i < n; i++) {
            t[i] = t[i - k];
        }
    }
    cout << n << '\n';
    cout << t << '\n';
}