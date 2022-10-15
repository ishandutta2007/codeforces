#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int t, ans[100001];
string s;
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> s;
        int sz = s.size(), len = 0;
        for (int i = 0; i + 4 < sz; i++)
        {
            if (s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o' && s[i + 3] == 'n' && s[i + 4] == 'e')
            {
                ans[len++] = i + 3;
            }
        }
        for (int i = 0; i + 2 < sz; i++)
        {
            if (s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o' && (i + 4 >= sz || s[i + 3] != 'n' || s[i + 4] != 'e'))
            {
                ans[len++] = i + 2;
            }
            if (s[i] == 'o' && s[i + 1] == 'n' && s[i + 2] == 'e' && (i - 2 < 0 || s[i - 1] != 'w' || s[i - 2] != 't'))
            {
                ans[len++] = i + 2;
            }
        }
        sort(ans, ans + len);
        int tmp = unique(ans, ans + len) - ans;
        printf("%d\n", tmp);
        for (int i = 0; i < tmp; i++)
        {
            printf("%d ", ans[i]);
        }
        printf("\n");
    }
    return 0;
}