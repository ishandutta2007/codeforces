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
#include <chrono>
#include <random>
typedef long long ll;
typedef unsigned long long ull;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-10
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define re register
#define umap(a) (a).reserve(1024);(a).max_load_factor(0.25);
using namespace std;
typedef pair<int,ll> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=1000005;
const ll Mod=1000000007;
//const ll Mod=998244353;



ll sum[maxn][5];
int cnt[maxn];
ll b[maxn];

void pushup(int rt)
{
    cnt[rt]=cnt[lr]+cnt[rr];
    int id;
    for(int i=0;i<5;i++)
    {
        id=i-cnt[lr];
        id=(id%5+5)%5;
        sum[rt][i]=sum[lr][i]+sum[rr][id];
    }
}

void upd(int rt,int l,int r,int pos,int val)
{
    if(l==r)
    {
        sum[rt][1]=val*b[l];
        cnt[rt]=val;
        return;
    }
    int mid=(l+r)/2;
    if(pos<=mid)
        upd(lr,l,mid,pos,val);
    else
        upd(rr,mid+1,r,pos,val);
    pushup(rt);
}

string s;
struct Node
{
    int op;
    ll x;
}q[maxn];


int main()
{
    sync;
    int Q;
    cin>>Q;
    int n=0;
    for(int i=1;i<=Q;i++)
    {
        cin>>s;
        if(s[0]=='a')
        {
            q[i].op=1;
            cin>>q[i].x;
            b[++n]=q[i].x;
        }
        else if(s[0]=='d')
        {
            q[i].op=-1;
            cin>>q[i].x;
        }
        else
        {
            q[i].op=2;
        }
    }
    sort(b+1,b+n+1);
    n=unique(b+1,b+n+1)-b-1;
    int op,x;
    for(int i=1;i<=Q;i++)
    {
        op=q[i].op;
        x=q[i].x;
        if(op==1)
        {
            x=lower_bound(b+1,b+n+1,x)-b;
            upd(1,1,n,x,1);
        }
        else if(op==-1)
        {
            x=lower_bound(b+1,b+n+1,x)-b;
            upd(1,1,n,x,0);
        }
        else
        {
            if(n==0)
                cout<<0<<endl;
            else
                cout<<sum[1][3]<<endl;
        }
    }
    return 0;
}