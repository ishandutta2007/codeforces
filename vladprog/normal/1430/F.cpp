#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int INF=1e18;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin>>n>>k;
    vector<pair<pii,int>> v;
    while(n--)
    {
        int l,r,a;
        cin>>l>>r>>a;
        if(!v.empty())
            v.push_back({{v.back().x.y,l},0});
        v.push_back({{l,r},a});
    }
    vector<pii> prv;
    prv.push_back({k,0});
    for(auto p:v)
    {
        int l=p.x.x,r=p.x.y,a=p.y;
        vector<pii> cur;
        cur.push_back({k,INF});
        for(pii opt:prv)
        {
            int x=opt.x,y=opt.y;
            if(a>(r-l)*k+x)
                continue;
            if(x>=a)
                cur.push_back({x-a,y+a});
            else
                cur.push_back({(k-(a-x)%k)%k,y+a});
            if(l==r)
                continue;
            if(a>(r-l-1)*k+x)
                continue;
            if(x>=a)
                cur[0].y=min(cur[0].y,y+x);
            else
                cur[0].y=min(cur[0].y,y+x+(a-x+k-1)/k*k);
        }
        prv=cur;
    }
    int ans=INF;
    for(pii opt:prv)
        ans=min(ans,opt.y);
    cout<<(ans!=INF?ans:-1);
}