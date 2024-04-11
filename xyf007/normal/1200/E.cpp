#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t, a[1000001], n, nxt[1000001];
string s, ans;
void init(int m)
{
    nxt[0] = -1;
    for (int i = 0; i < m - 1; i++)
    {
        nxt[i + 1] = -1;
        int k = nxt[i];
        while (k != -1 && s[i + 1] != s[k + 1])
        {
            k = nxt[k];
        }
        if (s[i + 1] == s[k + 1])
        {
            nxt[i + 1] = k + 1;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    ans = "";
    for (int k = 1; k <= t; k++)
    {
        cin >> s;
        int len = (int)s.size();
        if (k == 1)
        {
            ans = ans + s;
            n += len;
            continue;
        }
        init(len);
        int j = -1;
        for (int i = max(-1, n - len - 1); i < n - 1; i++)
        {
            while (j != -1 && ans[i + 1] != s[j + 1])
            {
                j = nxt[j];
            }
            if (ans[i + 1] == s[j + 1])
            {
                j++;
            }
        }
        for (int i = j + 1; i < len; i++)
        {
            ans.push_back(s[i]);
        }
        n += len - j - 1;
    }
    cout << ans << endl;
    return 0;
}