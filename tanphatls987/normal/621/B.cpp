#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("B.inp","r",stdin)
#define OUTPUT freopen("B.out","w",stdout)
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
const int N=1e3+10,M=N<<1;

int c2[M],c1[M];
int main(){
    int n,x,y;
    scanf("%d",&n);
    while (n--){
        scanf("%d%d",&x,&y);
        c1[x-y+N]++;
        c2[x+y]++;
    }
    ll ans=0;
    REP(i,0,M) ans+=1LL*c1[i]*(c1[i]-1)/2+1LL*c2[i]*(c2[i]-1)/2;
    cout<<ans;
}