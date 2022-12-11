#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("359.inp","r",stdin)
#define OUTPUT freopen("359.out","w",stdout)
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
const int N=100;

int main(){
    int n,m,x;
    scanf("%d%d",&n,&m);
    int ans=4;
    REP(i,0,n)
        REP(j,0,m) {
            scanf("%d",&x);
            if (!x) continue;
            if (i==0||i==n-1||j==0||j==m-1) ans=2;
        }
    cout<<ans;
}