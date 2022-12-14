#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=2e5+10;
const ll mod=1e9+7;
int n;
struct Edg
{
    int v,w;
};
vector<Edg>v[maxn];

ll gg;
ll bb;
int dfs(int o,int f)
{
    int ret=1;
    for(auto i:v[o])if(i.v!=f)
    {
        int sum=dfs(i.v,o);
        if(sum&1)gg+=i.w;
        bb+=(ll)min(sum,n-sum)*i.w;
        ret+=sum;
    }
    return ret;
}

int main()
{
//    freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        n*=2;
        for(int i=0;i<n-1;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            v[a].push_back({b,c});
            v[b].push_back({a,c});
        }
        dfs(1,0);
        printf("%lld %lld\n",gg,bb);

        for(int i=1;i<=n;i++)
        {
            v[i].clear();
        }
        gg=bb=0;
    }
    return 0;
}