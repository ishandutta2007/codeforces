#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=7000+10;

struct N
{
    ll a,b;
}arr[maxn];

bool st[maxn],vis[maxn];
map<ll,int>m;
ll ans=0;

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&arr[i].a);
        m[arr[i].a]++;
    }
    for(int i=0;i<n;i++)scanf("%lld",&arr[i].b);
    for(int i=0;i<n;i++)
    {
        if(m[arr[i].a]>1)st[i]=1;
    }
    for(int i=0;i<n;i++)
    {
        if(st[i])
        {
            if(vis[i])continue;
            for(int j=0;j<n;j++)
            {
                if(vis[j])continue;
                if((arr[j].a&arr[i].a)==arr[j].a)
                {
                    ans+=arr[j].b;
                    vis[j]=1;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}