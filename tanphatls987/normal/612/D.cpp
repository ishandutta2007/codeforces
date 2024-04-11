#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("D.inp","r",stdin)
#define OUTPUT freopen("D.out","w",stdout)
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
const int N=1e6+10;

int n,n1,k,p[N<<1],h[N<<1],a[N][2],g[N<<1];
void prepare(){
    scanf("%d%d",&n,&k);
    FOR(i,1,n)
        FOR(j,0,1){
            scanf("%d",a[i]+j);
            p[j*n+i]=a[i][j];
        }
    sort(p+1,p+n*2+1);
    n1=unique(p+1,p+n*2+1)-p-1;
    FOR(i,1,n){
        int L=lower_bound(p+1,p+n1+1,a[i][0])-p;
        int R=lower_bound(p+1,p+n1+1,a[i][1])-p;
        g[R]++;
        h[L]++,h[R]--;
    }
    FOR(i,1,n1) h[i]+=h[i-1];
}
void solve(){
    vector <ii> ans;
    FOR(en,1,n1) if (h[en]>=k){
        int st=en;
        while (en<=n1&&h[en]>=k) en++;
        ans.push_back(ii(p[st],p[en]));
    }else if (h[en]+g[en]>=k) ans.push_back(ii(p[en],p[en]));
    printf("%d\n",ans.size());
    for(auto i:ans) printf("%d %d\n",i.X,i.Y);
}
int main(){
    prepare();
    solve();
}