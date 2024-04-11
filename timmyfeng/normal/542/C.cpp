#include <bits/stdc++.h>
using namespace std;

const int N = 201;

int f[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> f[i];
    }

    long long cycle = 1, ans = 1;
    for (int i = 1; i <= n; ++i) {
        map<int, long long> in;

        int j = i;
        long long k = 0;
        while (in.count(j) == 0) {
            in[j] = k++;
            j = f[j];
        }

        if (i == j) {
            cycle *= k / __gcd(cycle, k);
        } else {
            ans = max(ans, in[j]);
        }
    }

    if (ans % cycle != 0) {
        ans += cycle - ans % cycle;
    }

    cout << ans << "\n";
}