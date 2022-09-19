#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=5e3+5;
vector <int> a[maxn];
bool used[maxn];
bool used1[maxn];
int color[maxn];
int b=0;
int w=0;
void dfs(int x)
{
    if(color[x]) ++b;
    else ++w;
    used[x]=true;
    int v;
    for(int i=0;i<a[x].size();++i)
    {
        v=a[x][i];
        if(!used[v])
        {
            color[v]=(color[x]+1)%2;
            dfs(v);
        }
        else if(color[v]==color[x])
        {
            cout<<"NO";
            exit(0);
        }
    }
}
void dfs1(int x)
{
    color[x]=(color[x]+1)%2;
    used1[x]=true;
    int v;
    for(int i=0;i<a[x].size();++i)
    {
        v=a[x][i];
        if(!used1[v])
        {
            dfs1(v);
        }
    }
}
bool can[maxn][maxn];
bool pr[maxn][maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    for(int i=0;i<m;++i)
    {
        int x,y;
        cin>>x>>y;
        x--;y--;
        a[x].push_back(y);a[y].push_back(x);
    }
    vector <pair<int,pair<int,int> > > v;
    for(int i=0;i<n;++i)
    {
        if(!used[i])
        {
            w=0;
            b=0;
            color[i]=0;
            dfs(i);
            v.push_back({i,{w,b}});
        }
    }
    can[0][0]=true;
    pr[0][0]=(-1);
    for(int i=0;i<v.size();++i)
    {
        for(int j=0;j<=n2;++j)
        {
            if(can[i][j])
            {
                can[i+1][j+v[i].second.first]=true;
                pr[i+1][j+v[i].second.first]=true;
                can[i+1][j+v[i].second.second]=true;
                pr[i+1][j+v[i].second.second]=false;
            }
        }
    }
    int sz=v.size();
    if(!can[sz][n2])
    {
        cout<<"NO";
        return 0;
    }
    int curr=n2;
    for(int i=sz;i>0;i--)
    {
        bool h=pr[i][curr];
        if(!h)
        {
            dfs1(v[i-1].first);
            curr-=v[i-1].second.second;
        }
        else
        {
            curr-=v[i-1].second.first;
        }
    }
    cout<<"YES"<<endl;
    int c1=0;
    string s;
    for(int i=0;i<n;++i)
    {
        if(color[i]==0)
        {
            s+='2';
        }
        else
        {
            if(c1<n1)
            {
                s+='1';
                ++c1;
            }
            else
            {
                s+='3';
            }
        }
    }
    cout<<s;
    return 0;
}