#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<double,double> pii;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int maxn=1e5+10;
const ll mod=1e9+7;
const double PI=acos(0)*2;

vi v[maxn];
int ma;
int dfs(int u,int f)
{
    int a=0,b=0;
    for(auto uu:v[u])if(uu!=f)
    {
        int tmp=dfs(uu,u);
        if(tmp>a)
        {
            b=a;
            a=tmp;
        }
        else if(tmp>b)
        {
            b=tmp;
        }
    }
    ma=max(ma,a+b);
    return a+1;
}
int dis(int a,int b,int f)
{
    if(a==b)return 0;
    for(auto i:v[a])if(i!=f)
    {
        int tmp=dis(i,b,a);
        if(tmp>=0)return tmp+1;
    }
    return -inf;
}
bool solve()
{
    int n,a,b,da,db;
    scanf("%d%d%d%d%d",&n,&a,&b,&da,&db);
    for(int i=1;i<=n;i++)
    {
        v[i].clear();
    }
    ma=0;
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    if(dis(a,b,0)<=da)return 1;
    dfs(1,0);
//    cout<<ma<<endl;
    db=min(db,ma);
    if(da*2>=db)return 1;
    return 0;
}

int main()
{
//    freopen("in.txt","r",stdin);
    int _;cin>>_;
    while(_--)
    {
        if(solve())puts("Alice");
        else puts("Bob");
    }
    return 0;
}