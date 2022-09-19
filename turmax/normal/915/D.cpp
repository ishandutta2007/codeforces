#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=5e2+5;
vector <int> a[maxn];
bool used[maxn];
int timer=0;
int tout[maxn];
void dfs(int x)
{
    //cout<<x<<" x "<<endl;
    used[x]=true;
    ++timer;
    for(auto v:a[x])
    {
        if(!used[v])
        {
            dfs(v);
        }
    }
    ++timer;
    tout[x]=timer;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    pair<int,int> b[m];
    for(int i=0;i<m;++i)
    {
        int x,y;
        cin>>x>>y;
        x--;y--;
        b[i]={x,y};
        a[x].push_back(y);
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<maxn;++j) used[j]=false;
        for(int k=i;k<(n+i);++k)
        {
            if(!used[k%n])
            dfs(k%n);
        }
        int sum=0;
        for(int i=0;i<m;++i)
        {
            if(tout[b[i].first]<=tout[b[i].second])
            {
                ++sum;
            }
        }
        //cout<<i<<" i "<<sum<<" sum "<<endl;
        if(sum<=1)
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}