#include <bits/stdc++.h>
using namespace std;
int T,n;
char s[1007];
bool vis[27];
void solve()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    memset(vis,false,sizeof(vis));
    char ch=s[1];
    int tmp=1;
    for (int i=2;i<=n;i++)
        if (ch==s[i]) ++tmp;
        else
        {
            if (tmp%2==1) vis[ch-'a']=true;
            tmp=1;
            ch=s[i];
        }
    if (tmp%2==1) vis[ch-'a']=true;
    for (int i=0;i<26;i++)
        if (vis[i]) printf("%c",'a'+i);
    printf("\n");
}
int main()
{
    scanf("%d",&T);
    while (T--) solve();
    return 0;
}