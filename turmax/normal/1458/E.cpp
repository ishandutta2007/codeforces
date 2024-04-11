#include <bits/stdc++.h>

using namespace std;
#define int long long
#define x first
#define y second
map <int,int> ux,uy;set<pair<int,int> > d;
bool checkx(int x,int y)
{
    if(d.count({x,y})) return true;
    if(!ux.count(x)) return true;
     //if(x==3 && y==3) cout<<ux[x]<<" ux "<<endl;
    return ux[x]>=y;
}
bool checky(int x,int y)
{
    if(d.count({x,y})) return true;
    if(!uy.count(y)) return true;
    //if(x==3 && y==3) cout<<uy[y]<<" uy "<<endl;
    return uy[y]>=x;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    cout<<time(NULL)<<endl;mt19937 rnd;rnd.seed(time(NULL));
    #endif // LOCAL
    int n,q;cin>>n>>q;set<int> moms;pair<int,int> a[n];for(int i=0;i<n;++i) {
        #ifdef LOCAL
        a[i].x=(rnd()%30);a[i].y=(rnd()%30);cout<<a[i].x<<' '<<a[i].y<<endl;
        #else
        cin>>a[i].x>>a[i].y;
        #endif
        d.insert({a[i].x,a[i].y});moms.insert(a[i].x);moms.insert(a[i].y);if(!ux.count(a[i].x)) ux[a[i].x]=a[i].y; else ux[a[i].x]=min(ux[a[i].x],a[i].y); if(!uy.count(a[i].y)) uy[a[i].y]=a[i].x; else uy[a[i].y]=min(uy[a[i].y],a[i].x);}
    moms.insert(1e18);
    int curx=0;int cury=0;
    vector<pair<int,int> > v;
    vector<pair<int,int> > ends;
    while(true)
    {
        //cout<<curx<<" curx "<<cury<<" cury "<<endl;
        ends.push_back({curx,cury});
        if(curx>=4e9 || cury>=4e9) break;
        while(true)
        {
            if(!checkx(curx,cury)) {++curx;continue;}
            if(!checky(curx,cury)) {++cury;continue;}
            break;
        }
        //cout<<curx<<" curx "<<cury<<" cury yhrtgerfw"<<endl;
        v.push_back({curx,cury});
        ++curx;++cury;
        int o=min(*moms.lower_bound(curx)-curx,*moms.lower_bound(cury)-cury);
        curx+=o;cury+=o;
    }
    sort(v.begin(),v.end());sort(ends.begin(),ends.end());
    #ifdef LOCAL
    string s[30];
    for(int i=0;i<30;++i)
    {
        for(int j=0;j<30;++j)
        {
            pair<int,int> t={i,j};
            if(t.x==0 && t.y==0) {s[i].push_back('L');cout<<'L';continue;}
        if(d.count(t)) {s[i].push_back('L');cout<<'L';continue;}
        pair<int,int> h2=v[lower_bound(v.begin(),v.end(),t)-v.begin()];
        if(h2==t) {s[i].push_back('L');cout<<'L';continue;}
        if(upper_bound(ends.begin(),ends.end(),t)-lower_bound(ends.begin(),ends.end(),t)) {s[i].push_back('W');cout<<'W';continue;}
        pair<int,int> h=v[upper_bound(v.begin(),v.end(),t)-v.begin()-1];
        pair<int,int> o=ends[upper_bound(v.begin(),v.end(),t)-v.begin()];
        if(o.x<t.x || o.y<t.y) {s[i].push_back('W');cout<<'W';continue;}
        if(h.x-h.y==t.x-t.y) s[i].push_back('L');
        else s[i].push_back('W');
        cout<<(h.x-h.y==t.x-t.y ? 'L' : 'W');
        }
        cout<<endl;
    }
    for(int i=0;i<30;++i)
    {
        for(int j=0;j<30;++j)
        {
            if(d.count({i,j}))
            {
                assert(s[i][j]=='L');continue;
            }
            bool ok=0;for(int i1=0;i1<i;++i1) if(s[i1][j]=='L') ok=1; for(int j1=0;j1<j;++j1) if(s[i][j1]=='L') ok=1;
            if((s[i][j]=='W')!=ok)
            {
                cout<<i<<' '<<j<<endl;
            }
            assert((s[i][j]=='W')==ok);
        }
    }
    #else
    while(q--)
    {
        pair<int,int> t;cin>>t.x>>t.y;
        if(t.x==0 && t.y==0) {puts("LOSE");continue;}
        if(d.count(t)) {puts("LOSE");continue;}
        pair<int,int> h2=v[lower_bound(v.begin(),v.end(),t)-v.begin()];
        if(h2==t) {puts("LOSE");continue;}
        if(upper_bound(ends.begin(),ends.end(),t)-lower_bound(ends.begin(),ends.end(),t)) {puts("WIN");continue;}
        pair<int,int> o=ends[upper_bound(v.begin(),v.end(),t)-v.begin()];
        if(o.x<t.x || o.y<t.y) {puts("WIN");continue;}
        pair<int,int> h=v[upper_bound(v.begin(),v.end(),t)-v.begin()-1];
        puts(h.x-h.y==t.x-t.y ? "LOSE" : "WIN");
    }
    #endif
    return 0;
}
/*
5 0
20 24
19 18
24 12
27 0
24 27
*/