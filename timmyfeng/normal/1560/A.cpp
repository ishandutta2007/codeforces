#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> like;
    for (int i = 1; like.size() < 1000; ++i) {
        if (i % 3 != 0 && i % 10 != 3) {
            like.push_back(i);
        }
    }

    int t;
    cin >> t;

    while (t--) {
        int k;
        cin >> k;
        cout << like[k - 1] << "\n";
    }
}