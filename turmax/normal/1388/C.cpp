#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5;
int p[maxn];
int h[maxn];
vector <int> a[maxn];
bool used[maxn];
bool can=true;
int sub[maxn];
int hor[maxn];
void dfs(int x)
{
    sub[x]=p[x];
    used[x]=true;
    int sum=0;
    for(auto v:a[x])
    {
        if(!used[v])
        {
            dfs(v);
            sum+=hor[v];
            sub[x]+=sub[v];
        }
    }
    if((sub[x]%2)!=(h[x]%2+2)%2)
    {
        can=false;
    }
    hor[x]=(h[x]+sub[x])/2;
    if(hor[x]<0 || hor[x]>sub[x])
    {
        can=false;
    }
    //cout<<sum<<" sum "<<endl;
    if(hor[x]<sum)
    {
        //cout<<x<<" x "<<endl;
        can=false;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    can=true;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i) {a[i].clear();used[i]=false;}
    for(int i=0;i<n;++i)
    {
        cin>>p[i];
    }
    for(int i=0;i<n;++i)
    {
        cin>>h[i];
    }
    for(int i=0;i<(n-1);++i)
    {
        int x,y;
        cin>>x>>y;
        x--;y--;
        a[x].push_back(y);a[y].push_back(x);
    }
    dfs(0);
    if(can) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    }
    return 0;
}