#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int maxn=2e3+10;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
const ll linf=0x3f3f3f3f3f3f3f3f;

vector<int>e[maxn];
int n,c[maxn],sum[maxn],ans[maxn];

void init(int o)
{
    sum[o]=1;
    for(auto i:e[o])
    {
        init(i);
        sum[o]+=sum[i];
    }
}

void dfs(int o,vector<int>v)
{
    ans[o]=v[c[o]];
    int id=0;
    for(auto i:e[o])
    {
        vector<int>tmp;
        for(int j=0;j<sum[i];j++)
        {
            if(id==c[o])id++;
            tmp.push_back(v[id]);
            id++;
        }
        dfs(i,tmp);
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
    cin>>n;
    int o;
    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        c[i]=b;
        if(!a)o=i;
        e[a].push_back(i);
    }
    init(0);
    vector<int>v;
    for(int i=1;i<=n;i++)
    {
        v.push_back(i);
        if(sum[i]<=c[i])
        {
            printf("NO");
            return 0;
        }
    }
    dfs(o,v);
    puts("YES");
    for(int i=1;i<=n;i++)printf("%d ",ans[i]);
    return 0;
}