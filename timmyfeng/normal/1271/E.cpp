#include <bits/stdc++.h>
using namespace std;

long long n;

long long count(long long m) {
    long long ret = 0;
    long long range = 1;
    while (m + range - 1 <= n) {
        ret += range;
        range *= 2;
        m *= 2;
    }
    if (m <= n) {
        ret += n - m + 1;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long k;
    cin >> n >> k;
    long long loOdd = 0, hiOdd = (n - 1) / 2;
    while (loOdd <= hiOdd) {
        long long mi = (loOdd + hiOdd) / 2;
        if (count(mi * 2 + 1) >= k) {
            loOdd = mi + 1;
        } else {
            hiOdd = mi - 1;
        }
    }
    long long loEven = 1, hiEven = n / 2;
    while (loEven <= hiEven) {
        long long mi = (loEven + hiEven) / 2;
        if (count(mi) - 1 >= k) {
            loEven = mi + 1;
        } else {
            hiEven = mi - 1;
        }
    }
    cout << max(hiOdd * 2 + 1, hiEven * 2) << '\n';
}