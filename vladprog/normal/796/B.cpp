#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    bool h[n+1];
    memset(h,0,sizeof(h));
    for(int i=0;i<m;i++)
    {
        int c;
        scanf("%d",&c);
        h[c]=true;
    }
    int p=1;
    for(int i=0;i<k;i++)
    {
        if(h[p])
            break;
        int u,v;
        scanf("%d%d",&u,&v);
        if(p==v)swap(u,v);
        if(p==u)p=v;
        //cout<<p<<endl;
    }
    printf("%d\n",p);
}