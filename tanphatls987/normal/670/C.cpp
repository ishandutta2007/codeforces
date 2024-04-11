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
const int N=2e5+10;

ll f[N];
map <int,int> h;
void prepare(){
    int n,x;
    scanf("%d",&n);
    while (n--){
        scanf("%d",&x);
        h[x]++;
    }
}
int solve(){
    int m,x;
    scanf("%d",&m);
    FORD(type,1,0)
        FOR(i,1,m){
            scanf("%d",&x);
            f[i]+=(type?1000000LL:1LL)*h[x];
        }
    return max_element(f+1,f+m+1)-f;
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    cout<<solve();
}