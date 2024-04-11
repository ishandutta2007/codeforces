#pragma GCC optimize("O3")
#include <bits/stdc++.h>

//#define int long long

using namespace std;

const int N=5e5+100;

int nxt[N],p[N];

bool solve(int l,int r,int x)
{
    for(int i=l;i<=r;i++)
    {
        if(nxt[i]>r+1)
            return false;
        if(nxt[i]==-1)
        {
            p[i]=x++;
            continue;
        }
        if(!solve(i+1,nxt[i]-1,x))
            return false;
        x+=(nxt[i]-1)-(i+1)+1;
        p[i]=x++;
        i=nxt[i]-1;
    }
    return true;
}

signed main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&nxt[i]),
            p[i]=0;
        if(solve(1,n,1))
            for(int i=1;i<=n;i++)
                printf("%d ",p[i]);
        else
            printf("-1");
        printf("\n");
    }
}