#include<bits/stdc++.h>
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 1e5 + 10;

int n,q,arr[N],lst[N];
vi edg[N];
int fa[N][20],lg[N],dep[N];
void dfs(int u,int d=1)
{
    dep[u]=d;
    for(int i=1;d>1<<i;i++)
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for(auto v:edg[u])
    {
        fa[v][0]=u;
        dfs(v,d+1);
    }
}
int main()
{
    lg[0]=-1;
    for(int i=1;i<N;i++)lg[i]=lg[i-1]+(i&i-1?0:1);
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    cin>>n>>q;
    int st=1;
    for(int id=1;id<=n;id++)
    {
        int a;cin>>a;
        int ma=0;
        for(int i=2;i*i<=a;i++)if(a%i==0)
        {
            while(a%i==0)
            {
                a/=i;
            }
            if(lst[i])ma=max(ma,lst[i]);
            lst[i]=id;
        }
        if(a!=1)
        {
            if(lst[a])ma=max(ma,lst[a]);
            lst[a]=id;
        }

        while(st<=ma)
        {
            edg[id].push_back(st++);
        }
    }
    while(st<=n)edg[n+1].push_back(st++);

    dfs(n+1);

    while(q--)
    {
        int l,r;cin>>l>>r;

        int ans=1;
        for(int i=lg[dep[l]];~i;i--)
        {
            if(fa[l][i]&&fa[l][i]<=r)
            {
                l=fa[l][i];
                ans+=1<<i;
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}