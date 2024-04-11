#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5;
bool ok[maxn];set <int> a[maxn];
int ans=0;
void go(int i)
{
    ans-=ok[i];ok[i]=0;
    set <int>::iterator it=(a[i].end());
    if(a[i].empty()) {ok[i]=1;++ans;return;}
    it--;
    ok[i]=((*it)<i);
    ans+=ok[i];
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        int x,y;
        cin>>x>>y;
        x--;y--;
        a[x].insert(y);a[y].insert(x);
    }
    for(int i=0;i<n;++i) go(i);
    int q;
    cin>>q;
    while(q--)
    {
        int typ;
        cin>>typ;
        if(typ==1)
        {
            int x,y;
            cin>>x>>y;
            x--;y--;
            a[x].insert(y);a[y].insert(x);
            go(x);go(y);
        }
        if(typ==2)
        {
            int x,y;
            cin>>x>>y;
            x--;y--;
            a[x].erase(y);a[y].erase(x);
            go(x);go(y);
        }
        if(typ==3)
        {
            cout<<ans<<'\n';
        }
    }
    return 0;
}