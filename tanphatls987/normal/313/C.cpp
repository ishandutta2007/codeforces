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
const int N=2e6+10;

int n;
ll a[N];
int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%I64d",a+i);
    sort(a+1,a+n+1,greater<int>());
    FOR(i,1,n) a[i]+=a[i-1];
    ll ans=0;
    for(int i=1;i<=n;i<<=2) ans+=a[i];
    cout<<ans;
}