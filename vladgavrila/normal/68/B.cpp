#include <stdio.h>

using namespace std;

#define maxn 10010

int n, i, j, k;
double sol, left, right, med, plus, minus;
int v[maxn];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d%d", &n, &k);

    k=100-k;
    for(int i=1; i<=n; ++i)
        scanf("%d", &v[i]);

    left=0;
    right=1000;
    for(int pas=1; pas<=1000; ++pas)
    {
        med=(left+right)/2;
        plus=minus=0;
        for(int i=1; i<=n; ++i)
        {
            if(v[i]>=med)
                plus+=v[i]-med;
            else
                minus+=med-v[i];
        }
        if(plus*k/100>minus)
            left=med;
        else
            right=med;
    }
    printf("%.9lf\n", left);
    return 0;
}