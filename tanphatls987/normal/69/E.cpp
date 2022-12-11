#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>
#include <vector>
#include <queue>
#include <map>

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
#define inf 2000000000

const int N=100010;

typedef long long ll;

map <int,int> m;
int h[N]={0},p[N<<2]={0},nod[N],n,k,c,num[N],a[N];
void init(int node,int l,int r)
{
    if (l==r){
        nod[l]=node;
        return;
    }
    init(node*2,l,(l+r)/2);
    init(node*2+1,(l+r)/2+1,r);
}
int maxi(int x,int y){if (num[x]>num[y]) return x;return y;}
void update(int node)
{
    while (node)
    {
        p[node]=maxi(p[node*2+1],p[node*2]);
        node>>=1;
    }
}
void prepare()
{
    c=0;
    scanf("%d%d",&n,&k);
    FOR(i,1,n)
    {
        scanf("%d",&a[i]);
        if (m[a[i]]==0) {m[a[i]]=++c;num[c]=a[i];}
    }
    //printf("%d",c);
    init(1,1,c);
    num[0]=-inf;
}
int change(int cur,int v)
{
    h[cur]+=v;
    if (h[cur]==1)
    {
        p[nod[cur]]=cur;
        update(nod[cur]>>1);
    }
    if (h[cur]==0||h[cur]>1)
    {
        p[nod[cur]]=0;
        update(nod[cur]>>1);
    }
}
void check(int node,int l,int r)
{
    printf("%d %d %d %d\n",node,l,r,p[node]);
    if (l<r)
    {
        check(node*2,l,(l+r)/2);
        check(node*2+1,(l+r)/2+1,r);
    }
}
int solve()
{
    FOR(i,1,n)
    {
        change(m[a[i]],1);
        if (i>k) change(m[a[i-k]],-1);
        //check(1,1,c);
        if (i>=k) if (p[1]==0) printf("Nothing\n");else printf("%d\n",num[p[1]]);
    }
}
int main()
{
    prepare();
    solve();
}