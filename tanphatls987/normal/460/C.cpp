#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second
#define MOD 1000000007
#define INPUT freopen(".inp","r",stdin)
#define OUTPUT freopen(".out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define inf 1000000

const int N=100010;

typedef long long ll;
int h[N],n,m,w;
struct nod{int ad,v,sv,s;}a[N<<2];

void update(int node,int l,int r)
{
    a[node].sv+=a[node].ad;
    if (l<r)
    {
        a[node*2].ad+=a[node].ad;
        a[node*2+1].ad+=a[node].ad;
    }
    a[node].ad=0;
}
void mergenode(int node,int l,int r){
    if (a[2*node+1].sv+a[2*node+1].v<a[2*node].sv+a[2*node].v)
    {
        a[node].s=a[2*node+1].s;
        a[node].sv=a[2*node+1].sv+a[2*node+1].v;
    }
    else{
        a[node].s=a[2*node].s;
        a[node].sv=a[2*node].sv+a[2*node].v;
    }
}
void add(int x,int y,int node,int l,int r)
{
    update(node,l,r);
    if (x>r||y<l) return ;
    if (x<=l&&y>=r)
    {
        a[node].sv++;
        if (l<r){
            a[node*2].ad++;
            a[node*2+1].ad++;
        }
        return;
    }
    add(x,y,node*2,l,(l+r)/2);
    add(x,y,node*2+1,(l+r)/2+1,r);
    if (l<r) mergenode(node,l,r);
}
void init(int node,int l,int r)
{
    if (l==r)
    {
        a[node].s=l;
        a[node].sv=h[l];
        a[node].ad=a[node].v=0;
        return;
    }
    init(node*2,l,(l+r)/2);
    init(node*2+1,(l+r)/2+1,r);
    mergenode(node,l,r);
}
void prepare()
{
    scanf("%d%d%d",&n,&m,&w);
    FOR(i,1,n) scanf("%d",&h[i]);
}
void check(int node,int l,int r)
{
    printf("%d %d %d %d %d %d %d\n",node,l,r,a[node].s,a[node].sv,a[node].v,a[node].ad);
    if (l==r) return ;
    check(node*2,l,(l+r)/2);
    check(node*2+1,(l+r)/2+1,r);
}
void solve()
{
    init(1,1,n);
    FOR(i,1,m)
    {
        int l=a[1].s;
        if (l+w-1>n) l=n-w+1;
        //printf("%d %d\n",l,a[1].sv);
        add(l,l+w-1,1,1,n);
        //check(1,1,n);
    }
    //check(1,1,n);
    //update(1,1,n);
    printf("%d",a[1].sv+a[1].v);
}
int main()
{
    prepare();
    solve();
}