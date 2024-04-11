#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2000+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;

struct P
{
    ll x,y;
    ll k;
}p[maxn];

ll c[maxn][maxn];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld%lld",&p[i].x,&p[i].y);
    }
    for(int i=1;i<=n;i++)
    {
        ll a;
        scanf("%lld",&a);
        c[0][i]=c[i][0]=a;
    }
    for(int i=1;i<=n;i++)
        scanf("%lld",&p[i].k);

    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            ll a=(abs(p[i].x-p[j].x)+abs(p[i].y-p[j].y))*(p[i].k+p[j].k);
            c[i][j]=c[j][i]=a;
        }
    }


    ll ans=0,fast[maxn],from[maxn];
    bool vis[maxn]={0};
    memset(fast,0x3f,sizeof(fast));
    fast[0]=0;
    while(1)
    {
        ll mi=inf+1,id=-1;
        for(int i=0;i<=n;i++)
        {
            if(fast[i]<mi&&!vis[i])
            {
                mi=fast[i];
                id=i;
            }
        }

        if(id==-1)break;
        vis[id]=1;
        ans+=fast[id];

        for(int i=0;i<=n;i++)
        {
            if(vis[i])continue;
            if(c[i][id]<fast[i])
            {
                from[i]=id;
                fast[i]=c[i][id];
            }
        }
    }
    printf("%lld\n",ans);
    vector<int>v;
    for(int i=1;i<=n;i++)
    {
        if(from[i]==0)
            v.push_back(i);
    }
    printf("%d\n",v.size());
    for(int i=0;i<v.size();i++)
    {
        printf("%d ",v[i]);
    }
    puts("");
    printf("%d\n",n-v.size());
    for(int i=1;i<=n;i++)
    {
        if(from[i])
        {
            printf("%d %d\n",i,from[i]);
        }
    }
    return 0;
}