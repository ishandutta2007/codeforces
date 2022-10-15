#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
int n;
long long sum[200001][26], sum2[200002][26];
char s[200001], t[200001];
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n >> (s + 1) >> (t + 1);
    for (int i = 1; i <= n; i++)
    {
        std::memcpy(sum[i], sum[i - 1], sizeof(sum[i]));
        std::memcpy(sum2[i], sum2[i - 1], sizeof(sum2[i]));
        sum[i][t[i] - 'A'] += n - i + 1;
        sum2[i][t[i] - 'A'] += i;
    }
    double ans = 0.0;
    for (int i = 1; i <= n; i++)
    {
        ans += (n - i + 1) * static_cast<long long>(sum2[i][s[i] - 'A']) + i * static_cast<long long>(sum[n][s[i] - 'A'] - sum[i][s[i] - 'A']);
    }
    std::cout << std::setprecision(8) << std::fixed << ans * 6 / n / (n + 1) / (2 * n + 1);
    return 0;
}