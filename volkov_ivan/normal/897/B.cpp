#include <iostream>

using namespace std;

long long zcy(long long num) {
    long long ans = num;
    while (num > 0) {
        ans *= 10;
        ans += num % 10;
        num /= 10;
    }
    return ans;
}

int main() {
    long long k, p, ans = 0;
    cin >> k >> p;
    for (long long i = 1; i <= k; i++) {
        ans = (ans + zcy(i)) % p;
    }
    cout << ans << endl;
    return 0;
}