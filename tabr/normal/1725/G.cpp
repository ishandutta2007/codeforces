#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    if (N == 1) {
        cout << 3 << "\n";
        return 0;
    }
    N -= 1;
    int ans = 4 * ((N + 2) / 3);
    if (N % 3 == 1)
        ans++;
    else if (N % 3 == 2)
        ans += 3;
    else
        ans += 4;
    cout << ans << "\n";
}