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
const int N=2e6+10;

int n,m,x,a[N],fi[N];
ll pos[N];
void prepare(){
    scanf("%d%d",&n,&m);
    REP(i,0,n) scanf("%d",a+i),a[n+i]=a[i];
    FOR(i,1,m) scanf("%d",&x),fi[x]=i;
}
int solve(){
    int ans=0;
    for(int r=0,l=0;r<2*n;r++){
        if (!fi[a[r]]) {
            l=r+1;
            continue;
        }
        if (l<r) pos[r]=fi[a[r]]+(pos[r-1]-fi[a[r]]+m-1)/m*m;
        else pos[r]=fi[a[r]];
        while (r-l>=n||pos[r]-pos[l]>=m) l++;
        ans=max(ans,r-l+1);
    }
//    REP(i,0,n<<1) printf("%lld ",pos[i]);ENDL;
    return ans;
}
int main(){
    prepare();
    cout<<solve();
}