#include <bits/stdc++.h>
#define fi first
#define se second
#define mid (l+r>>1)
#define lo (o<<1)
#define ro (o<<1|1)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
struct tri {int a, b, c;};
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 1e5 + 10;
const ll mod = 1e9 + 7;
const double PI = acos(0) * 2;
int n,m;
int vis[N];
unordered_set<int>s[2],edg[N];
void dfs(int u,int op)
{
    vis[u]=op;
    for(int v:edg[u])if(!vis[v])
    {
        dfs(v,3-op);
    }
}
int ans[N],tot;
vi e[N];
void solve()
{
    if(s[0].size()%3==2)s[0].swap(s[1]);
    if(s[0].size()%3==1)
    {
        for(int i:s[0])
        {
            if(edg[i].size()<s[1].size()-1)
            {
                ans[i]=++tot;
                s[0].erase(i);
                int cnt=0;
                vi v;
                for(int j:s[1])
                {
                    if(!edg[i].count(j))
                    {
                        ans[j]=tot;
                        cnt++;
                        v.push_back(j);
                    }
                    if(cnt==2)break;
                }
                for(auto j:v)s[1].erase(j);
                break;
            }
        }
        if(!tot){
        for(auto i:s[1])
        {
            for(auto j:s[0])
            {
                if(!edg[i].count(j))
                {
                    e[i].push_back(j);
                    e[j].push_back(i);
                }
            }
        }
        for(auto i:s[1])if(e[i].size()>=2)
        {
            for(auto j:s[1])if(i!=j&&e[j].size()>=2)
            {
                if(e[i].size()>=4)
                {
                    ans[j]=++tot;
                    ans[e[j][0]]=tot;
                    ans[e[j][1]]=tot;

                    ans[i]=++tot;
                    int cnt=0;
                    for(auto k:e[i])if(k!=e[j][0]&&k!=e[j][1])
                    {
                        ans[k]=tot;
                        cnt++;
                        if(cnt==2)break;
                    }
                }
                else if(e[j].size()>=4)
                {
                    ans[i]=++tot;
                    ans[e[i][0]]=tot;
                    ans[e[i][1]]=tot;

                    ans[j]=++tot;
                    int cnt=0;
                    for(auto k:e[j])if(k!=e[i][0]&&k!=e[i][1])
                    {
                        ans[k]=tot;
                        cnt++;
                        if(cnt==2)break;
                    }
                }
                else if(e[i].size()==3&&e[j].size()==3)
                {
                    set<int>t;
                    for(auto k:e[i])if(k!=e[j][0]&&k!=e[j][1]&&k!=e[j][2])
                    {
                        ans[i]=++tot;
                        ans[k]=tot;
                        t.insert(k);
                        break;
                    }
                    for(auto k:e[i])if(!t.count(k))
                    {
                        ans[k]=tot;
                        t.insert(k);
                        break;
                    }
                    int cnt=0;
                    ans[j]=++tot;
                    for(auto k:e[j])if(!t.count(k))
                    {
                        ans[k]=tot;
                        cnt++;
                        if(cnt==2)break;
                    }
                }
                else if(e[i].size()==2)
                {
                    vi t;
                    for(auto k:e[j])if(k!=e[i][0]&&k!=e[i][1])
                    {
                        t.push_back(k);
                    }
                    if(t.size()>=2)
                    {
                        ans[i]=++tot;
                        ans[e[i][0]]=tot;
                        ans[e[i][1]]=tot;
                        ans[j]=++tot;
                        ans[t[1]]=tot;
                        ans[t[0]]=tot;
                    }
                }
                else
                {
                    vi t;
                    for(auto k:e[i])if(k!=e[j][0]&&k!=e[j][1])
                    {
                        t.push_back(k);
                    }
                    if(t.size()>=2)
                    {
                        ans[j]=++tot;
                        ans[e[j][0]]=tot;
                        ans[e[j][1]]=tot;
                        ans[i]=++tot;
                        ans[t[1]]=tot;
                        ans[t[0]]=tot;
                    }
                }

                if(tot)break;
            }
            if(tot)break;
        }}
        if(!tot)
        {
            cout<<"NO";
            return;
        }
    }
//    for(int i=1;i<=n;i++)
//        cout<<ans[i]<<' ';cout<<endl;
    int cnt=0;
    tot++;
    for(auto i:s[0])if(!ans[i])
    {
        ans[i]=tot;
        cnt++;
        if(cnt==3)
        {
            cnt=0;
            tot++;
        }
    }
    for(auto i:s[1])if(!ans[i])
    {
        ans[i]=tot;
        cnt++;
        if(cnt==3)
        {
            cnt=0;
            tot++;
        }
    }
    cout<<"YES"<<endl;
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
//    freopen("in.txt", "r", stdin);
    cin>>n>>m;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        edg[a].insert(b);
        edg[b].insert(a);
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])dfs(i,1);
        if(vis[i]==1)s[0].insert(i);
        else s[1].insert(i);
    }
    solve();
    return 0;
}