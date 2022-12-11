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

int n;
int solve(){
    if (n==0) return 1;
    int cur=n+1;
    int ans=0;
    FOR(i,0,n){
        ll lim=1LL*n*n-1LL*i*i;
        int last=cur;
        while (1LL*cur*cur>lim) cur--,ans++;
        ans+=cur==last;
    }
    return 4*(ans-1);
}
int main(){
    scanf("%d",&n);
    cout<<solve();
}