#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <cstring>
using namespace std;

const int A = 30;
int cnt[A];
int t[A];

int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    string str;
    int n;
    cin >> str >> n;
    int cntD = 0;
    for (int i = 0; i < (int)str.length(); i++)
    {
        cnt[str[i] - 'a']++;
        if (cnt[str[i] - 'a'] == 1)
            cntD++;
    }

    if (cntD > n)
    {
        puts("-1");
        return 0;
    }
    for (int i = 0; i < A; i++)
    {
        if (cnt[i])
            t[i]++;
    }

    for (int i = cntD; i < n; i++)
    {                     
        int maxV = 0, pos;
        for (int s = 0; s < A; s++)
        {                     
            if (!cnt[s])
                continue;
            if ((cnt[s] + t[s] - 1) / t[s] > maxV)
            {
                maxV = (cnt[s] + t[s] - 1) / t[s];
                pos = s;
            }
        }      
        t[pos]++;
    }

    int ans = 0;
    for (int i = 0; i < A; i++)
    {
        if (cnt[i] == 0)
            continue;
        ans = max(ans, (cnt[i] + t[i] - 1) / t[i]);
    }
    printf("%d\n", ans);
    for (int i = 0; i < A; i++)
    {
        for (int s = 0; s < t[i]; s++)
            printf("%c", i + 'a');
    }

    return 0;
}