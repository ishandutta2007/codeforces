#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=100000;
vector <int> a[maxn];
int deq[maxn];
bool used[maxn];
int pr1[maxn];
int corn[maxn];
void dfs(int x,int pr=(-1))
{
    if(pr==(-1))
    {
        corn[x]=0;
    }
    used[x]=true;
    int v;
    bool h=false;
    for(int i=0;i<a[x].size();++i)
    {
        v=a[x][i];
        if(!used[v])
        {
            corn[v]=corn[x]+1;
            dfs(v,x);
            h=true;
        }
    }
    if(!h)
    {
        pr1[x]=pr;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<n;++i)
    {
        int x,y;
        cin>>x>>y;
        x--;y--;
        a[x].push_back(y);a[y].push_back(x);
        deq[x]++;
        deq[y]++;
    }
    for(int i=0;i<n;++i)
    {
        if(deq[i]>=2)
        {
            dfs(i,-1);
        }
    }
    set <int> u1;
    set <int> u2;
    int sum=(n-1);
    for(int i=0;i<n;++i)
    {
        if(deq[i]==1)
        {
            u1.insert(corn[i]%2);
            u2.insert(pr1[i]);
            sum--;
        }
    }
    if(u1.size()==1)
    {
        cout<<1<<" ";
    }
    else
    {
        cout<<3<<" ";
    }
    cout<<sum+u2.size();
    return 0;
}