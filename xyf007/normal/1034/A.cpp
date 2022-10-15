#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, a[300001], cnt[15000001], p[1000001], tot;
bool not_prime[15000001];
void checkmax(int &x, int y)
{
    if (x < y)
    {
        x = y;
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int GCD = a[1];
    for (int i = 2; i <= n; i++)
    {
        GCD = __gcd(GCD, a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        a[i] /= GCD;
        cnt[a[i]]++;
    }
    int minn = *min_element(a + 1, a + n + 1), maxx = *max_element(a + 1, a + n + 1);
    if (minn == maxx)
    {
        cout << -1;
        return 0;
    }
    not_prime[1] = 1;
    for (int i = 2; i <= maxx; i++)
    {
        if (!not_prime[i])
        {
            p[++tot] = i;
        }
        for (int j = 1; j <= tot && i * p[j] <= maxx; j++)
        {
            not_prime[i * p[j]] = 1;
            if (!(i % p[j]))
            {
                break;
            }
        }
    }
    int ans = 0, tmp = 0;
    for (int i = 1; i <= tot; i++)
    {
        tmp = 0;
        for (int j = p[i]; j <= maxx; j += p[i])
        {
            tmp += cnt[j];
        }
        checkmax(ans, tmp);
    }
    cout << n - ans;
    return 0;
}