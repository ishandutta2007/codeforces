#include <bits/stdc++.h>
#define x first
#define y second
#define mid (l+r>>1)
#define lo (o<<1)
#define ro (o<<1|1)
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<double,double> pii;
struct tri{int x,y,z;};
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int maxn=1e5+10;
const ll mod=1e9+7;
const double PI=acos(0)*2;

vi edg[maxn];
int ma[maxn],n;
int dfs(int u,int f)
{
    int ret=1;
    for(auto v:edg[u])if(v!=f)
    {
        int a=dfs(v,u);
        ret+=a;
        ma[u]=max(ma[u],a);
    }
    ma[u]=max(ma[u],n-ret);
    return ret;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        edg[i].clear();
        ma[i]=0;
    }
    for(int i=0;i<n-1;i++)
    {
        int a,b;cin>>a>>b;
        edg[a].push_back(b);
        edg[b].push_back(a);
    }
    dfs(1,0);
    vi p;
    int mi=n;
    for(int i=1;i<=n;i++)
    {
        if(ma[i]<mi)
        {
            p.clear();
            p.push_back(i);
            mi=ma[i];
        }
        else if(ma[i]==mi)
        {
            p.push_back(i);
        }
    }
    if(p.size()==1)
    {
        cout<<1<<' '<<edg[1][0]<<endl;
        cout<<1<<' '<<edg[1][0]<<endl;
        return;
    }

    int a;
    for(auto i:edg[p[0]])
    {
        if(i!=p[1])
        {
            a=i;
            break;
        }
    }
    cout<<p[0]<<' '<<a<<endl;
    cout<<p[1]<<' '<<a<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
//    freopen("in.txt","r",stdin);
    int _;cin>>_;
    while(_--)solve();
    return 0;
}