#include <bits/stdc++.h>
using namespace std;

int ask(const string &str)
{
    printf("? %s\n", str.c_str());
    fflush(stdout);

    int ret;
    scanf("%d", &ret);
    return ret;
}

void answer(int a, int b)
{
    printf("! %d %d\n", a, b);
    fflush(stdout);
    exit(0);
}

int main()
{
    int n;
    scanf("%d",&n);

    string str(n, '0');

    int q1 = ask(str);
    str[0] = '1';
    int q2 = ask(str);

    if (q1 < q2)
    {
        // str[0] is 0
        // base is q1
        str[0] = '0';

        int lo = 1, hi = n - 2, ans = n - 1;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            for (int i = 1; i <= mid; i++) str[i] = '1';
            for (int i = mid + 1; i < n; i++) str[i] = '0';

            int ret = ask(str);

            if (ret == q1 + mid)
            {
                lo = mid + 1;
            }
            else
            {
                ans = mid;
                hi = mid - 1;
            }
        }

        answer(1, ans + 1);
    }
    else
    {
        // str[0] is 1
        int lo = 1, hi = n - 2, ans = n - 1;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            for (int i = 1; i <= mid; i++) str[i] = '1';
            for (int i = mid + 1; i < n; i++) str[i] = '0';

            int ret = ask(str);

            if (ret == q2 - mid)
            {
                lo = mid + 1;
            }
            else
            {
                ans = mid;
                hi = mid - 1;
            }
        }

        answer(ans + 1, 1);
    }
}