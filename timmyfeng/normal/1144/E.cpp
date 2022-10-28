#include <bits/stdc++.h>
using namespace std;

vector<int> read() {
    string s;
    cin >> s;

    vector<int> ans;
    for (auto i : s) {
        ans.push_back(i - 'a');
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> s = read(), t = read(), d(n);

    for (int i = n - 1; i >= 0; --i) {
        d[i] += t[i] - s[i];
        while (d[i] < 0) {
            d[i] += 26;
            --d[i - 1];
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        if (d[i] % 2 == 1) {
            d[i + 1] += 13;
        }
        d[i] /= 2;
    }

    for (int i = n - 1; i >= 0; --i) {
        s[i] += d[i];
        while (s[i] >= 26) {
            s[i] -= 26;
            ++d[i - 1];
        }
    }

    for (auto i : s) {
        cout << (char) (i + 'a');
    }

    cout << "\n";
}