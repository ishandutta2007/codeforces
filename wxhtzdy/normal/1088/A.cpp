#include <bits/stdc++.h>
using namespace std;

void run_case() {
    int N;
    cin >> N;

    if (N == 1) cout << -1 << '\n';
    else cout << N << " " << N << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests = 1;

    while (tests--)
        run_case();
}