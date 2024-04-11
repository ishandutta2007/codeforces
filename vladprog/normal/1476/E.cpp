#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

string p[N];
vector<int> g[N];
int used[N];
vector<int> ans;

void dfs(int v)
{
    if(used[v]==2)
        return;
    if(used[v]==1)
        cout<<"NO",exit(0);
    used[v]=1;
    for(int to:g[v])
        dfs(to);
    used[v]=2;
    ans.push_back(v);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,k;
    cin>>n>>m>>k;
    map<string,int> ind;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
        ind[p[i]]=i;
    }
    for(int i=1;i<=m;i++)
    {
        string s;
        int mt;
        cin>>s>>mt;
        for(int j=0;j<k;j++)
            if(p[mt][j]!='_'&&p[mt][j]!=s[j])
                cout<<"NO",exit(0);
        for(int mask=0;mask<(1<<k);mask++)
        {
            string t;
            for(int j=0;j<k;j++)
                t+=((mask>>j)&1?s[j]:'_');
            if(t!=p[mt]&&ind.count(t))
                g[mt].push_back(ind[t]);
        }
    }
    for(int i=1;i<=n;i++)
        dfs(i);
    reverse(ans.begin(),ans.end());
    cout<<"YES\n";
    for(int x:ans)
        cout<<x<<" ";
}