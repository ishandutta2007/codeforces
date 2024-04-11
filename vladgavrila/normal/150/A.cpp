#include <cstdio>

using namespace std;

int n, m, k, cnt;
long long x, xs;
long long sol;

int main()
{
 //   freopen("data.in", "r", stdin);
 //   freopen("data.out", "w", stdout);

    scanf("%I64d", &x);
    xs=x;
    sol=1;

    for(int i=2; 1LL*i*i<=x; ++i)
    {
        if(x%i==0)
        {
            sol=sol*i;
            ++cnt;
            if(cnt==2)
                break;
            x=x/i;
            --i;
            continue;
        }
    }

    if(cnt<2 && x>1)
    {
        sol=sol*x;
        ++cnt;
    }

    if(cnt==2 && sol==xs)
    {
        printf("2\n");
        return 0;
    }

    if(cnt<2)
    {
        printf("1\n0\n");
        return 0;
    }

    printf("1\n%I64d\n", sol);

    return 0;
}