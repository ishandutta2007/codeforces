#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

set<int> g[N];
bool one[N],two[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            g[i].clear(),
            one[i]=two[i]=false;
        while(m--)
        {
            int x,y;
            cin>>x>>y;
            g[x].insert(y);
        }
        set<int> close;
        for(int i=1;i<=n;i++)
            if(two[i])
                close.insert(i);
            else if(one[i])
                for(int to:g[i])
                    two[to]=true;
            else
                for(int to:g[i])
                    one[to]=true;
        cout<<close.size()<<"\n";
        for(int x:close)
            cout<<x<<" ";
        cout<<"\n";
    }
}