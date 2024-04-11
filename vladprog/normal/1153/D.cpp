#pragma GCC optimize("O3")
#include <bits/stdc++.h>

typedef long long ll;
#define int ll
typedef long double ld;

using namespace std;

const int N=3e5+100;

int op[N];
vector<int> g[N];
int k=0;

int dfs(int v)
{
    if(g[v].empty())
        return k++, 1;
    vector<int> res;
    for(int to:g[v])
        res.push_back(dfs(to));
    if(op[v]==0)
        return accumulate(res.begin(),res.end(),0);
    else
        return *min_element(res.begin(),res.end());
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>op[i];
    for(int i=2;i<=n;i++)
    {
        int f;
        cin>>f;
        g[f].push_back(i);
    }
    int dfs1=dfs(1);
    cout<<k-dfs1+1;
}