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
const int N=1e6+10;

int n,h[N],x;
int main(){
    scanf("%d",&n);
    int ans=0;
    FOR(mod,1,n){
        int c1=n/mod,c2=n%mod;
//        printf("%d %d %d\n",mod,c1,c2);
        if (c1&1) h[mod-1]++;
        h[c2]++;
    }
    FORD(i,n,0) {
        h[i]+=h[i+1];
        if (h[i]&1) ans^=i;
    }
    while (n--){
        scanf("%d",&x);
        ans^=x;
    }
    cout<<ans;
}