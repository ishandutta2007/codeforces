#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

vector<int> g[N];
int a[N];
int ans=0;

pii dfs(int v)
{
    int leaves=g[v].empty();
    int people=a[v];
    for(int to:g[v])
    {
        auto [l,p]=dfs(to);
        leaves+=l;
        people+=p;
    }
    ans=max(ans,(people+leaves-1)/leaves);
    return {leaves,people};
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        int p;
        cin>>p;
        g[p].push_back(i);
    }
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dfs(1);
    cout<<ans;
}