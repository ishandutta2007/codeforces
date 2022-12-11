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
const int N=2e3+10,M=1300;

int n,x,y,t,d,f[105][N];
int main(){
    cin>>x>>y>>t>>d;
    FOR(i,0,M) f[1][i]=-inf;
    f[1][x]=x;
    FOR(T,2,t)
        FOR(i,0,M){
            f[T][i]=-inf;
            FOR(j,max(i-d,0),min(i+d,M)) f[T][i]=max(f[T][i],f[T-1][j]+i);
        }
    cout<<f[t][y];
}