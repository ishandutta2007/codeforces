#include <bits/stdc++.h>
#define fi first
#define se second
//#define mid (l+r>>1)
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=5e5+10;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;

ll hs(pii a)
{
    int gc=__gcd(a.fi,a.se);
    a.fi/=gc;
    a.se/=gc;
    return (ll)a.fi*inf+a.se;
}
int cnt=0;
map<ll,set<pii> >mp;
map<ll,int>sub;
void add(pii u,int w)
{
    cnt+=w;
    sub[hs(u)]+=w;
    if(w==-1)mp[u.fi*u.fi+u.se*u.se].erase(u);
    for(auto v:mp[u.fi*u.fi+u.se*u.se])
    {
        sub[hs({u.fi+v.fi,u.se+v.se})]+=2*w;
    }
    if(w==1)mp[u.fi*u.fi+u.se*u.se].insert(u);
}
int main()
{
//    freopen("1.txt","r",stdin);
    ios::sync_with_stdio(0),cin.tie(0);
    int q;
    cin>>q;
    while(q--)
    {
        int op;
        pii u;
        cin>>op>>u.fi>>u.se;
        if(op==1)add(u,1);
        else if(op==2)add(u,-1);
        else cout<<cnt-sub[hs(u)]<<endl;
    }
    return 0;
}