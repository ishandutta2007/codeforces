#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    vector<long long> sin(26);
    vector<long long> dou(26 * 26);
    for (char c : s) {
        for (int i = 0; i < 26; i++) {
            dou[i * 26 + c - 'a'] += sin[i];
        }
        ++sin[c - 'a'];
    }
    cout << max(*max_element(sin.begin(), sin.end()), *max_element(dou.begin(), dou.end())) << '\n';
}