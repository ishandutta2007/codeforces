#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t, n, ans[200001];
char s[200001];
int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %s", &n, s + 1);
        int now = 1;
        for (int i = 1; i <= n; i++)
        {
            ans[i] = 0;
        }
        if (s[1] == '<')
        {
            s[0] = '>';
        }
        else
        {
            s[0] = '<';
        }
        if (s[n - 1] == '<')
        {
            s[n] = '>';
        }
        else
        {
            s[n] = '<';
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '>')
            {
                ans[i + 1] = now++;
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '<')
            {
                int j = i - 1;
                while (s[j] == '<')
                {
                    j--;
                }
                j++;
                for (int k = j + 1; k <= i + 1; k++)
                {
                    ans[k] = now++;
                }
                i = j;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            cout << ans[i] << ' ';
            ans[i] = 0;
        }
        cout << endl;
        now--;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '<')
            {
                ans[i + 1] = now--;
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '>')
            {
                int j = i - 1;
                while (s[j] == '>')
                {
                    j--;
                }
                j++;
                for (int k = j + 1; k <= i + 1; k++)
                {
                    ans[k] = now--;
                }
                i = j;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            cout << ans[i] << ' ';
            ans[i] = 0;
        }
        cout << endl;
    }
    return 0;
}