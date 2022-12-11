#include <bits/stdc++.h>
using namespace std;
#define Maxn 2007
int n,p[Maxn];
int que[Maxn],cnt=0;
int nxt[Maxn],pre[Maxn];
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=2*n;i++)
        scanf("%d",&p[i]);
    if (n%2==0)
    {
        int cnt=0;
        if (p[1]>p[2])
        {
            for (int i=1;i<=2*n;i+=2)
                swap(p[i],p[i+1]);
            ++cnt;
        }
        if (p[1]>p[n+1])
        {
            for (int i=1;i<=n;i++)
                swap(p[i],p[i+n]);
            ++cnt;
        }
        bool flag=true;
        for (int i=1;i<=2*n;i++)
            if (p[i]!=i) flag=false;
        if (flag) printf("%d\n",cnt); else printf("%d\n",-1);
    } else
    {
        que[1]=1;
        for (int i=2;i<=2*n;i++)
            if (que[i-1]%2==1) que[i]=que[i-1]+1;
            else if (que[i-1]<=n) que[i]=que[i-1]+n;
            else que[i]=que[i-1]-n;
        que[0]=que[2*n];
        que[2*n+1]=que[1];
        for (int i=1;i<=2*n;i++)
        {
            nxt[que[i]]=que[i+1];
            pre[que[i]]=que[i-1];
        }
        int ans=10000007;
        int r=-1;
        bool flag=true;
        for (int i=1;i<=2*n;i++)
            if (i%2==0)
            {
                int x=p[que[i]];
                int tot=0;
                int tmp=que[i];
                while (tmp!=x)
                {
                    ++tot;
                    tmp=pre[tmp];
                }
                if (r==-1) r=tot; else if (r!=tot) flag=false;
            } else
            {
                int x=p[que[i]];
                int tot=0;
                int tmp=que[i];
                while (tmp!=x)
                {
                    ++tot;
                    tmp=nxt[tmp];
                }
                if (r==-1) r=tot; else if (r!=tot) flag=false;
            }
        if (flag) ans=min(ans,r);
        r=-1;
        flag=true;
        for (int i=1;i<=2*n;i++)
            if (i%2==1)
            {
                int x=p[que[i]];
                int tot=0;
                int tmp=que[i];
                while (tmp!=x)
                {
                    ++tot;
                    tmp=pre[tmp];
                }
                if (r==-1) r=tot; else if (r!=tot) flag=false;
            } else
            {
                int x=p[que[i]];
                int tot=0;
                int tmp=que[i];
                while (tmp!=x)
                {
                    ++tot;
                    tmp=nxt[tmp];
                }
                if (r==-1) r=tot; else if (r!=tot) flag=false;
            }
        if (flag) ans=min(ans,r);
        if (ans>=3*n) printf("%d\n",-1); else printf("%d\n",ans);
    }
    return 0;
}