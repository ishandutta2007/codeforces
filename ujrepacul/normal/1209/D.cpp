#include <bits/stdc++.h>
using namespace std;
int cnt;
int viz[200005];
vector <int> v[200005];
void dfs (int pz)
{
    viz[pz]=1;
    for(int i=0;i<v[pz].size();++i)
        if(!viz[v[pz][i]])
        {
            ++cnt;
            dfs(v[pz][i]);
        }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    long long n,i,j,m,k=0,x=0,t,s=0;
    cin>>n>>m;
    for(i=1;i<=m;++i)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(i=1;i<=n;++i)
        if(!viz[i])
            dfs(i);
    cout<<m-cnt;
    return 0;
}