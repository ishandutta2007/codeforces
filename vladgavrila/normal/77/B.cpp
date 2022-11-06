#include <cstdio>

using namespace std;

int n, m, rm;

void solve()
{
    int a, b;
    scanf("%d%d", &a, &b);

    if(b==0)
    {
        printf("1.0000000\n");
        return;
    }
    if(a==0)
    {
        printf("0.5000000\n");
        return;
    }

    rm=b*4;
    double ok, aria;
    aria=double(2.0)*a*b;
    ok=double(1.0)*a*b;
    if(rm<a)
        ok+=double(1.0)*rm*b/2.0+double(1)*(a-rm)*b;
    else
        ok+=double(1.0)*a*a/8;

    printf("%.7lf\n", ok/aria);

    return;
}


int main()
{
  //  freopen("data.in", "r", stdin);
  //  freopen("data.out", "w", stdout);

    int t;
    scanf("%d", &t);

    while(t--)
        solve();

    return 0;
}