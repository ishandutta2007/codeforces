#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#include<unordered_map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
typedef unsigned long long ull;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216")  //hdu 
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'A')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define re register
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=200005;
//const ll Mod=1000000007;
const ll Mod=998244353;

ll d[maxn],t[maxn],pre[maxn];
ll dp[105][maxn];
int q[105][maxn];
int head[maxn],tail[maxn];

double slope(int i,int j1,int j2)
{
    return (1.0*pre[j1]+dp[i][j1]-pre[j2]-dp[i][j2])/(j1-j2);
}

int main()
{
    sync;
    int n,m,p;
    cin>>n>>m>>p;
    for(int i=2;i<=n;i++)
    {
        cin>>d[i];
        d[i]+=d[i-1];
    }
    int x,pos;
    for(int i=1;i<=m;i++)
    {
        cin>>pos>>x;
        t[i]=x-d[pos];
    }
    if(p>=m)
    {
        cout<<0<<endl;
        return 0;
    }
    sort(t+1,t+m+1);
    for(int i=1;i<=m;i++)
    {
        pre[i]=pre[i-1]+t[i];
    }
    int id;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=min(i,p);j++)
        {
            while(head[j-1]<tail[j-1]&&slope(j-1,q[j-1][head[j-1]],q[j-1][head[j-1]+1])<=t[i])
                head[j-1]++;
            id=q[j-1][head[j-1]];
            dp[j][i]=dp[j-1][id]+t[i]*(i-id)-pre[i]+pre[id];
            while(head[j]<tail[j]&&slope(j,q[j][tail[j]],i)<slope(j,q[j][tail[j]-1],q[j][tail[j]]))
                tail[j]--;
            q[j][++tail[j]]=i;
        }
    }
    cout<<dp[p][m]<<endl;
    return 0;
}