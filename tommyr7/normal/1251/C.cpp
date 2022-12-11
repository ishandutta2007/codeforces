#include <bits/stdc++.h>
#define Maxn 300007
using namespace std;
int T,n,len1,len2;
int a[Maxn],b[Maxn];
char s[Maxn];
void solve()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    len1=0,len2=0;
    for (int i=1;i<=n;i++)
        if ((s[i]-'0')%2==0) a[++len1]=s[i]-'0'; else b[++len2]=s[i]-'0';
    int pos1=0,pos2=0;
    while (pos1<len1||pos2<len2)
    {
        if (pos1==len1) printf("%d",b[++pos2]);
        else if (pos2==len2) printf("%d",a[++pos1]);
        else if (a[pos1+1]<b[pos2+1]) printf("%d",a[++pos1]);
        else printf("%d",b[++pos2]);
    }
    printf("\n");
}
int main()
{
    scanf("%d",&T);
    while (T--) solve();
    return 0;
}