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
const int d[5]={0,2,4,3,1};

string s;
int main(){
    cin>>s;
    int base=0;
    REP(i,0,5) base=10*base+s[d[i]]-'0';
    ll ans=1;
    FOR(i,1,5) ans=ans*base%100000;
    printf("%05lld",ans);
}