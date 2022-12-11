#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("B.inp","r",stdin)
#define OUTPUT freopen("B.out","w",stdout)
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

ll ans[N];
ii a[N];
int n,m,q[N];
void prepare(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d%d",&a[i].X,&a[i].Y);
}
void solve(){
    int top=1,bot=0;
    ll stime=0;
    FOR(i,1,n){
        while (top<=bot){
            stime=max(stime,1LL*a[q[top]].X);
            if (stime+a[q[top]].Y<=a[i].X) {
                stime+=a[q[top]].Y;
                ans[q[top++]]=stime;
            }else break;
        }
        if (bot-top+1<=m) q[++bot]=i;
    }
    while (top<=bot){
        stime=max(stime,1LL*a[q[top]].X);
        stime+=a[q[top]].Y;
        ans[q[top++]]=stime;
    }
    FOR(i,1,n) printf("%lld ",ans[i]?ans[i]:-1);
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    solve();
}