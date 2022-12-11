#include <bits/stdc++.h>
using namespace std;

int k;
vector<string> words;
char line[1000005];

bool check(int t)
{
    int now = t, rem = k;

    for (auto &e : words)
    {
        if (e.size() > t) return false;

        if (now + e.size() > t)
        {
            now = 0;
            if (--rem < 0) return false;
        }

        now += e.size();
    }

    return true;
}

int main()
{
    scanf("%d ", &k);
    fgets(line, 1000005, stdin);
    int len = strlen(line);
    if (line[len - 1] == '\n') line[--len] = 0;

    for (int i = 0, j = 0; i <= len; i++)
    {
        if (i == len)
        {
            words.emplace_back(line + j);
        }
        else if (line[i] == ' ' || line[i] == '-')
        {
            words.emplace_back(line + j, line + i + 1);
            j = i + 1;
        }
    }

    int lo = 1, hi = len - 1, ans = len;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (check(mid))
        {
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    printf("%d\n", ans);
}