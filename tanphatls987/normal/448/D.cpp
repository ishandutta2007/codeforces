#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("C.inp","r",stdin)
#define OUTPUT freopen("C.out","w",stdout)
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

int n,m;
ll k;
bool check(ll M){
    ll sum=0;
    FOR(i,1,n) sum+=min(ll(m),M/i);
    return sum>=k;
}
int main(){
    cin>>n>>m>>k;
    if (n>m) swap(n,m);
    ll L=1,R=1LL*n*m;
    while (L<=R){
        ll M=(L+R)/2;
        if (check(M)) R=M-1;
        else L=M+1;
    }
    cout<<L;
}