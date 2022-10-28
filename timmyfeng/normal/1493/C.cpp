#include <bits/stdc++.h>
using namespace std;

const int A = 26;

int freq[A], n, k;
string ans, s;

bool solve(int index, bool greater) {
    if (index == n) {
        return true;
    }

    int sum = accumulate(freq, freq + A, 0);
    for (int i = greater ? 0 : s[index] - 'a'; i < A; ++i) {
        if (index + sum < n || freq[i] > 0) {
            freq[i] = (freq[i] - 1 + k) % k;
            ans += 'a' + i;
            if (solve(index + 1, greater || i > s[index] - 'a')) {
                return true;
            }
            ans.pop_back();
            freq[i] = (freq[i] + 1) % k;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> k >> s;

        if (n % k != 0) {
            cout << -1 << "\n";
            continue;
        }

        fill(freq, freq + A, 0);
        ans.clear();
        assert(solve(0, false));
        cout << ans << "\n";
    }
}