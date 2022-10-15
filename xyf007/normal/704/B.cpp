#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, s, t;
long long x[5001], a[5001], b[5001], c[5001], d[5001], nxt[5001];
long long calc(int i, int j)
{
    return i < j ? x[j] - x[i] + d[i] + a[j] : x[i] - x[j] + c[i] + b[j];
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> s >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
    long long ans = calc(s, t);
    nxt[s] = t;
    for (int i = 1; i <= n; i++)
    {
        if (i == s || i == t)
        {
            continue;
        }
        long long minn = 1e18, pos = 0;
        for (int j = s; j != t; j = nxt[j])
        {
            if (long long tmp = calc(j, i) + calc(i, nxt[j]) - calc(j, nxt[j]); tmp < minn)
            {
                minn = tmp;
                pos = j;
            }
        }
        nxt[i] = nxt[pos];
        nxt[pos] = i;
        ans += minn;
    }
    cout << ans;
    return 0;
}