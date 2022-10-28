#include <bits/stdc++.h>
using namespace std;

const int M = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    set<int> sell, buy, any;
    int ans = 1;

    for (int i = 0; i < n; ++i) {
        string s;
        int p;
        cin >> s >> p;

        if (s == "ADD") {
            if (!sell.empty() && p > *sell.begin()) {
                sell.insert(p);
            } else if (!buy.empty() && p < *--buy.end()) {
                buy.insert(p);
            } else {
                any.insert(p);
            }
        } else {
            if (sell.count(p) > 0) {
                if (p > *sell.begin()) {
                    cout << 0 << "\n";
                    exit(0);
                }
                sell.erase(p);

                for (auto q : any) {
                    buy.insert(q);
                }
                any.clear();
            } else if (buy.count(p) > 0) {
                if (p < *--buy.end()) {
                    cout << 0 << "\n";
                    exit(0);
                }
                buy.erase(p);

                for (auto q : any) {
                    sell.insert(q);
                }
                any.clear();
            } else {
                for (auto q : any) {
                    if (q < p) {
                        buy.insert(q);
                    } else if (q > p) {
                        sell.insert(q);
                    }
                }
                any.clear();

                ans *= 2;
                if (ans >= M) {
                    ans -= M;
                }
            }
        }
    }

    ans = (long long) (any.size() + 1) * ans % M;

    cout << ans << "\n";
}