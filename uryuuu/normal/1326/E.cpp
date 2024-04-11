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
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=300050;
//const ll Mod=1000000007;
const ll Mod=998244353;
using namespace std;

int a[maxn<<2],lazy[maxn<<2];
int p[maxn],q[maxn],pos[maxn];

void pushdown(int rt)
{
    lazy[lr]+=lazy[rt];
    lazy[rr]+=lazy[rt];
    a[lr]+=lazy[rt];
    a[rr]+=lazy[rt];
    lazy[rt]=0;
}

void update(int rt,int l,int r,int R,int val)
{
    if(r<=R)
    {
        a[rt]+=val;
        lazy[rt]+=val;
        return;
    }
    if(l==r)
    {
        a[rt]+=val;
        return;
    }
    pushdown(rt);
    int mid=(l+r)/2;
    update(lr,l,mid,R,val);
    if(mid+1<=R)
        update(rr,mid+1,r,R,val);
    a[rt]=min(a[lr],a[rr]);
}


int main()
{
    sync;
    int n;
    cin>>n;
    rep(i,1,n)
    {
        cin>>p[i];
        pos[p[i]]=i;
    }
    
    rep(i,1,n)
    cin>>q[i];
    int ans=n;
    cout<<ans<<' ';
    update(1,1,n,pos[ans],-1);
    rep(i,1,n-1)
    {
        update(1,1,n,q[i],1);
        while(a[1]>=0)
        {
            ans--;
            update(1,1,n,pos[ans],-1);
        }
        cout<<ans<<' ';
    }
    cout<<endl;
    return 0;
}