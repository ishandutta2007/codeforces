#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    if (n % 2 == 0) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    vector<int> a, b;
    rep(i, 1, n + 1) {
        if (i % 2) {
            a.push_back(2 * i);
            b.push_back(2 * i - 1);
        } else {
            b.push_back(2 * i);
            a.push_back(2 * i - 1);
        }
    }
    for (auto x : a)
        cout << x << ' ';
    for (auto x : b)
        cout << x << ' ';
    cout << endl;
    return 0;
}