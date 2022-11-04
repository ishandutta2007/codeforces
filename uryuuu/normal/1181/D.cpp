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
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'1')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=500005;
//const ll Mod=1000000007;
const ll Mod=998244353;
using namespace std;

ll cnt[maxn],dp[maxn];
int rt[maxn];
ll n,m,q,x;
vector<int>v[maxn];

int tot=0;
int lc[maxn*25],rc[maxn*25],T[maxn*25];
void upd(int &now,int old,int l,int r,int pos)
{
    now=++tot;
    T[now]=T[old]+1;
    lc[now]=lc[old];
    rc[now]=rc[old];
    if(l==r)
        return;
    int mid=(l+r)/2;
    if(pos<=mid)
    {
        upd(lc[now],lc[old],l,mid,pos);
    }
    else
        upd(rc[now],rc[old],mid+1,r,pos);
}


int query(int rt,int l,int r,int k)
{
    if(l==r)
        return l;
    int mid=(l+r)/2;
    if(T[lc[rt]]>=k)
        return query(lc[rt],l,mid,k);
    return query(rc[rt],mid+1,r,k-T[lc[rt]]);
}



int main()
{
    sync;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        cnt[x]++;
    }
    for(int i=1;i<=m;i++)
    {
        v[cnt[i]].push_back(i);
    }
    dp[0]=0;
    ll pre=0;
    ll len;
    for(int i=0;i<=n+1;i++)
    {
        if(i)
            dp[i]=dp[i-1]+pre;
        len=v[i].size();
        pre+=len;
        if(i)
        {
            rt[i]=rt[i-1];
        }
        for(int j=0;j<len;j++)
        {
            upd(rt[i],rt[i],1,m,v[i][j]);
        }
//        cout<<dp[i]<<' '<<rt[i]<<endl;
    }
    ll k;
    int pos;
    while(q--)
    {
        cin>>k;
        k-=n;
        pos=(int)(lower_bound(dp+1,dp+n+1,k)-dp);
        if(pos==n+1)
        {
            cout<<(k-dp[n]-1)%m+1<<endl;
        }
        else
        {
            cout<<query(rt[pos-1],1,m,k-dp[pos-1])<<endl;
        }
    }
    
    return 0;
}