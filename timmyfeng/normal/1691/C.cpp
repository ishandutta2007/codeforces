#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;

        int first = 0, last = n - 1;
        while (first < n && s[first] == '0') ++first;
        while (last >= 0 && s[last] == '0') --last;

        int answer = count(s.begin(), s.end(), '1') * 11;
        if (first + n - 1 - last <= k && first != last) {
            answer -= 11;
        } else if (n - 1 - last <= k) {
            answer -= 10;
        } else if (first <= k) {
            answer -= 1;
        }

        cout << max(0, answer) << "\n";
    }
}