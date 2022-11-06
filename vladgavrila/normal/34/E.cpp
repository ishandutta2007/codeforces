#include <stdio.h>
#include <algorithm>

using namespace std;

#define maxn 100

int n, i, j, k, t, b1, b2, ind[maxn];
double tc, vn1, vn2, v[maxn], tmin, m[maxn], x[maxn];

inline int cmp(int a, int b)
{
    return x[a]<x[b];
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d%d", &n, &t);
    for(int i=1; i<=n; ++i)
    {
        scanf("%lf%lf%lf", &x[i], &v[i], &m[i]);
        ind[i]=i;
    }
    sort(ind+1, ind+n+1, cmp);
    while(1)
    {
        tmin=1000000;
        for(int i=1; i<n; ++i)
        {
            if(v[ind[i]]>v[ind[i+1]])
            {
                if((x[ind[i+1]]-x[ind[i]])/(v[ind[i]]-v[ind[i+1]])<tmin)
                {
                    tmin=(x[ind[i+1]]-x[ind[i]])/(v[ind[i]]-v[ind[i+1]]);
                    b1=ind[i];
                    b2=ind[i+1];
                }
            }
        }
        if(tc+tmin>t)
            break;
        tc+=tmin;
        for(int i=1; i<=n; ++i)
            x[i]=x[i]+v[i]*tmin;
        vn1=((m[b1]-m[b2])*v[b1]+2*m[b2]*v[b2])/(m[b1]+m[b2]);
        vn2=((m[b2]-m[b1])*v[b2]+2*m[b1]*v[b1])/(m[b1]+m[b2]);
        v[b1]=vn1;
        v[b2]=vn2;
    }
    for(int i=1; i<=n; ++i)
        x[i]=x[i]+v[i]*((double)t-tc);
    for(int i=1; i<=n; ++i)
        printf("%.6lf\n", x[i]);
    return 0;
}