#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

int a[3][N];
set<pii> s[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            s[i].clear();
        for(int i=1;i<=2;i++)
            for(int j=1;j<=n;j++)
                cin>>a[i][j],
                s[a[i][j]].insert({i,j});
        bool bad=false;
        for(int i=1;i<=n;i++)
            if(s[i].size()!=2)
                bad=true;
        if(bad)
        {
            cout<<-1<<"\n";
            continue;
        }
        vector<int> pos;
        for(int i=1;i<=n;i++)
        {
            vector<int> add[3];
            int cur=i;
            while(!s[cur].empty())
            {
                int x=s[cur].begin()->x,
                    y=s[cur].begin()->y;
                s[cur].erase({x,y});
                add[x].push_back(y);
                cur=a[3-x][y];
                s[cur].erase({3-x,y});
            }
//            cout<<"min("<<add[1].size()<<","<<add[2].size()<<")\n";
            if(add[1].size()<add[2].size())
                pos.insert(pos.end(),add[1].begin(),add[1].end());
            else
                pos.insert(pos.end(),add[2].begin(),add[2].end());
        }
        cout<<pos.size()<<"\n";
        for(int p:pos)
            cout<<p<<" ";
        cout<<"\n";
    }
}