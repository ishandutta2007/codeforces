#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("a.inp","r",stdin)
#define OUTPUT freopen("a.out","w",stdout)
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

int h[N],t[N],n,x;
int main(){
    scanf("%d",&n);
    while (n--){
        scanf("%d",&x);
        int tmp=x;
        int rx=0;
        rx+=4*(x>=100);x%=100;
        rx+=2*(x>=10);x%=10;
        rx+=(x>0);
        h[rx]=1;
        t[rx]=tmp;
    }
    int ans=0;
    REP(i,0,256){
        bool ok=1;
        FOR(j,0,7) if (!h[j]&&(i&(1<<j))) ok=0;
        FOR(j,0,7) if (i&(1<<j))
            FOR(k,j+1,7) if ((i&(1<<k))&&(j&k)) ok=0;
        if (ok&&__builtin_popcount(ans)<__builtin_popcount(i)) ans=i;
    }
    cout<<__builtin_popcount(ans)<<'\n';
    FOR(j,0,7) if (ans&(1<<j)) cout<<t[j]<<" ";
}