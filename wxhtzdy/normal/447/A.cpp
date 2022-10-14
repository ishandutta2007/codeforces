#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int p, N; cin >> p >> N;
    vector<int> A(N); for (int& i : A) cin >> i;

    vector<bool> was(p);

    for (int i = 0; i < N; i++) {
        if (was[A[i] % p]) return cout << i + 1, 0;
        was[A[i] % p] = true;
    }
    cout << -1;
    return 0;
}