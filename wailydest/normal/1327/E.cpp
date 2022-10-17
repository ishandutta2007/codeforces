#include <iostream>
using namespace std;

const int mod = 998244353;

long long quickpow(long long base, long long exponent, long long mod);

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        cout << (quickpow(10, n - i, mod) * 18 + quickpow(10, n - i - 1, mod) * 81 * (n - i - 1)) % mod << ' ';
    }
    cout << 10 << '\n';
    return 0;
}

long long quickpow(long long base, long long exponent, long long mod)
{
    long long result = 1;
    do {
        if (exponent & 1) result = result * base % mod;
        base = base * base % mod;
    } while(exponent >>= 1);
    return result;
}