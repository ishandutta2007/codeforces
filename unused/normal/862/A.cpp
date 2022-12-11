#include <bits/stdc++.h>
using namespace std;

int dat[111];

int main()
{
    int n, m;
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; i++) scanf("%d",&dat[i]);

    sort(dat, dat + n);

    bool ism = binary_search(dat, dat + n, m);
    int cnt = upper_bound(dat, dat + n, m - 1) - dat;

    printf("%d\n", (m - cnt) + ism);
}