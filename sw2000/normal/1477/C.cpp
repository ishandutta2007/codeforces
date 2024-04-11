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
const int N = 5000 + 10;
const int mod = 1e9 + 7;

int n;
bool vis[N];
ll x[N],y[N];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++)
    {
        cin>>x[i]>>y[i];
    }
    int u=1;
    while(1)
    {
        vis[u]=1;
        cout<<u<<' ';
        int v;
        ll t=0;
        for(int i=1;i<=n;i++)if(!vis[i])
        {
            ll d=(x[i]-x[u])*(x[i]-x[u])+(y[i]-y[u])*(y[i]-y[u]);
            if(d>t)
            {
                t=d;
                v=i;
            }
        }
        if(!t)return 0;
        u=v;
    }
	return 0;
}