#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int INF=1e9;

vector<int> pos[4];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        pos[a].push_back(i);
    }
    for(int i=1;i<4;i++)
        pos[i].push_back(INF),
        reverse(pos[i].begin(),pos[i].end());
    vector<pii> ans;
    int rows=0;
    while(true)
    {
        vector<int> three;
        while(pos[3].back()<pos[2].back()&&
              pos[3].back()<pos[1].back())
            three.push_back(pos[3].back()),
            pos[3].pop_back();
        int two=pos[2].back();
        int one=pos[1].back();
        if(two>one)
            two=INF;
        if(one==INF)
        {
            if(!three.empty())
                cout<<-1,exit(0);
            break;
        }
        int last=INF;
        for(int x:three)
        {
            if(last!=INF)
                ans.push_back({last,x});
            last=++rows;
            ans.push_back({last,x});
        }
        if(two!=INF)
        {
            if(last!=INF)
                ans.push_back({last,two});
            last=++rows;
            ans.push_back({last,two});

            if(last!=INF)
                ans.push_back({last,one});
        }
        else
        {
            if(last!=INF)
                ans.push_back({last,one});
            last=++rows;
            ans.push_back({last,one});
        }
        if(two!=INF)
            pos[2].pop_back();
        if(one!=INF)
            pos[1].pop_back();
    }
    if(pos[1].back()!=INF||
       pos[2].back()!=INF||
       pos[3].back()!=INF||
       rows>n)
        cout<<-1,exit(0);
    cout<<ans.size()<<"\n";
    for(auto p:ans)
        cout<<p.x<<" "<<p.y<<"\n";
}