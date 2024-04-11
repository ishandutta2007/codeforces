#include <bits/stdc++.h>
#define Maxn 200007
using namespace std;
int T,n;
char ch[Maxn];
void solve()
{
    scanf("%s",ch+1);
    n=strlen(ch+1);
    int ans=n-2;
    for (int i=0;i<10;i++)
        for (int j=0;j<10;j++)
        {
            int tmp=0;
            int now=i;
            for (int k=1;k<=n;k++)
                if (ch[k]-'0'==now)
                {
                    ++tmp;
                    now=i+j-now;
                }
            if (i!=j&&tmp%2==1) --tmp;
            ans=min(ans,n-tmp);
        }
    printf("%d\n",ans);
}
int main()
{
    scanf("%d",&T);
    while (T--) solve();
    return 0;
}