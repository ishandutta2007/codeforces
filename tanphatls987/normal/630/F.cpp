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
    ll cur=1,den=1,ans=0;
    for(int i=1;i<=7;i++){
        cur=cur*(n-i+1)/i;
        if (i>4) ans+=cur;
    }
    cout<<ans;
}