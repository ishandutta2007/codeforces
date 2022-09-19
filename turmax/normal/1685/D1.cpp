#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=205;
int par[maxn];
int get(int x)
{
    if(par[x]==(-1)) return x;
    int ans=get(par[x]);par[x]=ans;return ans;
}
void merg(int x,int y)
{
    x=get(x);y=get(y);if(x==y) return; par[x]=y;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;for(int i=0;i<n;++i) par[i]=(-1);int a[n];for(int i=0;i<n;++i) {cin>>a[i];--a[i];} int a1[n];for(int i=0;i<n;++i) a1[a[i]]=i;
        bool used[n]={0};int b[n];vector<int> d[n];
        for(int i=0;i<n;++i) {if(!used[i]) {b[i]=i;used[i]=true;int x=i;while(a[x]!=i) {x=a[x];used[x]=true;b[x]=i;}}}
        for(int i=0;i<n;++i) {d[b[i]].push_back(i);}
        vector<pair<int,pair<int,int> > > z;
        for(int i=0;i<n;++i) for(int j=i+1;j<n;++j)
        {
            if(!d[i].empty() && !d[j].empty())
            {
                int u=(-1),v;
                for(int k:d[i])
                {
                    for(int l:d[j])
                    {
                        if(u==(-1) || abs(k-l)<abs(u-v))
                        {
                            u=k;v=l;
                        }
                    }
                }
                z.push_back({abs(u-v),{u,v}});
            }
        }
        int u[n];
        for(int i=0;i<n;++i) {u[i]=a1[i];}
        sort(z.begin(),z.end());
        for(auto h:z)
        {
            if(get(b[h.second.first])!=get(b[h.second.second]))
            {
                merg(b[h.second.first],b[h.second.second]);
                swap(u[h.second.first],u[h.second.second]);
            }
        }
        vector<int> res;int x=0;
        while(true)
        {
            res.push_back(x);x=u[x];if(x==0) break;
        }
        for(auto h:res) cout<<h+1<<' ';
        cout<<'\n';
    }
    return 0;
}