#include <bits/stdc++.h>
using namespace std;

int last[26];
int mx[26];
char str[111111];

int main()
{
    cin >> str + 1;
    int i = 1;
    while (str[i])
    {
        int x = str[i] - 'a';
        mx[x] = max(mx[x], i - last[x]);
        last[x] = i;
        ++i;
    }
    for (int j = 0; j < 26; j++)
    {
        if (last[j]) mx[j] = max(mx[j], i - last[j]);
    }
    int ans = INT_MAX;
    for (int i = 0; i < 26; i++) if (mx[i]) ans = min(ans, mx[i]);
    printf("%d\n", ans);
}