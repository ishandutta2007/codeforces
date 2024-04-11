#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
const long long MOD = 1e9 + 7;
long long n, q, sum[100001];
string s;
long long pow(long long a, long long b, long long mod)
{
    long long sum = 1;
    while (b)
    {
        if (b & 1)
        {
            sum = sum * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return sum;
}
int main()
{
    cin >> n >> q >> s;
    for (long long i = 0; i < n; i++)
    {
        sum[i + 1] = sum[i];
        if (s[i] == '1')
        {
            sum[i + 1]++;
        }
    }
    while (q--)
    {
        long long l, r;
        cin >> l >> r;
        long long t1 = sum[r] - sum[l - 1], t0 = r - l + 1 - t1;
        cout << (pow(2, t1, MOD) - 1) % MOD * pow(2, t0, MOD) % MOD << std::endl;
    }
    return 0;
}