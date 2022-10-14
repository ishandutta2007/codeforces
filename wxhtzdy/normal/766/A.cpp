#include <bits/stdc++.h>
using namespace std;

void run_case() {
    string A, B;
    cin >> A >> B;

    cout << (A == B ? -1 : max((int) A.size(), (int) B.size())) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests = 1;

    while (tests--)
        run_case();
}