#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

pii h[N];
int ans[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m,x;
        cin>>n>>m>>x;
        for(int i=1;i<=n;i++)
            cin>>h[i].x,h[i].y=i;
        sort(h+1,h+n+1,greater<>());
        multiset<pii> s;
        for(int i=1;i<=m;i++)
            s.insert({0,i});
        for(int i=1;i<=n;i++)
        {
            auto[cur,pos]=*s.begin();
            s.erase(s.begin());
            s.insert({cur+h[i].x,pos});
            ans[h[i].y]=pos;
        }
        if(s.rbegin()->x-s.begin()->x<=x)
        {
            cout<<"YES\n";
            for(int i=1;i<=n;i++)
                cout<<ans[i]<<" ";
            cout<<"\n";
        }
        else
            cout<<"NO\n";
    }
}