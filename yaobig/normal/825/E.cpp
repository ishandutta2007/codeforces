#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100000
#define mod 1000000007
#define inf (1ll<<60)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

vi e[maxn+5];
int deg[maxn+5];
priority_queue<int> q;
int label[maxn+5];

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,m)
    {
        int u,v; scanf("%d%d",&u,&v);
        e[v].pb(u);
        deg[u]++;
    }
    rep(i,1,n) if(deg[i]==0) q.push(i);
    int cnt=n;
    while(!q.empty())
    {
        int now=q.top(); q.pop();
        label[now]=cnt--;
        for(auto v: e[now]) if(--deg[v]==0) q.push(v);
    }
    rep(i,1,n) printf("%d%c",label[i]," \n"[i==n]);
    return 0;
}