#include <bits/stdc++.h>
using namespace std;

const int N = 200001;

string bitstring[3];
int add[N];

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < 3; ++i) {
        cin >> bitstring[i];
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = i + 1; j < 3; ++j) {
            for (auto k : {'0', '1'}) {
                if (count(bitstring[i].begin(), bitstring[i].end(), k) <= n) {
                    if (count(bitstring[j].begin(), bitstring[j].end(), k) <= n) {
                        fill(add, add + 2 * n + 1, 0);

                        int maxi = 0;
                        for (auto r : {i, j}) {
                            int prefix = 0;
                            for (int l = 0; l < 2 * n; ++l) {
                                if (bitstring[r][l] != k) {
                                    ++prefix;
                                } else {
                                    ++add[prefix];
                                }
                            }
                            maxi = max(maxi, prefix);
                        }

                        string ans;
                        for (int l = 0; l <= maxi; ++l) {
                            if (l > 0) {
                                ans += (char) ('0' + '1' - k);
                            }
                            ans += string(add[l], k);
                        }
                        ans += string(3 * n - ans.size(), '0');

                        cout << ans << "\n";
                        return;
                    }
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}