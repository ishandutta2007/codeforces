#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=110;

int a[N][N];

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
            for(int j=1;j<=m;j++)
                cin>>a[i][j];
        int ans=0;
        for(int i1=1,i2=n;i1<=i2;i1++,i2--)
            for(int j1=1,j2=m;j1<=j2;j1++,j2--)
            {
                set<pii> s{{i1,j1},{i1,j2},{i2,j1},{i2,j2}};
                vector<int> v;
                for(auto p:s)
                    v.push_back(a[p.x][p.y]);
                sort(v.begin(),v.end());
                for(int k1=0,k2=v.size()-1;k1<k2;k1++,k2--)
                    ans+=v[k2]-v[k1];
            }
        cout<<ans<<"\n";
    }
}