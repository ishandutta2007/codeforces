#include <bits/stdc++.h>
using namespace std;

pair<int, int> operator+(pair<int, int> a, pair<int, int> b) {
    return {a.first + b.first, a.second + b.second};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> pts(n);
    for (auto& i : pts) {
        cin >> i.first >> i.second;
    }
    if (n % 2) {
        cout << "NO\n";
        exit(0);
    }
    for (int i = 1; i < n / 2; i++) {
        if (pts[i] + pts[i + n / 2] != pts[0] + pts[n / 2]) {
            cout << "NO\n";
            exit(0);
        }
    }
    cout << "YES\n";
}