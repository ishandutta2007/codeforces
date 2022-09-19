#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5;
vector <int> a[maxn];
bool used[maxn];
int parent[maxn];
int z[maxn];
int lp[maxn];
int get(int x)
{
    while(parent[x]!=(-1)) x=parent[x];
    return x;
}
int get1(int x)
{
    int o=0;
    while(parent[x]!=(-1)) {o^=z[x];x=parent[x];}
    return o;
}
void merg(int x,int y,int w)
{
    int h1=get1(x);int h2=get1(y);
    x=get(x);y=get(y);
    if(x==y) {return;}
    if(lp[x]>=lp[y]) swap(x,y);
    parent[x]=y;z[x]=(w^h1^h2);lp[y]+=lp[x];
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;++i) {a[i].clear();used[i]=false;parent[i]=(-1);lp[i]=1;z[i]=0;}
        vector <vector <int> > b;
        for(int i=0;i<n-1;++i)
        {
            int x,y,w;cin>>x>>y>>w;x--;y--;a[x].push_back(y);a[y].push_back(x);
            b.push_back({x,y,w});
            if(w!=(-1)) {merg(x,y,(__builtin_popcountll(w))%2);}
        }
        vector <vector <int> > v;
        for(int i=0;i<m;++i)
        {
            int x,y,w;cin>>x>>y>>w;x--;y--;merg(x,y,w%2);
            v.push_back({x,y,w});
        }
        bool ok=true;
        for(auto h:v)
        {
            assert(h[2]!=(-1));
            {
                int w=h[2];
                int x=h[0];int y=h[1];
                int z=(__builtin_popcountll(w))%2;
                ok=(ok && ((get1(x))^(get1(y))==z));
            }
        }
        for(auto &h:b)
        {
            if(h[2]!=(-1))
            {
                int w=h[2];
                int x=h[0];int y=h[1];
                int z=(__builtin_popcountll(w))%2;
                ok=(ok && ((get1(x))^(get1(y))==z));
            }
            else
            {
                int x=h[0];int y=h[1];
                h[2]=((get1(x))^((get1(y))));
            }
        }
        if(!ok)
        {
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        for(auto h:b)
        {
            cout<<h[0]+1<<' '<<h[1]+1<<' '<<h[2]<<endl;
        }
    }
    return 0;
}