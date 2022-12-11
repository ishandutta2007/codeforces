#include <bits/stdc++.h>
using namespace std;
 
int dat[105];
 
void proc()
{
    int n, k;
    scanf("%d%d",&n,&k);
    for (int i = 0; i < n; i++) scanf("%d",&dat[i]);
    sort(dat, dat + n);
    int s = unique(dat, dat + n) - dat;
    if (s > k) printf("-1\n");
    else
    {
        printf("%d\n", k * n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < s; j++) printf("%d ", dat[j]);
            for (int j = s; j < k; j++) printf("1 ");
        }
        printf("\n");
    }
}
 
int main()
{
    int T; scanf("%d",&T);
    while (T--) proc();
}