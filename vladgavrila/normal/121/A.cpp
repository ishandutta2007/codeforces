#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 5500

int n, l, r, i, j, k, nn;
long long v[maxn], nc[maxn];
long long sol;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif

    scanf("%d%d", &l, &r);
    --l;
    v[1]=4;
    v[2]=7;
    nc[1]=nc[2]=1;
    nn=2;
    for(int i=1; i<=nn; ++i)
    {
        if(nc[i]==10)
            break;
        v[++nn]=v[i]*10+4;
        nc[nn]=nc[i]+1;
        v[++nn]=v[i]*10+7;
        nc[nn]=nc[i]+1;
    }

    sol=0;

    for(int i=1; i<=nn; ++i)
        sol=sol+1LL*max(min(1LL*r, v[i])-max(v[i-1], 1LL*l), 1LL*0)*v[i];

    printf("%I64d\n", sol);

    return 0;
}