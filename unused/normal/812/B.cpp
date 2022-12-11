#include <bits/stdc++.h>
using namespace std;

char dat[20][200];

int main()
{
    int n, m;
    scanf("%d%d",&n,&m);
    for (int i = n; i >= 1; i--) scanf("%s", dat[i]);

    while (n >= 1)
    {
        if (strchr(dat[n], '1')) break;
        --n;
    }

    if (n == 0) return !printf("0\n");

    int L = 0, R = m + 1;
    for (int i = 1; i <= n; i++)
    {
        int l = m + 1, r = 0;
        for (int j = 1; j <= m; j++) if (dat[i][j] == '1') r = j;
        for (int j = m; j >= 1; j--) if (dat[i][j] == '1') l = j;

        if (i == n)
        {
            printf("%d\n", min(L + r, R + m + 1 - l));
            return 0;
        }

        int nl, nr;
        nl = min(R + m + 1, L + 2 * r);
        nr = min(L + m + 1, R + 2 * (m + 1 - l));

        L = nl + 1; R = nr + 1;
    }
}