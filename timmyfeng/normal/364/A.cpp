#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a; cin >> a;
    string s; cin >> s;
    int n = (int) s.size();

    map<int, int> freq;
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = i; j < n; ++j) {
            sum += s[j] - '0';
            ++freq[sum];
        }
    }

    if (a == 0) {
        cout << 1LL * freq[0] * n * (n + 1) - 1LL * freq[0] * freq[0] << "\n";
        exit(0);
    }

    long long answer = 0;
    for (auto [sum, count] : freq) {
        if (sum && a % sum == 0 && freq.count(a / sum)) {
            answer += 1LL * count * freq[a / sum];
        }
    }

    cout << answer << "\n";
}