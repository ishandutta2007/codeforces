#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=5e5+100,MOD=1e9+7;

int p[N];

int dsu(int x)
{
    return p[x]==x?x:p[x]=dsu(p[x]);
}

bool un(int x,int y)
{
    x=dsu(x);
    y=dsu(y);
    if(x==y)
        return false;
    if(rand()%2)
        swap(x,y);
    p[x]=y;
    return true;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        p[i]=i;
    vector<int> ans;
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        int x[3]={};
        for(int j=1;j<=k;j++)
            cin>>x[j];
        if(un(x[1],x[2]))
            ans.push_back(i);
    }
    int t=1;
    for(int i=1;i<=ans.size();i++)
        t=t*2%MOD;
    cout<<t<<" "<<ans.size()<<"\n";
    for(int x:ans)
        cout<<x<<" ";
}