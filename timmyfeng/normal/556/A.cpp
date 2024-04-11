#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;

    cout << n - 2 * min(
        count(s.begin(), s.end(), '0'),
        count(s.begin(), s.end(), '1')
    ) << "\n";
}