#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int n;
string s;
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s;
    int l = 0, r = 0, last = 0, ans = 0;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == '(')
        {
            l++;
        }
        else
        {
            r++;
        }
    }
    if (l != r)
    {
        printf("-1");
        return 0;
    }
    l = 0;
    last = 0;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == '(')
        {
            l++;
            if (!l)
            {
                ans += i - last + 1;
                last = i + 1;
            }
        }
        else
        {
            l--;
            if (!l)
            {
                last = i + 1;
            }
        }
    }
    printf("%d", ans);
    return 0;
}