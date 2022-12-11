#include <bits/stdc++.h>
using namespace std;

int perm[7];
set<vector<int>> ans;

int main()
{
    int n, m;
    scanf("%d%d",&n,&m);

    int numfirst = 0;
    --n; --m;

    int tmp = n;
    do
    {
        tmp /= 7;
        numfirst++;
    } while (tmp);

    int numsecond = 0;
    tmp = m;
    do
    {
        tmp /= 7;
        numsecond++;
    } while (tmp);

    if (numfirst + numsecond > 7)
    {
        printf("0\n");
        return 0;
    }

    for (int i = 0; i < 7; i++) perm[i] = i;
    do
    {
        int a = 0, b = 0;
        for (int i = 0; i < numfirst; i++)
            a = a * 7 + perm[i];
        for (int i = numfirst; i < numfirst + numsecond; i++)
            b = b * 7 + perm[i];
        if (a <= n && b <= m) ans.insert({perm, perm + numfirst + numsecond});
    } while(next_permutation(perm,perm+7));
    printf("%zd\n", ans.size());
}