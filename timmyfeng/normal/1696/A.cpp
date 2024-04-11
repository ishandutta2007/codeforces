#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, z; cin >> n >> z;
        int answer = 0;
        for (int i = 0; i < n; ++i) {
            int a; cin >> a;
            answer = max(answer, a | z);
        }
        cout << answer << "\n";
    }
}