#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,t;
    scanf("%d%d",&n,&t);
    int a[n+1];
    a[0]=0;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),a[i]+=a[i-1];
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int l=i-1,r=n+1;
        while(r-l>1)
        {
            int m=(l+r)/2;
            if(a[m]-a[i-1]<=t)
                l=m;
            else
                r=m;
        }
        ans=max(ans,l-i+1);
    }
    printf("%d\n",ans);
}