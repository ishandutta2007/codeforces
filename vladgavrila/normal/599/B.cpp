#include <cstdio>

using namespace std;

#define maxn 100010

int n, m, x, amb;
int mp[maxn], nmp[maxn];
int sol[maxn];

int main()
{
    scanf("%d%d", &n, &m);

    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &x);
        mp[x]=i;
        ++nmp[x];
    }

    for(int i=1; i<=m; ++i)
    {
        scanf("%d", &x);
        if(nmp[x]==0)
        {
            printf("Impossible\n");
            return 0;
        }
        else
        if(nmp[x]>1)
        {
            amb=1;
        }
        else
        {
            sol[i]=mp[x];
        }
    }

    if(amb==1)
    {
        printf("Ambiguity\n");
        return 0;
    }

    printf("Possible\n");
    for(int i=1; i<=m; ++i)
        printf("%d ", sol[i]);
    printf("\n");
    return 0;
}