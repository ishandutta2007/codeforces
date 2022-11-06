#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 55

int n, k;
int v[maxn];

int main()
{
  //  freopen("data.in", "r", stdin);
  //  freopen("data.out", "w", stdout);

    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &v[i]);
        v[i]=-v[i];
    }

    sort(v+1, v+n+1);

    if(k>n)
    {
        printf("-1\n");
        return 0;
    }
    if((v[k]==v[k+1] && k<n)|| (v[k]==v[k-1] && k>1))
    {
        printf("-1\n");
        return 0;
    }

    printf("%d %d\n", -v[k], -v[k]);
    return 0;
}