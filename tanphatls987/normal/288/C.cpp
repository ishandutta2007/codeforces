#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("C.inp","r",stdin)
#define OUTPUT freopen("C.out","w",stdout)
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

int ans[N],n;
void solve(int n){
    if (n<=0) return;
    int bar=1<<int(log2(n));
//    cout<<n<<" "<<bar<<'\n';
    FOR(i,bar,n) ans[i]=i^(bar*2-1);
    int rem=n-bar+1;
    REP(i,0,rem) ans[bar-i-1]=bar+i;
    solve(bar-rem-1);
}
int main(){
    cin>>n;
    solve(n);
    ll sum=0;
    FOR(i,0,n) sum+=ans[i]^i;
    printf("%I64d\n",sum);
    FOR(i,0,n) printf("%d ",ans[i]);
}