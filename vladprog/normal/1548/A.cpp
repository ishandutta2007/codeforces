#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

int cnt[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    int ans=n;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        ans-=!(cnt[min(u,v)]++);
    }
    int q;
    cin>>q;
    while(q--)
    {
        int tp;
        cin>>tp;
        if(tp==3)
            cout<<ans<<"\n";
        else
        {
            int u,v;
            cin>>u>>v;
            if(tp==1)
                ans-=!(cnt[min(u,v)]++);
            else
                ans+=!(--cnt[min(u,v)]);
        }
    }
}