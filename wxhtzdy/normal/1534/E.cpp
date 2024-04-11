#include <bits/stdc++.h>
#define SZ 505
using namespace std;

int n,k,dist[SZ],prv[SZ],que[SZ],st[SZ];
int ask(vector<int> vec)
{
    printf("? ");
    for(int i=0;i<vec.size();i++) printf("%d ",vec[i]);
    printf("\n");
    fflush(stdout);
    int ret;
    scanf("%d",&ret);
    return ret;
}
void bfs()
{
    memset(dist,-1,sizeof dist);
    int t=0;
    que[++t]=0;
    dist[0]=0;
    for(int b=1;b<=t;b++)
    {
        int x=que[b];
        for(int i=0;i<=min(x,k);i++)
        {
            int j=k-i;
            if(j>n-x) continue;
            int nk=x-i+j;
            assert(0<=nk&&nk<=n);
            if(nk>=0&&nk<=n&&dist[nk]==-1)
            {
                dist[nk]=dist[x]+1;
                prv[nk]=x;
                que[++t]=nk;
            }
        }
    }
}
void rec()
{
    if(dist[n]==-1)
    {
        printf("-1");
        fflush(stdout);
        return;
    }
    int c=n;
    vector<int> vec;
    while(c!=0)
    {
        vec.push_back(c);
        c=prv[c];
    }
    vec.push_back(0);
    reverse(vec.begin(),vec.end());
    int ans=0;
    for(int i=0;i+1<vec.size();i++)
    {
        int x=0;
        while(vec[i]-x+(k-x)!=vec[i+1]) x++;
        int y=k-x;
        vector<int> qv;
        for(int j=1;j<=n;j++)
        {
            if(st[j]==1)
            {
                if(x) qv.push_back(j),x--,st[j]^=1;
            }
            else
            {
                if(y) qv.push_back(j),y--,st[j]^=1;
            }
        }
        ans^=ask(qv);
    }
    printf("! %d",ans);
    fflush(stdout);
}
int main()
{
    scanf("%d%d",&n,&k);
    bfs();
    rec();
    return 0;
}