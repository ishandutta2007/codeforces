#include <bits/stdc++.h>
using namespace std;

string solve(string x) {
    int n = (int) size(x);

    for (int i = n - 2; i >= 0; --i) {
        int cur = x[i] - '0', nxt = x[i + 1] - '0';
        if (cur + nxt >= 10)
            return x.substr(0, i) + to_string(cur + nxt) + x.substr(i + 2);
    }

    int first = x[0] - '0', second = x[1] - '0';
    return to_string(first + second) + x.substr(2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        string x; cin >> x;
        cout << solve(x) << "\n";
    }
}