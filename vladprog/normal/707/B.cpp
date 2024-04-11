#include <bits/stdc++.h>

using namespace std;

struct in
{
    int u,v,l;
};

int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);;
    in a[m];
    for(int i=0;i<m;i++)
        scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].l);
    bool b[n+1];
    memset(b,0,sizeof(b));
    for(int i=0;i<k;i++)
    {
        int c;
        scanf("%d",&c);
        b[c]=true;
    }
    int ans=2e9;
    for(int i=0;i<m;i++)
        if((b[a[i].u]&&!b[a[i].v])||
           (b[a[i].v]&&!b[a[i].u]))
            ans=min(ans,a[i].l);
    printf("%d",(ans==2e9)?-1:ans);
}