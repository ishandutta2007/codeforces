#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e5+5;
vector <int> a[maxn];
int top[maxn];
bool used[maxn];
int pr[maxn];
int pt[maxn];
int deq[maxn];
int cnt1[maxn];
int deq1[maxn];
vector <int> l;
vector <vector <int> > o;
vector <vector <int> > z;
void dfs(int x)
{
    //cout<<x<<" x "<<endl;
    used[x]=true;int cnt=0;top[x]=x;
    for(auto v:a[x]) {if(!used[v]) {dfs(v);if(cnt<=1 && cnt1[v]<=1) {++cnt;top[v]=x;cnt1[x]++;}}}
    l.push_back(x);
    used[x]=false;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        z.resize(n);
        l.clear();o.clear();
        for(int i=0;i<n;++i) {a[i].clear();top[i]=i;used[i]=false;pr[i]=(-1);pt[i]=(-1);z[i].clear();cnt1[i]=0;deq1[i]=0;}
        vector <pair<int,int> > b;
        vector <pair<int,int> > ans1,ans2;
        for(int i=0;i<(n-1);++i) {int x,y;cin>>x>>y;x--;y--;b.push_back({x,y});a[x].push_back(y);a[y].push_back(x);}
        dfs(0);
        reverse(l.begin(),l.end());for(auto h:l) {if(top[h]!=h) top[h]=top[top[h]];} reverse(l.begin(),l.end());
        for(auto i:l) {z[top[i]].push_back(i);}
        for(auto h:z)
        {
            if(!h.empty())
            {
                vector <int> z;
                if(h.size()>=2)
                {
                    for(auto l:h) used[l]=true;
                    for(auto l:h) for(auto l1:a[l]) deq1[l]+=used[l1];
                    for(auto l:h)
                    {
                        if(deq1[l]==1)
                        {
                            z.push_back(l);
                        }
                    }
                    for(auto l:h) used[l]=false;
                }
                else z.push_back(h[0]);
                o.push_back(z);
            }
        }
        for(auto h:b) if(top[h.first]!=top[h.second]) ans1.push_back(h);
        for(int i=0;i<o.size()-1;++i) ans2.push_back({o[i].back(),o[i+1][0]});
        assert(ans1.size()==ans2.size());
        cout<<ans1.size()<<endl;
        for(int i=0;i<ans1.size();++i) cout<<ans1[i].first+1<<' '<<ans1[i].second+1<<' '<<ans2[i].first+1<<' '<<ans2[i].second+1<<endl;
    }
    return 0;
}