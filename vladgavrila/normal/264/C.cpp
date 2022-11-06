#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define maxn 100010

int n, m, x, q, a, b, mx1, mx2;
int v[maxn], c[maxn];
long long cr, sol, s[maxn];

int main()
{
 //   freopen("data.in", "r", stdin);
 //   freopen("data.out", "w", stdout);

    scanf("%d%d", &n, &q);
    for(int i=1; i<=n; ++i)
        scanf("%d", &v[i]);

    for(int i=1; i<=n; ++i)
        scanf("%d", &c[i]);

    while(q--)
    {
        for(int i=1; i<=n+1; ++i)
            s[i]=-1LL*1000000000*1000000000;

        sol=0;

        scanf("%d%d", &a, &b);
        mx1=1;
        mx2=2;

        for(int i=1; i<=n; ++i)
        {
            x=c[i];

            if(mx1==x)
                cr=s[mx2];
            else
                cr=s[mx1];

            cr=max(cr, 0LL);
            cr=cr+1LL*v[i]*b;

            cr=max(cr, s[x]+1LL*v[i]*a);

            s[x]=max(s[x], cr);
            sol=max(sol, s[x]);

            if(x==mx2 || x==mx1)
            {
                if(s[mx1]<s[mx2])
                    swap(mx1, mx2);
            }
            else
            if(s[x]>s[mx1])
            {
                mx2=mx1;
                mx1=x;
            }
            else
            if(s[x]>s[mx2])
                mx2=x;
        }

        printf("%I64d\n", sol);
    }

    return 0;
}