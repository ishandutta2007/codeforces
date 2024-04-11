#include <bits/stdc++.h>
using namespace std;

void run_case() {
    int N;
    cin >> N;

    vector<int> A(N + 2);
    for (int i = 0; i < N + 2; i++) cin >> A[i];
    sort(A.begin(), A.end());

    int64_t sum = 0;
    for (int i = 0; i < N + 2; i++) sum += A[i];
    int x = -1, y = -1;

    for (int i = 0; i < N + 1; i++) {
        if (A[N + 1] == sum - A[N + 1] - A[i]) {
            x = N + 1; y = i;
        }
    }
    for (int i = 0; i < N + 2; i++) {
        if (i == N) continue;
        if (A[N] == sum - A[N] - A[i]) {
            x = N; y = i;
        }
    }
    if (x == -1 && y == -1) {
        cout << -1 << '\n';
        return;
    }

    vector<int> ans;
    for (int i = 0; i < N + 2; i++) if (i != x && i != y) ans.push_back(A[i]);
    for (int i : ans) cout << i << " ";
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests--)
        run_case();
}