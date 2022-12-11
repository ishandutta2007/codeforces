#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("630.inp","r",stdin)
#define OUTPUT freopen("630.out","w",stdout)
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
const int N=0;
const double mul=1.000000011;


int main(){
    int n;
    cin>>n;
    ll ans1=24,ans2=(n-3)*36;
    REP(i,1,n-2) ans1*=4;
    REP(i,1,n-3) ans2*=4;
    cout<<ans1+ans2;
}