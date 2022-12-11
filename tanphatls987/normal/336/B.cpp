#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("draft.inp","r",stdin)
#define OUTPUT freopen("draft.out","w",stdout)
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
const int N=0;

ll n;
int r;
ll sum(int x){
    return 1LL*x*(x+1)/2;
}
int main(){
    cin>>n>>r;
    ll ans=n<<1;
    FOR(i,1,n){
        if (i>1) ans+=(sum(i-2)+1)<<1;
        if (i<n) ans+=(sum(n-i-1)+1)<<1;
    }
    printf("%.9f",r*(ans+2*sqrt(2)*(n-1)*(n-1))/(1LL*n*n));
}