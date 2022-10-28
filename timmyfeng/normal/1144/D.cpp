#include <bits/stdc++.h>
using namespace std;

const int N = 200001;

int a[N], tally[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++tally[a[i]];
    }

    int x = max_element(tally, tally + N) - tally;
    int y = find(a, a + n, x) - a;

    cout << n - tally[x] << "\n";

    for (int i = y - 1; i >= 0; --i) {
        cout << (a[i] < x ? 1 : 2) << " " << i + 1 << " " << i + 2 << "\n";
    }

    for (int i = y + 1; i < n; ++i) {
        if (a[i] != x) {
            cout << (a[i] < x ? 1 : 2) << " " << i + 1 << " " << i << "\n";
        }
    }
}