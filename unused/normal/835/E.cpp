#include <bits/stdc++.h>
using namespace std;

int n, x, y, DA, DB;

bool ask(const vector<int> &vt)
{
    if (vt.empty() || vt[0] > n) return false;

    printf("? %zd", vt.size());
    for (int t : vt)
    {
        printf(" %d", t);
    }
    printf("\n");
    fflush(stdout);

#ifdef ONLINE_JUDGE
    int res;
    scanf("%d",&res);
#else
    int res = 0;
    for (int t : vt) if (t == DA || t == DB) res ^= y; else res ^= x;
#endif
    return res == y || res == (x ^ y);
}

int main()
{
#ifdef ONLINE_JUDGE
    scanf("%d%d%d", &n, &x, &y);
#else
    n = 10; x = 123; y = 456; DA = 7; DB = 8;
#endif

    int flag = 0;
    int diff = 0;
    for (int i = 1; i <= 512; i <<= 1)
    {
        vector<int> vt;
        for (int j = 1; j <= n; j++)
        {
            if (j & i) vt.push_back(j);
        }

        if (ask(vt))
        {
            flag |= i;
            if (diff == 0) diff = i;
        }
    }

    int ans = 0;
    for (int i = 1; i <= 512; i <<= 1)
    {
        if (diff == i) continue;

        vector<int> vt;
        for (int j = 1; j <= n; j++)
        {
            if ((j & diff) == 0 && (j & i)) vt.push_back(j);
        }

        if (ask(vt)) ans |= i;
    }

    int ans2 = ans ^ flag;
    printf("! %d %d\n", min(ans, ans2), max(ans, ans2));
    fflush(stdout);
}