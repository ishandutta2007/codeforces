#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=20;
vector <int> a[maxn];
vector <int> b[maxn];
int ans[1<<maxn];
bool used[maxn];
int parent[maxn];
int tim;
int tout[maxn];
int glav(int x)
{
    int y=x;
    while(true)
    {
        if(parent[y]==(-1))
        {
            return y;
        }
        y=parent[y];
    }
}
void merg(int x,int y)
{
    x=glav(x);y=glav(y);
    if(x!=y) parent[x]=y;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    tim=0;
    for(int i=0;i<maxn;++i) {parent[i]=(-1);a[i].clear();used[i]=false;}
    int n;
    string s1,s2;
    cin>>n;
    cin>>s1>>s2;
    /*bool h=true;
    for(int i=0;i<n;++i)
    {
        if(s1[i]>s2[i])
        {
            cout<<(-1)<<endl;
            h=false;
            break;
        }
    }
    if(!h) continue;*/
    for(int i=0;i<n;++i)
    {
        merg(s1[i]-'a',s2[i]-'a');
        if((s1[i]-'a')==(s2[i]-'a')) continue;
        a[s1[i]-'a'].push_back(s2[i]-'a');
    }
    for(int i=0;i<maxn;++i)
    {
        sort(a[i].begin(),a[i].end());
        a[i].erase(unique(a[i].begin(),a[i].end()),a[i].end());
    }
    set <int> d;
    for(int i=0;i<maxn;++i)
    {
        d.insert(glav(i));
    }
    int o=d.size();
    int sz=(1<<maxn);
    ans[0]=0;
    for(int mask=1;mask<sz;++mask)
    {
        ans[mask]=1e18;
        bool h1=false;
        for(int i=0;i<maxn;++i)
        {
            int r=0;
            if((1<<i) & mask)
            {
                for(auto v:a[i])
                {
                    if(((1<<v) & mask))
                    {
                        r=1;
                        break;
                    }
                }
            }
            else
            {
                continue;
            }
            if(!r) h1=true;
            ans[mask]=min(ans[mask],ans[mask-(1<<i)]+r+1);
        }
        //if(!h1) cout<<mask<<" mask "<<endl;
       // cout<<mask<<" mask "<<endl;
        //cout<<ans[mask]<<" ans[mask] "<<endl;
    }
    //cout<<d.size()<<" d.size() "<<endl;
    cout<<ans[sz-1]-d.size()<<endl;
    }
    return 0;
}