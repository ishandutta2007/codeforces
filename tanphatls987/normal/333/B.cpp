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
const int N=1e3+10;
int h[N][N],n,m,x,y;
int solve(){
    int ans=0;
    REP(i,2,n) {
        if (n%2&&i==(n+1)/2) ans+=(h[0][i]&h[1][i])==0;
        else ans+=(h[0][i]==0)+(h[1][i]==0);
    }
    return ans;
}
int main(){
    scanf("%d%d",&n,&m);
    while (m--){
        scanf("%d%d",&x,&y);
        h[0][x]=1,h[1][y]=1;
    }
    cout<<solve();
}