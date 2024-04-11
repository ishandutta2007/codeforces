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
const int N=1e3+10;

int n,m,a1,a2,b1,b2,h[N];
void prepare(){
    scanf("%d%d",&n,&m);
    scanf("%d%d%d%d",&a1,&a2,&b1,&b2);
    if (n==4||m<=n){
        printf("-1");
        exit(0);
    }
    h[a1]=h[a2]=h[b1]=h[b2]=1;
}
void solve(){
    printf("%d %d ",a1,b1);
    FOR(i,1,n) if (!h[i]) printf("%d ",i);
    printf("%d %d\n",b2,a2);
    printf("%d %d ",b1,a1);
    FOR(i,1,n) if (!h[i]) printf("%d ",i);
    printf("%d %d",a2,b2);
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    solve();
}