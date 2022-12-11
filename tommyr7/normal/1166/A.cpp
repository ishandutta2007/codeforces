#include <bits/stdc++.h>
#define Maxn 107
using namespace std;
int n;
int cnt[Maxn];
char s[Maxn];
int ans=0;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%s",s+1);
        ++cnt[s[1]-'a'];
    }
    for (int i=0;i<26;i++)
    {
        int x=cnt[i]/2,y=cnt[i]-cnt[i]/2;
        ans+=(x*(x-1))/2+(y*(y-1))/2;
    }
    printf("%d\n",ans);
    return 0;
}