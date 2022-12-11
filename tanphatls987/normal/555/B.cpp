#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("B.inp","r",stdin)
#define OUTPUT freopen("B.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;

const int inf=1e9;
const int MOD=1e9+7;
const int N=2e5+10;

int p[N],n,m,b[N],ans[N];
ll c[N],a[N][2];
struct bri{
    ll L,R;
    int idx;
    bri(ll _L=0,ll _R=0,int _idx=0){
        L=_L,R=_R,idx=_idx;
    }
}re[N];
int get(int x){
    int ans=0;
    while (x){
        ans+=b[x];
        x-=x&-x;
    }
    return ans;
}
void add(int x,int v){
    while (x<=m){
        b[x]+=v;
        x+=x&-x;
    }
}
int findpre(int v){
    int ans=0,pos=0;
    for(int i=1<<(int(log2(m)));i>0;i>>=1){
        int cur=pos+i;
        if (cur>m) continue;
        if (v>b[cur]) v-=b[cur],pos=cur;
        else if (b[cur]==v) ans=cur;
    }
    return ans;
}
bool comp(bri a,bri b){
    if (a.R==b.R) return a.L>b.L;
    return a.R<b.R;
}
bool compidx(int x,int y){
    return c[x]<c[y];
}
void solve(){
    REP(i,1,n){
        int L=lower_bound(c+1,c+m+1,re[i].L)-c,R=upper_bound(c+1,c+m+1,re[i].R)-c-1;
        int v1=get(R),v2=get(L-1);
        if (v1==v2){
            printf("No");
            return;
        }
        int sel=findpre(v2+1);
        ans[re[i].idx]=p[sel];
        add(sel,-1);
    }
    printf("Yes\n");
    REP(i,1,n) printf("%d ",ans[i]);
}
int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%I64d%I64d",a[i],a[i]+1);
    FOR(i,1,m) scanf("%I64d",c+i);
    FOR(i,1,m) p[i]=i;
    sort(p+1,p+m+1,compidx);
    sort(c+1,c+m+1);
    FOR(i,1,m) add(i,1);
    REP(i,1,n) re[i]=bri(a[i+1][0]-a[i][1],a[i+1][1]-a[i][0],i);
    sort(re+1,re+n,comp);
    solve();
}