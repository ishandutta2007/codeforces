#include <bits/stdc++.h>
#define Maxn 10007
using namespace std;
char s[Maxn];
int cnt[26];
int n;
int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    for (int i=1;i<=n;i++)
        s[n+i]=s[i];
    memset(cnt,0,sizeof(cnt));
    for (int i=1;i<=n;i++)
    {
        ++cnt[s[i]-'a'];
        if (cnt[s[i]-'a']>=n-1)
        {
            printf("Impossible\n");
            return 0;
        }
    }
    for (int i=1;i<n;i++)
    {
        bool flag=true;
        for (int j=1;j<=n;j++)
            if (s[i+j]!=s[i+n+1-j]) flag=false;
        if (flag)
        {
            for (int j=1;j<=n;j++)
                if (s[i+j]!=s[j])
                {
                    printf("%d\n",1);
                    return 0;
                }
        }
    }
    printf("%d\n",2);
    return 0;
}