#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,s;
    scanf("%d%d",&n,&s);
    pair<double,int> a[n+1];
    a[0]=make_pair(0,s);
    for(int i=1;i<=n;i++)
    {
        int x,y,k;
        scanf("%d%d%d",&x,&y,&k);
        a[i]=make_pair(sqrt(x*x+y*y),k);
    }
    sort(a,a+(n+1));
    s=0;
    for(int i=0;i<=n;i++)
        if((s+=a[i].second)>=1e6)
            printf("%.7f",a[i].first),exit(0);
    printf("-1");
}