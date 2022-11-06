#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 1000010

int n, m, cr, x, smax, ini;
int f[maxn];
char ss;

int main()
{
    scanf("%d\n", &n);
    for(int i=1; i<=n; ++i)
    {
        scanf("%c%d\n", &ss, &x);
        if(ss=='-' && f[x]==0)
            ++ini;
        if(ss=='-')
            cr--;
        else
            cr++;
        f[x]=1;
        smax=max(cr, smax);
    }

    printf("%d\n", ini+smax);

    return 0;
}