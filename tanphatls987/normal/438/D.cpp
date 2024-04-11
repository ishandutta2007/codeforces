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
#define INPUT freopen(".inp","r",stdin)
#define OUTPUT freopen(".out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")

const int inf=((1LL<<31)-1);
const int MOD=1e9+7;
const int N=1e5+10;

typedef long long ll;

int s[N],n,m,k,type,x,y,nod[N];
struct node{
    ll sum;
    int maxn,l,r;
    void init(int L,int R){
        l=L,r=R;
    }
    void mergeup(node a,node b){
        sum=a.sum+b.sum;
        maxn=(s[a.maxn]>s[b.maxn])?a.maxn:b.maxn;
    }
}a[N<<2];
void build(int no,int l,int r){
    a[no].init(l,r);
    if (l==r){
        nod[l]=no;
        a[no].sum=s[l];
        a[no].maxn=l;
        return;
    }
    build(no*2,l,(l+r)/2);
    build(no*2+1,(l+r)/2+1,r);
    a[no].mergeup(a[no*2],a[no*2+1]);
}
ll squery(int no,int l,int r){
    if (a[no].l>r||a[no].r<l) return 0;
    if (l<=a[no].l&&a[no].r<=r) return a[no].sum;
    return squery(no*2,l,r)+squery(no*2+1,l,r);
}
void schange(int idx,int v,int lim){
    s[idx]=v;
    idx=nod[idx];
    a[idx].sum=v;
    for(int i=idx>>1;i>=lim;i>>=1) a[i].mergeup(a[i*2],a[i*2+1]);
}
void mchange(int no,int l,int r,int k){
    if (a[no].l>r||a[no].r<l) return ;
    if (l<=a[no].l&&a[no].r<=r){
        int idx=a[no].maxn;
        while (s[idx]>=k){
            schange(idx,s[idx]%k,no);
            idx=a[no].maxn;
        }
        return;
    }
    mchange(no*2,l,r,k);
    mchange(no*2+1,l,r,k);
    a[no].mergeup(a[no*2],a[no*2+1]);
}
void prepare(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",&s[i]);
    build(1,1,n);
}
int main()
{
    prepare();
    while (m--){
        scanf("%d",&type);
        switch (type){
        case 1:{
            scanf("%d%d",&x,&y);
            printf("%lld\n",squery(1,x,y));
            break;
            }
        case 2:{
            scanf("%d%d%d",&x,&y,&k);
            mchange(1,x,y,k);
            break;
            }
        case 3:{
            scanf("%d%d",&x,&y);
            schange(x,y,1);
            break;
            }
        }
    }
}