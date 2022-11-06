#include <cstdio>

using namespace std;

#define maxn 2010
#define mod 1000000007

int n, m;
int v[maxn];
int sol;

int main()
{
    scanf("%d%d", &n, &m);
    sol=1;
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &v[i]);
        v[i]=m-v[i];
        if(v[i]<0)
        {
            printf("0\n");
            return 0;
        }
    }

    for(int i=1; i<=n+1; ++i)
    {
        if(v[i]==v[i-1]+1)
            continue;
        else
        if(v[i]==v[i-1]-1)
            sol=(1LL*sol*v[i-1])%mod;
        else
        if(v[i]==v[i-1])
            sol=(1LL*sol*(v[i]+1))%mod;
        else
        {
            printf("0\n");
            return 0;
        }
    }

    printf("%d\n", sol);

    return 0;
}