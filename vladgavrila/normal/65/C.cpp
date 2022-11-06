#include <stdio.h>
#include <math.h>

using namespace std;

#define maxn 10010

int n, i, j, k, px, py, pz, vh, vp, poz;
int a[maxn], b[maxn], c[maxn];
double tsf, th, tm, lx, ly, lz, rx, ry, rz, mx, my, mz;

double dist(double ax, double ay, double az, double bx, double by, double bz)
{
    return sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by)+(az-bz)*(az-bz));
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d", &n);
    for(int i=0; i<=n; ++i)
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
    scanf("%d%d", &vp, &vh);
    scanf("%d%d%d", &px, &py, &pz);

    for(int i=1; i<=n; ++i)
    {
        th=dist(px, py, pz, a[i], b[i], c[i])/vp;
        if(tsf+dist(a[i], b[i], c[i], a[i-1], b[i-1], c[i-1])/vh>=th-0.0000001)
        {
            poz=i;
            break;
        }
        tsf+=dist(a[i], b[i], c[i], a[i-1], b[i-1], c[i-1])/vh;
    }
    if(poz==0)
    {
        printf("NO\n");
        return 0;
    }
    lx=a[poz-1]; ly=b[poz-1]; lz=c[poz-1];
    rx=a[poz]; ry=b[poz]; rz=c[poz];

    for(int pas=1; pas<=10000; ++pas)
    {
        mx=(lx+rx)/2;
        my=(ly+ry)/2;
        mz=(lz+rz)/2;
        tm=tsf+dist(a[poz-1], b[poz-1], c[poz-1], mx, my, mz)/vh;
        th=dist(px, py, pz, mx, my, mz)/vp;
        if(tm>th)
        {
            rx=mx;
            ry=my;
            rz=mz;
        }
        else
        {
            lx=mx;
            ly=my;
            lz=mz;
        }
    }
    th=dist(px, py, pz, lx, ly, lz)/vp;
    printf("YES\n%.7lf\n%.7lf %.7lf %.7lf\n", th, lx, ly, lz);
    return 0;
}