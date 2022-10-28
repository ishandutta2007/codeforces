#include <bits/stdc++.h>
using namespace std;

long long freq[4];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string a, b;
    cin >> n >> a >> b;

    for (int i = 0; i < n; ++i) {
        int c = a[i] - '0', d = b[i] - '0';
        ++freq[2 * c + d];
    }

    cout << freq[2] * (freq[0] + freq[1]) + freq[3] * freq[0] << "\n";
}