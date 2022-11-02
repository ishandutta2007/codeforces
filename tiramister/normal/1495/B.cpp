#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void fail() {
    cout << "0\n";
    exit(0);
}

void solve() {
    int n;
    cin >> n;

    vector<int> ps(n);
    for (auto& p : ps) cin >> p;

    vector<int> turns{0};
    for (int i = 1; i < n - 1; ++i) {
        if ((ps[i - 1] < ps[i]) ==
            (ps[i] > ps[i + 1])) turns.push_back(i);
    }
    turns.push_back(n - 1);

    int m = turns.size();
    vector<int> lens(m - 1);
    for (int i = 0; i + 1 < m; ++i) {
        lens[i] = turns[i + 1] - turns[i];
    }

    int mi = max_element(lens.begin(), lens.end()) - lens.begin();
    if (count(lens.begin(), lens.end(), lens[mi]) != 2 ||
        lens[mi + 1] != lens[mi] ||
        lens[mi] % 2 != 0) fail();

    int p = turns[mi + 1];
    // peak or cave
    if (ps[p] < ps[p + 1]) fail();

    cout << "1\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    solve();

    return 0;
}