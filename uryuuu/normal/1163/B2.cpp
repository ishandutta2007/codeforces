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
//#include<unordered_map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'A')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=100010;
//const ll Mod=1000000007;
const ll Mod=998244353;


int a[maxn<<2];
int v[maxn];
int s[maxn];

void pushup(int rt)   //
{
    a[rt]=a[lr]+a[rr];
}

void build(int rt,int l,int r)// 1n
{
    if(l==r)
    {
        a[l]=0;
        return ;
    }
    int mid=(l+r)/2;
    build(lr,l,mid);
    build(rr,mid+1,r);
    pushup(rt);
}


void update(int rt,int l,int r,int pos,int val)//,,lazy pushdown
{
    if(l==r)
    {
        a[rt]=val;
        return;
    }
    int mid=(l+r)/2;
    if(pos<=mid)
        update(lr,l,mid,pos,val);
    else
        update(rr,mid+1,r,pos,val);
    pushup(rt); //
    return;
}

int main()
{
    sync;
    int n;
    cin>>n;
    int zd=1;
    int m=0;
    int x;
    int uuu=0;
    build(1,1,n);
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(v[x])
        {
            if(s[v[x]]==1)
                update(1,1,n,v[x],0);
            s[v[x]]--;
        }
        else
            m++;
        v[x]++;
        s[v[x]]++;
        update(1,1,n,v[x],1);
        int c=a[1];
        if(c==1)
        {
            if(s[1]==m||v[x]==i)
                zd=i;
        }
        else if(c==2)
        {
            if(s[1]==1)
                zd=i;
            else if(s[v[x]]+s[v[x]+1]==m&&(s[v[x]+1]==1))
                zd=i;
            else if(s[v[x]]+s[v[x]-1]==m&&(s[v[x]]==1))
                zd=i;
        }
    }
    cout<<zd<<endl;
    
    return 0;
}