#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int n, d, a, t, v;
double sp, sc, tvm;

int main()
{
  //  freopen("data.in", "r", stdin);
  //  freopen("data.out", "w", stdout);

    scanf("%d%d%d", &n, &a, &d);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d%d", &t, &v);

        tvm=(double)v/a;
        if(tvm*tvm*a/2<d)
            sc=(1.0*d-tvm*tvm*a/2)/v+t+tvm;
        else
            sc=sqrt((double)2.0*d/a)+t;

        sp=max(sp, sc);
        printf("%.6lf\n", sp);
    }

    return 0;
}