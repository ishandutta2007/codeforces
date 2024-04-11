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

int n,k,a[N],h[N];
void modified(int &ans,int x,int v){
    if (v==-1) ans-=(h[x]==1);
    else ans+=(h[x]==0);
    h[x]+=v;
}
void prepare(){
    scanf("%d%d",&n,&k);
    FOR(i,1,n) scanf("%d",a+i);
}
void solve(){
    int aL=0,aR=-1;
    int cur=0;
    for(int R=1,L=1;R<=n;R++){
        modified(cur,a[R],1);
        while (cur>k) modified(cur,a[L++],-1);
        if (R-L>aR-aL) aL=L,aR=R;
//        cout<<R<<" "<<L<<" "<<cur<<'\n';
    }
    cout<<aL<<" "<<aR;
}
int main(){
    prepare();
    solve();
}