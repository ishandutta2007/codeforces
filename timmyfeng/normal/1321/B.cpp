#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> b(n);
    for (auto& i : b) {
        cin >> i;
    }

    vector<long long> seqLen(1e6);
    for (int i = 0; i < n; ++i) {
        int seq = n - i + b[i];
        seqLen[seq] += b[i];
    }

    cout << *max_element(seqLen.begin(), seqLen.end()) << '\n';
}