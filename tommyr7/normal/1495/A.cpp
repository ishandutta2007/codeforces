#include <bits/stdc++.h>
using namespace std;
#define Maxn 100007
int T,n;
int x[Maxn],y[Maxn],cnt1=0,cnt2=0;
void solve()
{
    scanf("%d",&n);
    cnt1=0;
    cnt2=0;
    for (int i=1;i<=2*n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if (a==0) y[++cnt2]=abs(b); else x[++cnt1]=abs(a);
    }
    sort(x+1,x+n+1);
    sort(y+1,y+n+1);
    double ans=0.0;
    for (int i=1;i<=n;i++)
        ans+=1.0*(double)sqrt(1.0*x[i]*x[i]+1.0*y[i]*y[i]);
    printf("%.15lf\n",ans);
}
int main()
{
    scanf("%d",&T);
    while (T--) solve();
    return 0;
}