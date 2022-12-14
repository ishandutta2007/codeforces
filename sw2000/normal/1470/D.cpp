#include<bits/stdc++.h>
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 3e5 + 10;
const int mod = 1e9 + 7;
int n,m,father[N];
bool vis[N];
vi edg[N];
int ff(int a){return a==father[a]?a:father[a]=ff(father[a]);}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)vis[i]=0;
    for(int i=1;i<=n;i++)father[i]=i;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        edg[a].push_back(b);
        edg[b].push_back(a);
        int fa=ff(a),fb=ff(b);
        if(fa!=fb)father[fa]=fb;
    }
    for(int i=2;i<=n;i++)
    {
        if(ff(i)!=ff(1))
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    queue<int>q;
    vi ans{1};
    for(auto i:edg[1])
    {
        q.push(i);
        vis[i]=1;
    }
    vis[1]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(auto v:edg[u])if(!vis[v])
        {
            vis[v]=1;
            ans.push_back(v);
            for(auto i:edg[v])if(!vis[i])
            {
                vis[i]=1;
                q.push(i);
            }
        }
    }
    cout<<ans.size()<<endl;
    for(auto i:ans)
        cout<<i<<' ';
    cout<<endl;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
    int _;
    cin>>_;
    while(_--)
    {
        solve();
        for(int i=1;i<=n;i++)
            edg[i].clear();
    }
	return 0;
}