#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("c.inp","r",stdin)
#define OUTPUT freopen("c.out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=0;

int main(){
    ll x;
    int n;
    cin>>n>>x;
    ll ans=0;
    int cur=0;
    for(ll i=0,bar=1LL<<(n-1);i<n;bar>>=1,i++){
        ans++;
        bool wrong=(!cur&&x>bar)||(cur&&x<=bar);
        if (wrong) ans+=(1LL<<(n-i))-1,cur=1-cur;
        if (x>bar) x-=bar;
        cur=1-cur;
        //cout<<i<<" "<<ans<<" "<<x<<" "<<bar<<'\n';
    }
    cout<<ans;
}