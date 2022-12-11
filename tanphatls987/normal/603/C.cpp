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

int k;
int cal(int x,int k){
    if (!x) return 0;
    if (x&1) return (x/2<=k%2);
    int h[4]={0};
    h[cal(x-1,k)]=1;
    h[(k&1)?cal(x>>1,k):0]=1;
    int ans=0;
    while (h[ans]) ans++;
    return ans;
}
int main(){
    int n,x;
    scanf("%d%d",&n,&k);
    int ans=0;
    while (n--){
        scanf("%d",&x);
        ans^=cal(x,k);
    }
    cout<<(ans?"Kevin":"Nicky");
}