#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int tt;
    cin >> tt;

    while (tt--) {
        long long k;
        cin >> k;

        long long sum = 0;
        int round = 0;
        for (int i = 1; i < 100000; i += 2) {
            sum += i;
            round++;
            if (sum >= k) {
                sum -= i;
                break;
            }
        }

        long long id = k - sum - 1;
        int x = 1, y = round;
        while (id > 0) {
            if (x < round) x++;
            else y--;
            id--;
        }

        cout << x << " " << y << '\n';
    }
}