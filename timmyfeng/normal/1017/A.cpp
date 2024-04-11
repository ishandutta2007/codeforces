#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    int n;
    cin >> n;

    int ans = 1, tom = 0;
    for (int i = 0; i < n; ++i) {
        int score = 0;
        for (int j = 0; j < 4; ++j) {
            int a;
            cin >> a;
            score += a;
        }

        if (i == 0) {
            tom = score;
        } else {
            ans += (score > tom);
        }
    }

    cout << ans << "\n";
}