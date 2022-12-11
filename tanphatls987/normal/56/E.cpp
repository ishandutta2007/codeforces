#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("56e.inp","r",stdin)
#define OUTPUT freopen("56e.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e5+10;

int rmq[N][20],n,ans[N],f[N];
struct dom{
    int x,w,idx;
}a[N];
bool comp(dom a,dom b){
    return a.x<b.x;
}
int larger(int x,int y){
    if (a[x].x+a[x].w>a[y].x+a[y].w) return x;
    return y;
}
int RMQ(int x,int y){
    int bar=int(log2(y-x+1));
    return larger(rmq[x][bar],rmq[y-(1<<bar)+1][bar]);
}
int main(){
    scanf("%d",&n);
    FOR(i,1,n) {
        scanf("%d%d",&a[i].x,&a[i].w);
        a[i].idx=i;
    }
    sort(a+1,a+n+1,comp);
    //FOR(i,1,n) printf("%d %d %d\n",a[i].x,a[i].w,a[i].idx);
    FOR(i,1,n) rmq[i][0]=i;
    FOR(bar,1,int(log2(n)))
        FOR(i,1,n-(1<<bar)+1)
            rmq[i][bar]=larger(rmq[i][bar-1],rmq[i+(1<<(bar-1))][bar-1]);
    FORD(i,n,1){
        int len=a[i].x+a[i].w-1;
        int L=i,R=n;
        while (L<=R){
            int M=(L+R)/2;
            if (len>=a[M].x) L=M+1;
            else R=M-1;
        }
        int sel=RMQ(i,L-1);
        //printf("%d %d %d\n",i,L,sel);
        if (sel==i) f[i]=L-i;
        else f[i]=f[sel]+sel-i;
        ans[a[i].idx]=f[i];
    }
    FOR(i,1,n) printf("%d ",ans[i]);
}