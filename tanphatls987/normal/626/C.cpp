#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("C.inp","r",stdin)
#define OUTPUT freopen("C.out","w",stdout)
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

int main(){
    int n,m;
    cin>>n>>m;
    int L=1,R=inf;
    while (L<=R){
        int mid=(L+R)/2;
        int ua=mid/6,u2=mid/2-ua,u3=mid/3-ua;
        if (max(n-u2,0)+max(m-u3,0)<=ua) R=mid-1;
        else L=mid+1;
    }
    cout<<L;
}