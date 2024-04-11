#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100,INF=2e9;

int h[N],w[N];

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
        map<pii,int> m;
        for(int i=1;i<=n;i++)
            cin>>h[i]>>w[i],
            m[{h[i],w[i]}]=m[{w[i],h[i]}]=i;
        set<pii> s{{-INF,INF},{INF,-INF}};
        for(int i=1;i<=n;i++)
        {
            auto it=s.lower_bound({h[i],w[i]});
            while(it->y>w[i])
                s.erase(it++);
            if(prev(it)->y>w[i])
                s.insert({h[i],w[i]});

            it=s.lower_bound({w[i],h[i]});
            while(it->y>h[i])
                s.erase(it++);
            if(prev(it)->y>h[i])
                s.insert({w[i],h[i]});
        }
        for(int i=1;i<=n;i++)
        {
            auto it=prev(s.lower_bound({h[i],-INF}));
            if(it->y<w[i])
            {
                cout<<m[*it]<<" ";
                continue;
            }
            it=prev(s.lower_bound({w[i],-INF}));
            if(it->y<h[i])
            {
                cout<<m[*it]<<" ";
                continue;
            }
            cout<<-1<<" ";
        }
        cout<<"\n";
    }
}