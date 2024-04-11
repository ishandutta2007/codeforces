#include <bits/stdc++.h>
using namespace std;
int t,n;
int main()
{
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        bool flag=true;
        int now=n+1;
        while (now>1)
        {
            if (now%2!=0) flag=false;
            now/=2;
        }
        if (flag)
        {
            int ans=1;
            for (int i=2;i*i<=n;i++)
                if (n%i==0) ans=max(ans,n/i);
            printf("%d\n",ans);
        } else
        {
            int ans=1;
            while (ans<=n) ans*=2;
            --ans;
            printf("%d\n",ans);
        }
    }
    return 0;
}