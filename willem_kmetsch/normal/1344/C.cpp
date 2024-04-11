#include<bits/stdc++.h>
#define endl "\n"
#define rd(x) x=read()
#define wt(x) write(x)
#define pii pair<int,int>
#define pq priority_queue<int>
using namespace std;
const int N=2e5+5;
const int M=70;
const int SZ=450;
const int mod=1e9+7;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if (x<0){putchar('-');x=-x;}if (x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int n,m;
int d[N];
vector<int> G[N],H[N];
int vis[N];
int Q[N],l,r;
bool chk()
{
    //
    for (int i=1;i<=n;i++) d[i]=H[i].size();
    for (int i=1;i<=n;i++) if (d[i]==0) Q[++r]=i,vis[i]=1;
    while (l<r)
    {
        l++;int u=Q[l];
        for (int v:G[u]) if (!vis[v]){d[v]--;if (d[v]==0) Q[++r]=v,vis[v]=1;}
    }
    return r!=n;
}
int s[N];
int rt;
int K[N],L[N];
void get1(int u,int fa){if (K[u]) return;K[u]=1;for (int v:G[u]) if (v!=fa && v>rt) s[v]=1,get1(v,u);}
void get2(int u,int fa){if (L[u]) return;L[u]=1;for (int v:H[u]) if (v!=fa && v>rt) s[v]=1,get2(v,u);}
void DOIT()
{
    rd(n);rd(m);
    for (int i=1,j,k;i<=m;i++) rd(j),rd(k),G[k].push_back(j),H[j].push_back(k);
    if (chk()) {puts("-1");return;}
    for (int i=1;i<=n;i++) {rt=i;get1(i,0);get2(i,0);}
    int cnt=0;for (int i=1;i<=n;i++) cnt+=(!s[i]);cout<<cnt<<"\n";
    for (int i=1;i<=n;i++) putchar("AE"[s[i]]);putchar(10);
}
signed main()
{
    DOIT();
}
/*
2*3*5  

*/