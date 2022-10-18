#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=30;

bool b[N][N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int h,w;
        cin>>h>>w;
        vector<pii> v;
        for(int i=1;i<=h;i++)
            v.push_back({i,1});
        for(int j=2;j<=w;j++)
            v.push_back({h,j});
        for(int i=h-1;i>=1;i--)
            v.push_back({i,w});
        for(int j=w-1;j>=2;j--)
            v.push_back({1,j});
        for(int i=0;i<=h+1;i++)
            for(int j=0;j<=w+1;j++)
                b[i][j]=false;
        for(auto[x,y]:v)
        {
            bool ok=true;
            for(int i=x-1;i<=x+1;i++)
                for(int j=y-1;j<=y+1;j++)
                    if(b[i][j])
                        ok=false;
            if(ok)
                b[x][y]=true;
        }
        for(int i=1;i<=h;i++,cout<<"\n")
            for(int j=1;j<=w;j++)
                cout<<b[i][j];
        cout<<"\n";
    }
}