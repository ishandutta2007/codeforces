#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int tl=100,tr=1;
    for(int i=0;i<n;i++)
    {
        int t;
        scanf("%d",&t);
        tl=min(tl,t);
        tr=max(tr,t);
    }
    int v=max(tr,2*tl);
    for(int i=0;i<m;i++)
    {
        int f;
        scanf("%d",&f);
        if(f<=v)
            printf("-1"),exit(0);
    }
    printf("%d",v);
}