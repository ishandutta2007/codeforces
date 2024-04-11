#include <bits/stdc++.h>

using namespace std;
#define int long long
map <int,int> u;
map<int,int> l;
map<pair<int,int>,int> cnt1;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    mt19937_64 rnd;rnd.seed(228);
    int t;cin>>t;
    while(t--)
    {
        int n,m;cin>>n>>m;vector<int> a[n];int hsh[m]={0};bool ok1[m];int val=0;for(int i=0;i<m;++i) ok1[i]=1;for(int i=0;i<n;++i) {a[i].resize(m);for(int j=0;j<m;++j) cin>>a[i][j];}
        bool ok=true;
        cnt1.clear();int cnt2=0;
        for(int i=0;i<n;++i)
        {
            u.clear();
             vector<int> d=a[i];sort(d.begin(),d.end());vector<int> ids;
             for(int j=0;j<m;++j)
             {
                 u[d[j]]=rnd();
                 if(a[i][j]!=d[j]) ids.push_back(j);
             }
             if(ids.size()>=3) {ok=false;break;}
             if(ids.size()==1) assert(false);
             if(ids.empty())
             {
                 for(int j=0;j<m;++j)
                 {
                     hsh[j]^=u[a[i][j]];
                 }
             }
             else
             {
                 cnt2++;cnt1[{min(ids[0],ids[1]),max(ids[0],ids[1])}]++;
             }
        }
        //cout<<val<<' '<<hsh[0]<<' '<<hsh[1]<<" hshs "<<endl;
        if(!ok) {cout<<(-1)<<'\n';continue;}
        bool ok2=false;
        l.clear();
        if(!cnt2)
        {
            cnt1[{0,0}]=0;
        }
        for(auto [key,val]:cnt1)
        {
            int u=key.first;int v=key.second;
            if(cnt1[{u,v}]==cnt2 && hsh[u]==hsh[v]) {cout<<u+1<<' '<<v+1<<'\n';ok2=true;break;}
        }
        if(!ok2) cout<<(-1)<<'\n';
    }
    return 0;
}