#include <bits/stdc++.h>
using namespace std;

string a, b;

int calc(int idx, bool print)
{
    int ret = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[idx + i])
        {
            ++ret;
            if (print) printf("%d ", i + 1);
        }
    }
    return ret;
}

int main()
{
    int tmp;
    cin >> tmp >> tmp >> a >> b;

    int ans = INT_MAX;

    for (int i = 0; i <= b.size() - a.size(); i++)
    {
        ans = min(ans, calc(i, false));
    }

    printf("%d\n", ans);

    for (int i = 0; i <= b.size() - a.size(); i++)
    {
        if (calc(i, false) == ans)
        {
            calc(i, true);
            break;
        }
    }
}