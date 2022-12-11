#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("A.inp","r",stdin)
#define OUTPUT freopen("A.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+9;
const int N=0;

int power(int x,int y){
    int ans=1;
    while (y){
        if (y&1) ans=1LL*ans*x%MOD;
        x=1LL*x*x%MOD;
        y>>=1;
    }
    return ans;
}
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    int rem=max(0LL,n-1LL*(n-m)*k)/k;
//    cout<<rem<<'\n';
    cout<<(2LL*(power(2,rem)+MOD-1)*k+m-rem*k)%MOD;
}