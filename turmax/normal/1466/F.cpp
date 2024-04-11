#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;
const int maxn=5e5+5;
int parent[maxn];
bool ok[maxn];
vector <int> ans;
int sz;
int get1(int x)
{
    if(parent[x]==(-1))
    {
        return x;
    }
    int ans=get1(parent[x]);
    parent[x]=ans;
    return ans;
}
void merg(int x,int y)
{
    parent[x]=y;
    ok[y]|=ok[x];
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=0;i<maxn;++i) parent[i]=(-1);
    sz=1;
    int n,m;
    cin>>n>>m;
    vector <int> v[n];
    for(int i=0;i<n;++i)
    {
        int k;
        cin>>k;
        v[i].resize(k);
        for(int j=0;j<k;++j)
        {
            int x;
            cin>>x;
            v[i][j]=x;
        }
        if(v[i].size()==2)
        {
            int u=get1(v[i][0]);
            int h=get1(v[i][1]);
            if(ok[u] && ok[h]) continue;
            if(u!=h)
            {
                merg(u,h);
                sz*=2;
            sz%=p;
            ans.push_back(i);
            }
        }
        else
        {
            int l=get1(v[i][0]);
            bool h=ok[l];
            if(!h)
            {
                ok[l]=true;
                sz*=2;
            sz%=p;
            ans.push_back(i);
            }
        }
    }
    cout<<sz<<' '<<ans.size()<<endl;
    for(auto h:ans) cout<<h+1<<' ';
    return 0;
}