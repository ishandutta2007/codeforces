#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 100010

int n, m, x, pz, ok, cnt, sol;
int v[maxn];

int main()
{
  //  freopen("data.in", "r", stdin);
  //  freopen("data.out", "w", stdout);

    scanf("%d", &m);
    pz=1000000;
    while(m--)
    {
        scanf("%d", &x);
        pz=min(pz, x);
    }

    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
        scanf("%d", &v[i]);

    sort(v+1, v+n+1);

    for(int i=n; i; --i)
    {
        if(ok>0)
        {
            ok--;
            continue;
        }
        ++cnt;
        sol+=v[i];
        if(cnt==pz)
        {
            ok=2;
            cnt=0;
        }
    }

    printf("%d\n", sol);

    return 0;
}