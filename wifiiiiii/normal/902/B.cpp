#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

vector<int> g[100005];
int c[100005];
int ans = 0;
void dfs(int u, int col)
{
    if(c[u] != col) col = c[u], ans++;
    for(int v:g[u]) dfs(v, col);
}
int main()
{
    int n;
    cin>>n;
    for(int i=2;i<=n;++i)
    {
        int fa;
        cin>>fa;
        g[fa].push_back(i);
    }
    ii cin>>c[i];
    dfs(1,-1);
    cout<<ans<<endl;
}