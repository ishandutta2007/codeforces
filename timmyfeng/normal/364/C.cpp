#include <bits/stdc++.h>
using namespace std;

bool is_prime(int x) {
    for (int p = 2; p * p <= x; ++p)
        if (x % p == 0)
            return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k; cin >> k;

    vector<int> a = {1};
    for (int i = 2; (int) a.size() < k; ++i) {
        if (!is_prime(i)) continue;
        for (int j = 0; j < (int) a.size(); ++j) {
            if (a[j] * i <= 2 * k * k)
                a.push_back(a[j] * i);
        }
    }

    sort(a.begin(), a.end());

    for (int i = (int) a.size() - k; i < (int) a.size(); ++i)
        cout << a[i] << " ";
    cout << "\n";
}