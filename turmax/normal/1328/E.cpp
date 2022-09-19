#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=200005;
vector <int> a[maxn];
bool used[maxn];
int timein[maxn];
int timeout[maxn];
int timer=0;
int pr[maxn];
void dfs(int x)
{
    timein[x]=timer;
    ++timer;
    used[x]=true;
    int v;
    for(int i=0;i<a[x].size();++i)
    {
        v=a[x][i];
        if(!used[v])
        {
            pr[v]=x;
            dfs(v);
        }
    }
    ++timer;
    timeout[x]=timer;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    pr[0]=0;
    for(int i=0;i<(n-1);++i)
    {
        int x,y;
        cin>>x>>y;
        x--;y--;
        a[x].push_back(y);a[y].push_back(x);
    }
    dfs(0);
    for(int i=0;i<m;++i)
    {
        int x;
        cin>>x;
        vector <int> v(x);
        for(int j=0;j<x;++j)
        {
            cin>>v[j];
            v[j]--;
            v[j]=pr[v[j]];
        }
        vector <pair <int,int> > d(x);
        for(int j=0;j<x;++j)
        {
            d[j]={timein[v[j]],timeout[v[j]]};
        }
        sort(d.begin(),d.end());
        bool h=true;
        for(int j=0;j<(x-1);++j)
        {
            if(d[j].second<d[j+1].second)
            {
                cout<<"NO"<<endl;
                h=false;
                break;
            }
        }
        if(h)
        {
            cout<<"YES"<<endl;
        }
    }
    return 0;
}