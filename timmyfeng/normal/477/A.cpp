#include <bits/stdc++.h>
using namespace std;
 
const int M = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b; cin >> a >> b;

    long long answer = 0;
    for (long long r = 1; r < b; ++r) {
        answer += r * a + ((a + 1) * a / 2 % M) * (r * b % M);
        answer %= M;
    }

    cout << answer << "\n";
}