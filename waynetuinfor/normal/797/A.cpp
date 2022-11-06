#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    vector<int> ans;
    for (int i = 2; n > 1 && k; ++i) {
        while (n % i == 0 && k) {
            ans.push_back(i);
            --k;
            n /= i;
        }
    }
    ans.back() *= n;
    if (k) return cout << "-1\n", 0;
    for (int i : ans) cout << i << ' ';
    return 0;
}