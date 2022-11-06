#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 100010

int n, m, st0, ok, sol, mxc;
int v[maxn], st[maxn], t[maxn];

int main()
{
  //  freopen("b.in", "r", stdin);
  //  freopen("b.out", "w", stdout);

    scanf("%d", &n);

    st0=1;

    for(int i=1; i<=n+1; ++i)
    {
        if(i<=n)
            scanf("%d", &v[i]);
        else
            v[i]=n+1;

        st[++st0]=v[i];
        t[st0]=0;

        mxc=-1;
        ok=0;
        while(st[st0]>st[st0-1] && st[st0-1]<st[st0-2])
        {
            ok=1;
            mxc=max(t[st0-1], mxc);
            st[st0-1]=st[st0];
            t[st0-1]=t[st0];
            --st0;
        }
        if(ok)
            t[st0-1]=max(t[st0-1], mxc)+1;

//        for(int j=1; j<=st0; ++j)
 //           printf("%d %d\n", st[j], t[j]);
  //      printf("\n");
    }
    for(int i=1; i<st0; ++i)
        sol=max(sol, t[i]);

    printf("%d\n", sol);

    return 0;
}