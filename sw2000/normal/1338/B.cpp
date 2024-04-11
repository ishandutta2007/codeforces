#include <bits/stdc++.h>
#define x first
#define y second
#define mid (l + r >> 1)
#define lo (o << 1)
#define ro (lo | 1)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct tri{int x,y,z;};

vi v[maxn];
int mi=1,ma,last=3,sum[maxn];

void dfs(int o,int f,int d)
{
    if(v[o].size()==1)
    {
        if(((d&1)^last)==1)mi=3;
        last=d&1;
        sum[f]++;
    }

    for(auto i:v[o])if(i!=f)
    {
        dfs(i,o,d+1);
    }
    if(sum[o])
    {
        ma-=sum[o]-1;
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
    int n;scanf("%d",&n);
    ma=n-1;
    for(int i=1;i<n;i++)
    {
        int a,b;scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int o;
    for(int i=1;i<=n;i++)
    {
        if(v[i].size()!=1)
        {
            o=i;
            break;
        }
    }

    dfs(o,0,0);

    printf("%d %d",mi,ma);
    return 0;
}