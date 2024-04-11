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
const int N=5e3+10;

int n,a[N],h[N],ans[N];
void modified(int &cur,int x){
    h[x]++;
    if (h[x]>h[cur]) cur=x;
    if (h[x]==h[cur]&&x<=cur) cur=x;
}
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
}
void solve(){
    FOR(st,1,n){
        memset(h,0,sizeof(h));
        int use=1;
        FOR(i,st,n) {
            modified(use,a[i]);
            ans[use]++;
        }
    }
    FOR(i,1,n) printf("%d ",ans[i]);
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    solve();
}