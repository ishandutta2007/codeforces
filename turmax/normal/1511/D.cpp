#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=27;
vector <int> a[maxn];
set <pair<int,int> > use;
vector <int> z;
void dfs(int x)
{
    for(auto v:a[x])
    {
        if(!use.count({x,v}))
        {
            use.insert({x,v});
            dfs(v);
        }
    }
    z.push_back(x);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<k;++i)
    {
        for(int j=0;j<k;++j)
        {
            a[i].push_back(j);
        }
    }
    dfs(0);
    z.pop_back();
    for(int i=0;i<n;++i)
    {
        cout<<(char) ('a'+z[i%z.size()]);
    }
    return 0;
}