#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

using namespace __gnu_pbds;

typedef tree<int,
             null_type,
             less<int>,
             rb_tree_tag,
             tree_order_statistics_node_update>
    ord_set;


const int N=1e5+100,M=1e6;

enum Type{start,up,down,stop};

struct event
{
    Type tp;
    int x,y;
};

bool operator<(event a,event b)
{
    return pii(a.x,a.tp)<pii(b.x,b.tp);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    vector<event> scanline;
    {
        int y=0,lx=0,rx=M;
        scanline.push_back({start,lx,y});
        scanline.push_back({stop,rx,y});
    }
    {
        int y=M,lx=0,rx=M;
        scanline.push_back({start,lx,y});
        scanline.push_back({stop,rx,y});
    }
    while(n--)
    {
        int y,lx,rx;
        cin>>y>>lx>>rx;
        scanline.push_back({start,lx,y});
        scanline.push_back({stop,rx,y});
    }
    {
        int x=0,ly=0,ry=M;
        if(ly==0)
            scanline.push_back({down,x,ry});
        else
            scanline.push_back({up,x,ly});
    }
    {
        int x=M,ly=0,ry=M;
        if(ly==0)
            scanline.push_back({down,x,ry});
        else
            scanline.push_back({up,x,ly});
    }
    while(m--)
    {
        int x,ly,ry;
        cin>>x>>ly>>ry;
        if(ly==0)
            scanline.push_back({down,x,ry});
        else
            scanline.push_back({up,x,ly});
    }
    sort(scanline.begin(),scanline.end());
    ord_set s;
    int ans=1;
    for(auto e:scanline)
    {
        if(e.tp==start)
//            cout<<"start "<<e.y<<"\n",
            ans--,
            s.insert(e.y);
        else if(e.tp==stop)
//            cout<<"stop "<<e.y<<"\n",
            s.erase(e.y);
        else if(e.tp==down)
//            cout<<"down "<<e.y<<" -> "<<(s.order_of_key(e.y+1)-1)<<"\n",
            ans+=s.order_of_key(e.y+1)-1;
        else
//            cout<<"up "<<e.y<<" -> "<<(s.size()-s.order_of_key(e.y)-1)<<"\n",
            ans+=s.size()-s.order_of_key(e.y)-1;
    }
    cout<<ans;
}