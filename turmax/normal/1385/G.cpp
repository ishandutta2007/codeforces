#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5;
vector <pair<int,int> > a[maxn];
bool used[maxn];
bool color[maxn];
vector <int> z1;
vector <int> z2;
void dfs(int x,bool col)
{
    used[x]=true;
    color[x]=col;
    if(col)
    {
        z1.push_back(x);
    }
    else
    {
        z2.push_back(x);
    }
    for(auto v:a[x])
    {
        if(used[v.first]) continue;
        if(!v.second)
        {
            dfs(v.first,col);
        }
        else
        {
            dfs(v.first,!col);
        }
    }
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
    for(int i=0;i<n;++i) {a[i].clear();used[i]=false;}
    vector <pair<int,int> > u[n];
    int a1[n];
    int b[n];
    int cnt[n];
    for(int i=0;i<n;++i) cnt[i]=0;
    for(int i=0;i<n;++i) {cin>>a1[i];a1[i]--;cnt[a1[i]]++;u[a1[i]].push_back({i,0});}
    for(int i=0;i<n;++i) {cin>>b[i];b[i]--;cnt[b[i]]++;u[b[i]].push_back({i,1});}
    bool h=true;
    for(int i=0;i<n;++i) {
        if(cnt[i]!=2) {cout<<(-1)<<endl;h=false;break;}
    }
    if(!h)
    {
        continue;
    }
    for(int i=0;i<n;++i)
    {
        pair <int,int> z1=u[i][0];pair <int,int> z2=u[i][1];
        if(z1.first==z2.first)
        {
            color[z1.first]=true;
            continue;
        }
        if(z1.second==z2.second)
        {
            a[z1.first].push_back({z2.first,1});
            a[z2.first].push_back({z1.first,1});
        }
        else
        {
            a[z1.first].push_back({z2.first,0});
            a[z2.first].push_back({z1.first,0});
        }
    }
    vector <int> res;
    for(int i=0;i<n;++i)
    {
        if(!used[i])
        {
            dfs(i,true);
        }
        if(z2.size()>=z1.size())
        {
            swap(z1,z2);
        }
        for(auto v:z1)
        {
            color[v]=true;
        }
        for(auto v:z2)
        {
            res.push_back(v);
            color[v]=false;
        }
        z1.clear();z2.clear();
    }
    cout<<res.size()<<endl;
    for(auto v:res)
    {
        cout<<v+1<<' ';
    }
    cout<<endl;
    }
    return 0;
}