#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

#define maxn 1000010

int n, m, sol, a, b, mx;
int v[maxn], l[maxn], r[maxn], nap[maxn];

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &v[i]);

        ++nap[v[i]];
        if(nap[v[i]]>mx)
            mx=nap[v[i]];

        if(l[v[i]]==0)
            l[v[i]]=i;

        r[v[i]]=i;
    }

    sol=1000000000;

    for(int i=1; i<=n; ++i)
    {
        if(nap[v[i]]==mx && r[v[i]]-l[v[i]]<sol)
        {
            a=l[v[i]];
            b=r[v[i]];
            sol=b-a;
        }
    }

    printf("%d %d\n", a, b);

    return 0;
}