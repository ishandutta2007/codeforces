#include <bits/stdc++.h>
#define Maxn 1000007
using namespace std;
char s1[Maxn],s2[Maxn];
int len1,len2;
int sum[Maxn];
int main()
{
    scanf("%s",s1+1);
    len1=strlen(s1+1);
    scanf("%s",s2+1);
    len2=strlen(s2+1);
    for (int i=1;i<=len1;i++)
        if (s1[i]=='1') sum[i]=sum[i-1]+1; else sum[i]=sum[i-1];
    int t=0;
    for (int i=1;i<=len2;i++)
        if (s2[i]=='1') ++t;
    int ans=0;
    for (int i=1;i<=len1-len2+1;i++)
        if ((sum[i+len2-1]-sum[i-1]+t)%2==0) ++ans;
    printf("%d\n",ans);
    return 0;
}