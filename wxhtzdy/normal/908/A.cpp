#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

string vowel = "aeiou";

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    string s;
    cin >> s;

    int cnt = 0;
    for (char c : s) {
        if ('0' <= c && c <= '9') {
            cnt += ((c - '0') % 2 == 1 ? 1 : 0);
        } else {
            bool ok = true;
            for (char v : vowel) {
                ok &= (c != v);
            }
            cnt += (!ok);
        }
    }

    cout << cnt << '\n';
}