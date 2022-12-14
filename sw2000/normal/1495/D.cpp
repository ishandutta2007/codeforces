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
typedef pair<int, ll>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 400 + 10;
const int mod = 998244353;

int n,m,dis[N][N];
vi edg[N];
set<int> from[N][N];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
	memset(dis,-1,sizeof(dis));
	cin>>n>>m;
	for(int i=0;i<m;i++)
    {
        int a,b;cin>>a>>b;
        edg[a].push_back(b);
        edg[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        queue<int>q;
        q.push(i);
        dis[i][i]=0;
        while(!q.empty())
        {
            int u=q.front();q.pop();

            for(auto v:edg[u])
            {
                if(dis[i][v]==-1)
                {
                    dis[i][v]=dis[i][u]+1;
                    q.push(v);
                }
                if(dis[i][v]==dis[i][u]+1)
                {
                    from[i][v].insert(u);
//                    cout<<i<<' '<<v<<endl;
                }
            }
        }
    }
//    for(auto i:from[1][3])cout<<i<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(from[i][j].size()>1)
            {
                cout<<0<<' ';
//                cout<<i<<' '<<j<<endl;
            }
            else
            {
                ll ans=1,tot=0;
                for(int k=1;k<=n;k++)if(k!=i&&k!=j)
                {
                    if(dis[i][k]+dis[j][k]==dis[i][j])tot++;
                    else
                    {
                        int cnt=0;
                        for(auto a:from[i][k])
                        {
                            if(from[j][k].count(a))cnt++;
                        }
                        ans=ans*cnt%mod;
                    }
                }
                if(i!=j&&tot!=dis[i][j]-1)ans=0;
                cout<<ans<<' ';
            }
        }
        cout<<endl;
    }
	return 0;
}