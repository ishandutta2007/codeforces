#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=3e5+100;

vector<int> g[N];

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
            g[i].clear();
        for(int i=1;i<=m;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        set<int> teachers,now,nxt;
        nxt.insert(1);
        while(!nxt.empty())
        {
            int cur=*nxt.begin();
            nxt.erase(nxt.begin());
            teachers.insert(cur);
            now.insert(cur);
            for(int student:g[cur])
                if(!now.count(student))
                {
                    now.insert(student);
                    nxt.erase(student);
                    for(int add:g[student])
                        if(!now.count(add))
                            nxt.insert(add);
                }
        }
        if(now.size()==n)
        {
            cout<<"YES\n";
            cout<<teachers.size()<<"\n";
            for(int t:teachers)
                cout<<t<<" ";
            cout<<"\n";
        }
        else
            cout<<"NO\n";
    }
}