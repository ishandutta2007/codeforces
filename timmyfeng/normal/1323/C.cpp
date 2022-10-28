#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;

    int left = 0;
    for (auto i : s) {
        if (i == '(') {
            ++left;
        }
    }
    if (left != n - left) {
        cout << -1 << '\n';
        exit(0);
    }

    int sol = 0;
    int len = 0;
    int right = 0;
    bool wrong = false;
    left = 0;
    for (auto i : s) {
        len++;
        if (i == '(') {
            if (right) {
                --right;
                wrong = true;
            } else {
                ++left;
            }
        } else {
            if (left) {
                --left;
            } else {
                ++right;
            }
        }
        if (left == right) {
            if (wrong) {
                sol += len;
            }
            len = 0;
            left = 0;
            right = 0;
            wrong = false;
        }
    }
    cout << sol << '\n';
}