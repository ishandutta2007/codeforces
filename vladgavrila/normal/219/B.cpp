#include <cstdio>

using namespace std;

long long n, mx, pt, cr, rez;

int main()
{
 //   freopen("data.in", "r", stdin);
 //   freopen("data.out", "w", stdout);

    scanf("%I64d%I64d", &n, &mx);

    pt=1;
    for(int i=0; i<=18; ++i)
    {
        cr=n-(n%pt)-1;
        while(cr+pt<=n)
            cr+=pt;

        if(n-cr<=mx && cr>0)
            rez=cr;

        pt=pt*10;
    }

    printf("%I64d\n", rez);

    return 0;
}