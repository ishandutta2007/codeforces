#include <cstdio>
#include <map>

using namespace std;

#define maxn 100010

int k, b, x, cnt, lg, n, sp;
map<int, int> mp;
long long sol, n0;

int main()
{
   // freopen("data.in", "r", stdin);
   // freopen("data.out", "w", stdout);

    scanf("%d%d%d", &k, &b, &n);
    if(b==k-1)
    {
        b=0;
        cnt=1;
    }
    else
    if(b==0)
        cnt=2;

    mp[0]=1;

    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &x);

        sp=(sp+x)%(k-1);
        sol+=mp[(sp+k-1-b)%(k-1)];
        mp[sp]=mp[sp]+1;

        if(cnt)
        {
            if(x==0)
                ++lg;
            else
            {
                n0=n0+1LL*lg*(lg+1)/2;
                lg=0;
            }
        }
    }
    n0=n0+1LL*lg*(lg+1)/2;

    sol-=n0;
    if(cnt==2)
        printf("%I64d\n", n0);
    else
        printf("%I64d\n", sol);

    return 0;
}