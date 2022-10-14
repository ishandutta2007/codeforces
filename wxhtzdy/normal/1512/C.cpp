#include <bits/stdc++.h>
using namespace std;

void run_case() {
    int a, b;
    cin >> a >> b;

    int x = a, y = b;
    string S;
    cin >> S;

    int N = (int) S.size();

    for (int i = 0; i < N; i++) {
        if (S[i] == '?') {
            int j = N - i - 1;
            S[i] = S[j];
        }
    }

    for (int i = 0; i < N; i++) {
        if (S[i] == '0') a--;
        if (S[i] == '1') b--;
    }
    if (a < 0 || b < 0 || (a % 2 == 1 && b % 2 == 1)) {
        cout << -1 << '\n';
        return;
    }
    if (N % 2 == 0) {
        if (a % 2 == 1 || b % 2 == 1) {
            cout << -1 << '\n';
            return;
        }
    }
    if (N % 2 == 1) {
        if (a % 2 == 1 && S[N / 2] == '?') S[N / 2] = '0', --a;
        if (b % 2 == 1 && S[N / 2] == '?') S[N / 2] = '1', --b;
    }

    for (int i = 0; i < N; i++) {
        if (S[i] == '?') {
            if (a > 0) S[i] = S[N - i - 1] = '0', a -= 2;
            else if (b > 0) S[i] = S[N - i - 1] = '1', b -= 2;
            else assert(false);
        }
    }
    int cnt[2] = {0, 0};
    for (char c : S) cnt[c - '0']++;
    if (cnt[0] != x && cnt[1] != y) {
        cout << -1 << '\n';
        return;
    }

    for (int i = 0; i < N; i++) {
        if (S[i] != S[N - i - 1]) {
            cout << -1 << '\n';
            return;
        }
    }

    cout << S << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests--)
        run_case();
}