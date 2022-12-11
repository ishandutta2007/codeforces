#include <bits/stdc++.h>
#define Maxn 5000007
using namespace std;
int T,n;
int last[Maxn],other[Maxn],pre[Maxn],cnt=0;
int d[Maxn];
bool flag[Maxn];
char ch[Maxn];
void insert(int u,int v)
{
    other[++cnt]=v,pre[cnt]=last[u],last[u]=cnt;
    ++d[u];
}
void work()
{
    scanf("%d",&n);
    for (int i=1;i<=10*n;i++)
    {
        last[i]=0;
        other[i]=0;
        pre[i]=0;
        d[i]=0;
        flag[i]=true;
    }
    cnt=0;
    for (int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        insert(u,v),insert(v,u);
    }
    scanf("%s",ch+1);
    int now=n;
    for (int i=1;i<=n;i++)
        if (ch[i]=='W') 
        {
            insert(i,now+1),insert(now+1,i);
            insert(now+1,now+2),insert(now+2,now+1);
            insert(now+1,now+3),insert(now+3,now+1);
            now+=3;
        }
    n=now;
    int mx=0;
    for (int i=1;i<=n;i++)
        mx=max(mx,d[i]);
    if (mx>=4) printf("White\n");
    else if (mx<=2) printf("Draw\n");
    else
    {
        bool res=false;
        int cnt0=0;
        for (int i=1;i<=n;i++)
            if (d[i]==3) ++cnt0;
        if (cnt0>=3) res=true;
        for (int i=1;i<=n;i++)
            if (d[i]==1) flag[i]=false;
        for (int i=1;i<=n;i++)
        {
            int cnt=0;
            for (int q=last[i];q;q=pre[q])
            {
                int v=other[q];
                if (flag[v]) ++cnt;
            }
            if (cnt>=2&&d[i]==3) res=true;
        }
        int cnt1=0;
        for (int i=1;i<=n;i++)
            if (d[i]==2) ++cnt1;
        if (cnt1%2==1&&cnt0==2) res=true;
        if (res) printf("White\n"); else printf("Draw\n");
    }
}
int main()
{
    scanf("%d",&T);
    while (T--) work();
    return 0;
}