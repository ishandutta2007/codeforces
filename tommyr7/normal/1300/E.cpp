#include <bits/stdc++.h>
#define Maxn 1000007
using namespace std;
int n,a[Maxn];
pair<double,int> q[Maxn];
int cnt=0;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        double now=1.0*a[i];
        int r=1;
        while (cnt>0&&q[cnt].first*r>=now*q[cnt].second)
        {
            r+=q[cnt].second;
            now+=q[cnt].first;
            --cnt;
        }
        q[++cnt]=make_pair(now,r);
    }
    for (int i=1;i<=cnt;i++)
        for (int j=1;j<=q[i].second;j++)
            printf("%.9lf\n",q[i].first/q[i].second);
    return 0;
}