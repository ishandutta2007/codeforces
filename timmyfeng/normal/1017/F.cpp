#include <bits/stdc++.h>
using namespace std;

const int N = 300000000;

unsigned f[4]; 
bitset<N / 3> sieve;

bool check(int n) {
    if (n == 2 || n == 3) {
        return true;
    } else if (n % 6 == 1 || n % 6 == 5) {
        return !sieve[n / 3];
    } else {
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (auto &i : f) {
        cin >> i;
    }

    for (int i = 4; i <= n; ++i) {
        if (check(i)) {
            for (int j = 2 * i; j <= n; j += i) {
                if (j % 6 == 1 || j % 6 == 5) {
                    sieve[j / 3] = true;
                }
            }
        }
    }

    unsigned ans = 0;
    for (int i = 2; i <= n; ++i) {
        if (check(i)) {
            long long k = i;
            unsigned c = 0;
            while (k <= n) {
                c += n / k;
                k *= i;
            }

            unsigned y = 0;
            for (auto j : f) {
                y = i * y + j;
            }

            ans += c * y;
        }
    }

    cout << ans << "\n";
}