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
const string fi="Stannis",se="Daenerys";

int n,k,a[2];
string solve(){
    int last=(n-k)%2;
    if (k==n) return (a[1]%2)?fi:se;
    if (last){
        if (a[1]<=(n-k)/2) return se;
        if (a[0]>=(n-k+1)/2) return fi;
        if (a[0]<=(n-k)/2&&k%2==0) return se;
        return fi;
    }
    if (a[1]<=(n-k)/2) return se;
    if (a[0]<=(n-k+1)/2&&k%2) return fi;
    return se;
}
int main(){
    scanf("%d%d",&n,&k);
    int x;
    REP(i,0,n){
        scanf("%d",&x);
        a[x%2]++;
    }
    cout<<solve();
}