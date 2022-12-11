#include <bits/stdc++.h>
using namespace std;

int main()
{
    int vp,vd,t,f,c;
    cin>>vp>>vd>>t>>f>>c;
    double pos=vp*t;

    if (vp >= vd)
    {
        printf("0\n");
        return 0;
    }

    int ans = 0;

    for (;;)
    {
        double tt = pos / (vd - vp);
        pos += tt * vp;
        if (pos + 1e-9 >= c) break;
        ans++;
        pos += vp * (f + pos / vd);
    }

    printf("%d\n", ans);
}