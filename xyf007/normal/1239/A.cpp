#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
constexpr int MOD = 1e9 + 7;
int n, m, f[100001];
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    f[1] = 1;
    f[2] = 2;
    for (int i = 3; i <= max(n, m); i++)
    {
        f[i] = (f[i - 1] + f[i - 2]) % MOD;
    }
    cout << 2LL * (f[n] + f[m] - 1) % MOD;
    return 0;
}