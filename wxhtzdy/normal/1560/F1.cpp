#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

bool valid(long long n) {
    set<int> s;
    while (n > 0) {
        s.insert(n % 10);
        n /= 10;
    }
    return s.size() <= 1;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    vector<long long> dif;
    vector<long long> same;

    for (int len = 1; len <= 10; len++) {
        for (int x = 0; x < 10; x++) {
            for (int y = 0; y < 10; y++) {
                for (int mask = 0; mask < (1 << len); mask++) {
                    long long val = 0;
                    for (int i = 0; i < len; i++) {
                        val *= 10;
                        if (mask & (1 << i)) val += x;
                        else val += y;
                    }

                    if (valid(val)) {
                        same.push_back(val);
                    }
                    dif.push_back(val);
                }
            }
        }
    }

    sort(same.begin(), same.end());
    same.erase(unique(same.begin(), same.end()), same.end());

    sort(dif.begin(), dif.end());
    dif.erase(unique(dif.begin(), dif.end()), dif.end());


    int tt;
    cin >> tt;

    while (tt--) {
        long long n, k;
        cin >> n >> k;

        if (k == 1) {
            cout << *lower_bound(same.begin(), same.end(), n) << '\n';
        } else {
            cout << *lower_bound(dif.begin(), dif.end(), n) << '\n';
        }
    }
}