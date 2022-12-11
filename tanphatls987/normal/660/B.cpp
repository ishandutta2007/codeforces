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
const int N=1e2+10;
const int d[4]={1,0,2,3};

int n,m,a[N][4];

int main(){
//    freopen("input.inp","r",stdin);
    cin>>n>>m;
    REP(i,0,min(m,2*n))
        a[i/2][(i%2)*3]=i+1;
    REP(i,0,m-2*n)
        a[i/2][1+i%2]=2*n+i+1;
    REP(i,0,n)
        for(auto j:d) if (a[i][j]) cout<<a[i][j]<<" ";
}