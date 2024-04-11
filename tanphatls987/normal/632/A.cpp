#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("draft.inp","r",stdin)
#define OUTPUT freopen("draft.out","w",stdout)
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

int n,m;
string s[100];
int main(){
//    freopen("input.inp","r",stdin);
    cin>>n>>m;
    ll ans=0;
    FOR(i,1,n) cin>>s[i];
    FORD(i,n,1){
        ans<<=1;
        if (s[i].length()>4) ans++;
    }
    cout<<ans*m-__builtin_popcountll(ans)*m/2;
}