#include <stdio.h>

using namespace std;

#define maxn 1010

int n, i, j, k, rez, sol, v[maxn];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d", &n);
    v[1]=1000;
    for(int i=1; i<=n; ++i)
        scanf("%d", &v[i]);
    for(int i=1; i<=n; ++i)
    {
        sol=19999;
        for(int cif=1; cif<=9; ++cif)
        {
            rez=v[i]+((cif-(v[i]/1000)%10)*1000);
            if(rez<sol && rez>=v[i-1] && rez<=2011)
                sol=rez;
        }
        for(int cif=0; cif<=9; ++cif)
        {
            rez=v[i]+((cif-(v[i]/100)%10)*100);
            if(rez<sol && rez>=v[i-1] && rez<=2011)
                sol=rez;
        }
        for(int cif=0; cif<=9; ++cif)
        {
            rez=v[i]+((cif-(v[i]/10)%10)*10);
            if(rez<sol && rez>=v[i-1] && rez<=2011)
                sol=rez;
        }
        for(int cif=0; cif<=9; ++cif)
        {
            rez=v[i]+((cif-(v[i])%10));
            if(rez<sol && rez>=v[i-1] && rez<=2011)
                sol=rez;
        }
        if(sol==19999)
        {
            printf("No solution\n");
            return 0;
        }
        v[i]=sol;
    }
    for(int i=1; i<=n; ++i)
        printf("%d\n", v[i]);
    return 0;
}