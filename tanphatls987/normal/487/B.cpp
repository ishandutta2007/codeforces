#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cmath>
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

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9+10;
const int MOD=1e9+7;
const int N=1e5+10;

int a[N],r[N],n,k,len,b[N<<2]={0};
void build(int node,int L,int R){
    b[node]=inf;
    if (L==R) return;
    build(node*2,L,(L+R)/2);
    build(node*2+1,(L+R)/2+1,R);
}
void update(int node,int L,int R,int M,int val){
    if (L>M||R<M) return;
    if (L==R&&L==M){
        b[node]=min(b[node],val);
        return;
    }
    update(node*2,L,(L+R)/2,M,val);
    update(node*2+1,(L+R)/2+1,R,M,val);
    b[node]=min(b[node*2],b[node*2+1]);
}
int query(int node,int L,int R,int l,int r){
    if (L>r||R<l) return inf;
    if (l<=L&&R<=r) return b[node];
    return min(query(node*2,L,(L+R)/2,l,r),query(node*2+1,(L+R)/2+1,R,l,r));
}
void solve(){
    a[0]=inf;
    priority_queue <ii> ma,mi;
    ma.push(ii(a[n],n));
    mi.push(ii(-a[n],n));
    for(int R=n,L=n;R>=len;R--){
        //printf("%d\n",R);
        while (1LL*ma.top().X+mi.top().X<=k){
            //printf("%d %d %d\n",L,ma.top().Y,mi.top().Y);
            L--;
            ma.push(ii(a[L],L));
            mi.push(ii(-a[L],L));
        }
        r[R]=L;
        while (ma.top().Y>=R) ma.pop();
        while (mi.top().Y>=R) mi.pop();
    }
    //FOR(i,len,n) printf("%d ",r[i]);
    build(1,0,n);
    update(1,0,n,0,0);
    FOR(i,len,n) if (r[i]<=i-len) update(1,0,n,i,query(1,0,n,r[i],i-len)+1);
    int ans=query(1,0,n,n,n);
    if (ans>=inf) printf("-1");else printf("%d",ans);
}
int main(){
    scanf("%d%d%d",&n,&k,&len);
    FOR(i,1,n) scanf("%d",a+i);
    solve();
}