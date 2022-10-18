#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2010,COORDS=1e6+100;

int a[N],b[N],c[N],d[N];
vector<pii> v[COORDS];
int y[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i];
    set<pii> s;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        for(auto it=s.begin();it!=s.end();)
            if(it->x<=x&&it->y<=y)
                s.erase(it++);
            else if(it->x>=x&&it->y>=y)
            {
                x=-1;
                break;
            }
            else
                it++;
        if(x!=-1)
            s.insert({x,y});
    }
    m=s.size();
    for(int i=1;i<=m;i++)
        tie(c[i],d[i])=*s.begin(),
        s.erase(s.begin());
    c[m+1]=1e9;
    d[m+1]=-1e9;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]<=c[j])
                v[c[j]-a[i]].push_back({i,j});
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]<=c[j]&&b[i]<=d[j])
                y[i]=max(y[i],d[j]-b[i]+1);
    multiset<int,greater<int>> res(y+1,y+n+1);
    int ans=1e9;
    for(int x=0;x<COORDS;x++)
    {
//        cout<<x<<" -> ";
//        for(int i=1;i<=n;i++)
//            cout<<y[i]<<" ";
//        cout<<"\n";
        ans=min(ans,x+*res.begin());
        for(auto p:v[x])
        {
            int i=p.x,j=p.y;
            res.erase(res.find(y[i]));
            y[i]=max(0ll,d[j+1]-b[i]+1);
            res.insert(y[i]);
        }
    }
    cout<<ans;
}