#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

vi e[maxn+5],ind,sta,cycle;
bool flag,blocked[maxn+5];
int dep[maxn+5],sq;

int mysqrt(int n)
{
    int x=sqrt(n);
    while(x*x>n) x--;
    while(x*x<n) x++;
    return x;
}

void dfs(int now,int fa)
{
    sta.pb(now);
    dep[now]=dep[fa]+1;
    for(auto v: e[now]) 
    {
        if(dep[v]==0) dfs(v,now);
        else if(dep[now]-dep[v]+1>=sq && flag==0)
        {
            int N=sta.size();
            per(i,0,N-1) 
            {
                cycle.pb(sta[i]);
                if(sta[i]==v) break;
            }
            flag=1;
        }
    }
    if(blocked[now]==0)
    {
        ind.pb(now);
        for(auto v: e[now]) blocked[v]=1;
    }
    sta.pop_back();
}


int main()
{
    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,m)
    {
        int x,y; scanf("%d%d",&x,&y);
        e[x].pb(y);
        e[y].pb(x);
    }
    sq=mysqrt(n);
    dfs(1,0);
    if(flag)
    {
        int N=cycle.size();
        puts("2"); printf("%d\n",N);
        rep(i,0,N-1) printf("%d%c",cycle[i]," \n"[i==N-1]);
    }
    else
    {
        puts("1");
        rep(i,0,sq-1) printf("%d%c",ind[i]," \n"[i==sq]);
    }
    return 0;
}