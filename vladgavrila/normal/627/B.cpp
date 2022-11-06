#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 200010

int n, m, a, b, q, k;
int va[maxn], vb[maxn];
int aib[2][maxn];

int lsb(int x)
{
    return (x&(x-1))^x;
}

int query(int arb[], int pz)
{
    int sol=0;
    while(pz>0)
    {
        sol+=arb[pz];
        pz-=lsb(pz);
    }
    return sol;
}

void update(int arb[], int pz, int val)
{
    while(pz<=n)
    {
        arb[pz]+=val;
        pz+=lsb(pz);
    }
}

int main()
{
    scanf("%d%d%d%d%d", &n, &k, &a, &b, &q);

    while(q--)
    {
        int t, x, y;
        scanf("%d", &t);
        if(t==1)
        {
            scanf("%d%d", &x, &y);

            update(aib[0], x, min(b-vb[x], y));
            vb[x]+=min(b-vb[x], y);

            update(aib[1], n-x+1, min(a-va[x], y));
            va[x]+=min(a-va[x], y);
        }
        else
        {
            scanf("%d", &x);
            printf("%d\n", query(aib[0], x-1) + query(aib[1], n-x-k+1));
        }
    }

    return 0;
}