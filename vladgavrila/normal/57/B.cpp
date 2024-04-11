#include <stdio.h>

using namespace std;

#define maxn 100010

int n, m, i, j, k, a, b, c;
long long s1[maxn], s2[maxn], s3[maxn], sol;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d%d%d", &n, &m, &k);
    for(int i=1; i<=m; ++i)
    {
        scanf("%d%d%d", &a, &b, &c);
        s1[a]++;
        s1[b+1]--;
        s2[a]+=c-1;
        s2[b+1]-=c-1;
        s3[b+1]-=(b-a+1);
    }
    for(int i=1; i<=n; ++i)
    {
        s1[i]=s1[i-1]+s1[i];
        s2[i]=s2[i-1]+s2[i];
    }
    for(int i=1; i<=n; ++i)
        s1[i]=s1[i]+s1[i-1]+s3[i];

    for(int i=1; i<=k; ++i)
    {
        scanf("%d", &a);
        sol=sol+s1[a]+s2[a];
    }
    printf("%I64d\n", sol);
    return 0;
}