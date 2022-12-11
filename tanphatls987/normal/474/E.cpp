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

typedef long long ll;
typedef pair<int,int> ii;

const ll inf=1e15+10;
const int MOD=1e9+7;
const int N=1e5+10;


int b[2][N],f[N],t[N],n,d,m;
ll a[N],r[N];
bool maximize(int& a,int b){
    if (f[a]<f[b]) a=b;else return false;return true;
}
void update(int key,int idx,int val){
    if (key==0){
        while (idx){
            maximize(b[0][idx],val);
            idx-=idx&-idx;
        }
        return;
    }
    while (idx<=m){
        maximize(b[1][idx],val);
        idx+=idx&-idx;
    }
}
int get(int key,int idx){
    int tmp=n+1;
    if (key==0){
        while (idx<=m){
            maximize(tmp,b[0][idx]);
            idx+=idx&-idx;
        }
    }else{
        while (idx){
            maximize(tmp,b[1][idx]);
            idx-=idx&-idx;
        }
    }
    return tmp;
}
void prepare(){
    scanf("%d%d",&n,&d);
    FOR(i,1,n) scanf("%lld",a+i);
    r[1]=-inf;a[0]=-inf;r[0]=0;
    FOR(i,1,n) r[i+1]=a[i];
    sort(r+1,r+n+2);
    m=0;
    FOR(i,1,n+1) if (r[i]!=r[m]) r[++m]=r[i];
}
void trace(int idx){
    if (t[idx]<=n){
        printf("%d ",t[idx]);
        trace(t[idx]);
    }
}
void solve(){
    FOR(i,1,m+1) b[0][i]=b[1][i]=n+1;
    f[n+1]=0;
    //FOR(i,1,m) printf("%lld ",r[i]);
    //ENDL;
    FORD(i,n,0){
        int tmp=n+1;
        int idx=lower_bound(r+1,r+m+1,a[i]-d)-r;
        if (r[idx]+d>a[i]) idx--;
        idx=max(idx,1);
        //printf("%d ",idx);
        maximize(tmp,get(1,idx));
        idx=lower_bound(r+1,r+m+1,a[i]+d)-r;
        //printf("%d ",idx);
        maximize(tmp,get(0,idx));
        t[i]=tmp;
        f[i]=f[tmp]+1;
        idx=lower_bound(r+1,r+m+1,a[i])-r;
        //printf("%d\n",idx);
        FOR(j,0,1) update(j,idx,i);
        //FOR(k,0,1) {FOR(j,1,m) printf("%d ",b[k][j]);ENDL;}
    }
    printf("%d\n",f[0]-1);
    trace(0);
}
int main(){
    prepare();
    solve();
}