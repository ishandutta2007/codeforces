#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t, n, a[200005], cnt;
string s;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        cnt = 0;
        int tmp = 1, ans = 0, tt = 1;
        for (int i = 1; i < n; i++)
        {
            if (s[i] == s[i - 1])
            {
                tmp++;
            }
            else
            {
                a[++cnt] = tmp;
                tmp = 1;
            }
        }
        a[++cnt] = tmp;
        for (int i = 1; i <= cnt; i++)
        {
            ans++;
            if (a[i] == 1)
            {
                while (tt <= cnt && (tt <= i || a[tt] == 1))
                {
                    tt++;
                }
                if (tt <= cnt && a[tt] > 1)
                {
                    a[tt]--;
                }
                else
                {
                    i++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}