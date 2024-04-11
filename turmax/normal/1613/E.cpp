#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e6+5;
bool used[maxn];
vector <int> g[maxn];
vector <int> b[maxn];
vector <int> o[maxn];
void dfs(int x);
void ch(int x)
{
    if(o[x].size()<=2) return;
    int h=0;
    for(auto z:o[x])
    {
        h+=(!used[z]);
    }
    if(h<=1) dfs(x);
}
void dfs(int x)
{
    if(used[x]) return;
    used[x]=true;
    for(auto v:g[x])
    {
        if(!used[v]) dfs(v);
    }
    for(auto v:b[x])
    {
        if(!used[v]) ch(v);
    }
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
        for(int i=0;i<n*m;++i) {used[i]=false;g[i].clear();b[i].clear();o[i].clear();}
        string a[n];
        for(int i=0;i<n;++i) cin>>a[i];
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                vector <pair<int,int> > v;
                int sum=0;
                for(int k=(-1);k<=1;++k)
                {
                    for(int l=(-1);l<=1;++l)
                    {
                        if(abs(k)+abs(l)==1 && (i+k)>=0 && (i+k)<n && (j+l)>=0 && (j+l)<m)
                        {
                             if(a[i+k][j+l]!='#') {++sum;v.push_back({i+k,j+l});}
                        }
                    }
                }
                for(auto h:v)
                    {
                        o[i*m+j].push_back(h.first*m+h.second);
                        b[h.first*m+h.second].push_back(i*m+j);
                    }
                if(sum<=2)
                {
                    for(auto h:v)
                    {
                        g[h.first*m+h.second].push_back(i*m+j);
                    }
                }
            }
        }
        for(int i=0;i<n;++i) for(int j=0;j<m;++j) if(a[i][j]=='L') dfs(i*m+j);
        for(int i=0;i<n;++i) {for(int j=0;j<m;++j)
        {
            if(a[i][j]!='.' || !used[i*m+j]) cout<<a[i][j];
            else cout<<'+';
        }
        cout<<'\n';
        }
    }
    return 0;
}