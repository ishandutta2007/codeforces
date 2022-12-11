#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("A.inp","r",stdin)
#define OUTPUT freopen("A.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=2e5+10;

int n,m,k,bud,a[N][2],per[N];
ii cv[2][N];
ll ccost[N];

bool operator <(ii a,ii b){
    return a.X<b.X;
}
bool comp(int x,int y){
    return ccost[x]<ccost[y];
}
void prepare(){
    scanf("%d%d%d%d",&n,&m,&k,&bud);
    cv[0][0].X=cv[1][0].X=inf;
    FOR(type,0,1)
        FOR(i,1,n) scanf("%d",&cv[type][i].X),cv[type][i].Y=i;
    FOR(i,1,m)
        FOR(j,0,1) scanf("%d",a[i]+j);
    ///
    FOR(type,0,1)
        FOR(i,1,n) cv[type][i]=min(cv[type][i],cv[type][i-1]);
    FOR(i,1,m) a[i][0]--;
}
bool check(int mid,int type){
    FOR(i,1,m) ccost[i]=1LL*cv[a[i][0]][mid].X*a[i][1];
    FOR(i,1,m) per[i]=i;
    sort(per+1,per+m+1,comp);
    ll total=0;
    FOR(i,1,k) total+=ccost[per[i]];
    if (type){
        FOR(i,1,k) {
            int idx=per[i];
            printf("%d %d\n",idx,cv[a[idx][0]][mid].Y);
        }
    }
//    cout<<mid<<'\n';
//    FOR(i,1,m) cout<<ccost[i]<<" \n"[i==m];
    return total<=bud;
}
void solve(){
    int L=1,R=n;
    while (L<=R){
        int mid=(L+R)/2;
        if (check(mid,0)) R=mid-1;
        else L=mid+1;
    }
    if (L>n){
        printf("-1");
        return;
    }
    printf("%d\n",L);
    check(L,1);
}
int main(){
    prepare();
    solve();
}