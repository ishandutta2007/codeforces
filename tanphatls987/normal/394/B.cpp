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

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e6+10;

int n,m,num[N],ans[N];
void build(){
    REP(i,1,n-1) num[i]=9;
    num[0]=10-m;
}
bool ok(int x){
    memset(ans,0,sizeof(ans));
    REP(i,0,n){
        ans[i]+=x*num[i];
        ans[i+1]=ans[i]/10;
        ans[i]%=10;
    }
//    cout<<x<<'\n';
//    FORD(i,n,0) cout<<ans[i];ENDL;
    for(int i=n+1,sum=0;i>=0;i--){
        sum=(sum*10+ans[i]);
        ans[i]=sum/(10*m-1);
        sum%=(10*m-1);
        if (i==0&&sum) return 0;
    }
    int len=n+1;
    while (!ans[len]) len--;
    if (len==n-2){
        FORD(i,len,0) printf("%d",ans[i]);
        printf("%d",x);
        return 1;
    }
    return 0;
}
void solve(){
    if (n==1){
        if (m==1) printf("1");
        else printf("Impossible");
        return;
    }
    build();
    FOR(i,1,9) if (ok(i)) return;
    printf("Impossible");
}
int main(){
    cin>>n>>m;
    solve();
}