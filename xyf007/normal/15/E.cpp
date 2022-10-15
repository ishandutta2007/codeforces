#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MOD = 1e9 + 9;
int n;
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    long long res = 2, cur = 1, sum = 1, pre = 1;
    for (int i = 4; i <= n; i += 2)
    {
        res = (res + sum * 4) % MOD;
        pre = (pre + cur * 4) % MOD;
        cur = (cur << 1) % MOD;
        sum = sum * pre % MOD;
    }
    printf("%lld", (2 * res * res + 2) % MOD);
    return 0;
}