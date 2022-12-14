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
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
int n,m,vis[N];
vi edg[N];
set<int>ans;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
	cin>>n>>m;
	for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        edg[a].push_back(b);
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            ans.insert(i);
            for(auto v:edg[i])
            {
                vis[v]=1;
            }
        }
    }
    for(int i=n;i;i--)
    {
        if(ans.count(i))
        {
            for(auto v:edg[i])
            {
                if(ans.count(v))
                {
                    ans.erase(v);
                }
            }
        }
    }
    cout<<ans.size()<<endl;
    for(auto i:ans)
        cout<<i<<' ';
	return 0;
}