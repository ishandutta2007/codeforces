#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
long long t, n, a, b, c[200001];
string s;
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> a >> b >> s;
        long long ans = n * a, cnt = 0, tmp = 0;
        for (int i = 0; i <= n; i++)
        {
            c[i] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                c[i] = c[i + 1] = 2;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (c[i] != c[i + 1])
            {
                ans += a;
            }
            ans += b * c[i];
        }
        ans += b;
        while (c[tmp] == 1)
        {
            tmp++;
        }
        while (c[tmp] == 2)
        {
            tmp++;
        }
        for (; tmp <= n; tmp++)
        {
            if (c[tmp] == 1)
            {
                cnt++;
            }
            else
            {
                if (cnt > 0 && b * cnt < 2 * a)
                {
                    ans -= 2 * a - b * cnt;
                }
                cnt = 0;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}