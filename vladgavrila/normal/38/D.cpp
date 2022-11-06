#include <stdio.h>
#include <algorithm>

using namespace std;

#define maxn 110

int n, i, j, k, g;
int a1[maxn], a2[maxn], b1[maxn], b2[maxn];
int x, y;
int sp;
double xm, ym;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d%d%d%d", &a1[i], &b1[i], &a2[i], &b2[i]);
        if(a1[i]>a2[i])
            swap(a1[i], a2[i]);
        if(b1[i]>b2[i])
            swap(b1[i], b2[i]);
        x=0;
        y=0;
        sp=0;
        for(int j=i; j>=1; --j)
        {
            g=(a2[j]-a1[j])*(a2[j]-a1[j])*(a2[j]-a1[j]);
            sp+=g;
            x+=g*(a2[j]+a1[j]);
            y+=g*(b2[j]+b1[j]);
            xm=1.0*x/2/sp;
            ym=1.0*y/2/sp;
 //           printf("%.4lf %.4lf\n", xm, ym);
            if(xm<a1[j] || xm>a2[j] || ym<b1[j] || ym>b2[j])
            {
                printf("%d\n", i-1);
                return 0;
            }
            if(j>1 && (xm<a1[j-1] || xm>a2[j-1] || ym<b1[j-1] || ym>b2[j-1]))
            {
                printf("%d\n", i-1);
                return 0;
            }
        }
    }
    printf("%d\n", n);
    return 0;
}