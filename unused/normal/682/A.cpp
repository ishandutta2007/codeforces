#include <bits/stdc++.h>
using namespace std;

long long c1[5], c2[5];

int main()
{
    int n, m;
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++) c1[i%5]++;
    for (int i = 1; i <= m; i++) c2[i%5]++;
    printf("%lld\n",
        c1[0]*c2[0]+c1[1]*c2[4]+c1[2]*c2[3]+c1[3]*c2[2]+c1[4]*c2[1]
        );
}