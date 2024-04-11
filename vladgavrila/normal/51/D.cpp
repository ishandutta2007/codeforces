#include <stdio.h>

using namespace std;

#define maxn 100010

int n, i, j, k, ok;
int v[maxn], pa[maxn], pb[maxn];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
        scanf("%d", &v[i]);
    pa[1]=pa[2]=1;
    if(v[1]==0 && v[2]!=0)
        pa[2]=0;
    for(int i=3; i<=n; ++i)
        if(v[i]*v[i-2]==v[i-1]*v[i-1] && pa[i-1]==1 && !(v[i-1]==0 && v[i]!=0))
            pa[i]=1;
        else
            break;
    pb[n]=pb[n-1]=1;
    for(int i=n-2; i; --i)
        if(v[i]*v[i+2]==v[i+1]*v[i+1] && !(v[i+2]!=0 && v[i+1]==0))
            pb[i]=1;
        else
            break;
    if(pa[n]==1)
    {
        printf("0\n");
        return 0;
    }
    if(pb[2]==1 || pa[n-1]==1)
    {
        printf("1\n");
        return 0;
    }
    for(int i=2; i<n; ++i)
    {
        if(pa[i-1]==1 && pb[i+1]==1)
        {
            ok=1;
            if(i>2 && !(v[i-2]*v[i+1]==v[i-1]*v[i-1] && !(v[i-2]==0 && v[i-1]!=0)))
                ok=0;
            if(i<n-1 && !(v[i+1]*v[i+1]==v[i-1]*v[i+2] && !(v[i+1]==0 && v[i+2]!=0)))
                ok=0;
            if(v[i-1]==0 && v[i+1]!=0)
                ok=0;
            if(i>2 && i<n-1 && v[i-2]*v[i+2]!=v[i-1]*v[i+1])
                ok=0;
            if(ok)
            {
                printf("1\n");
                return 0;
            }
        }
    }
    printf("2\n");
    return 0;
}