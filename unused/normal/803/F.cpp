#include <bits/stdc++.h>
using namespace std;

int a[100005];
vector<int> divs[100005];
int cnt[100005];
int ans[100005];
int pow2[100005];

constexpr int MOD = 1000000007;

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) scanf("%d",&a[i]);

    pow2[0] = 1;
    for (int i = 1; i <= 100000; i++) pow2[i] = (pow2[i - 1] << 1) % MOD;

    for (int i = 1; i <= 100000; i++)
        for (int j = i; j <= 100000; j += i)
            divs[j].push_back(i);

    for (int i = 1; i <= n; i++)
        for (int j : divs[a[i]])
            ++cnt[j];

    for (int i = 1; i <= 100000; i++) ans[i] = (pow2[cnt[i]] + MOD - 1) % MOD;

    for (int i = 100000; i >= 1; i--)
        for (int j = i * 2; j <= 100000; j += i)
            ans[i] = (ans[i] + MOD - ans[j]) % MOD;

    printf("%d\n", ans[1]);
}