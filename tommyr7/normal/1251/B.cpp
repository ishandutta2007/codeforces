#include <bits/stdc++.h>
using namespace std;
#define Maxn 57
int T,n,cnt1,cnt2;
char s[Maxn][Maxn];
int len[Maxn];
void solve()
{
    scanf("%d",&n);
    cnt1=0,cnt2=0;
    for (int i=1;i<=n;i++)
    {
        scanf("%s",s[i]+1);
        len[i]=strlen(s[i]+1);
        for (int j=1;j<=len[i];j++)
            if (s[i][j]=='0') ++cnt1; else ++cnt2;
        len[i]/=2;
    }
    sort(len+1,len+n+1);
    int ans=0;
    int cnt=(cnt1/2)+(cnt2/2);
    for (int i=1;i<=n;i++)
    {
        if (cnt>=len[i])
        {
            ++ans;
            cnt-=len[i];
        }
    }
    printf("%d\n",ans);
}
int main()
{
    scanf("%d",&T);
    while (T--) solve();
    return 0;
}