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

const int inf=1e9+10;
const ll linf=1e17;
const int MOD=1e9+7;
const int N=1e6+10,M=1e5+10;

int n,cd,ca,h[N],t[N],a[N];
ll g[N];
int cost[N];
vector <int> pri;
map <int,int> imp;
template <class T>
bool minimize(T &x,T y){
    if (x>y) x=y;else return 0;
    return 1;
}
void standin(int cur){
    for(auto i:pri) {
        if (1LL*i*i>cur) break;
        if (cur%i==0){
            imp[i]=1;
            while (cur%i==0) cur/=i;
        }
    }
    if (cur!=1) imp[cur]=1;
}
void prepare(){
    REP(i,2,M) if (!h[i]){
        pri.push_back(i);
        for(int j=i;j<M;j+=i) h[j]=i;
    }
    scanf("%d%d%d",&n,&cd,&ca);
    FOR(i,1,n) scanf("%d",a+i);
    ///
    FOR(j,-1,1) standin(a[1]+j);
    FOR(j,-1,1) standin(a[n]+j);
}
ll check(int x){
    FOR(i,1,n){
        cost[i]=inf;
        FOR(j,-1,1) if ((a[i]+j)%x==0) minimize(cost[i],(j!=0)*ca);
    }
    g[0]=0;
    FOR(i,1,n) if (cost[i]!=inf) g[i]=min(g[i-1]+cost[i],linf);
    else g[i]=linf;
    FOR(i,0,n) g[i]+=1LL*(n-i)*cd;
    FOR(i,1,n) t[i]=(g[i]<g[t[i-1]])?i:t[i-1];
    ll cur=0,ans=*min_element(g+1,g+n+1);
    FORD(i,n,1) {
        if (cost[i]==inf) cur=linf;
        else cur=min(cur+cost[i],linf);
        ans=min(ans,g[t[i-1]]+cur-1LL*(n-i+1)*cd);
    }
//    cout<<x<<" "<<ans<<'\n';
//    FOR(i,1,n) cout<<cost[i]<<" ";ENDL;
    return ans;
}
ll solve(){
    ll ans=linf;
    for(auto x:imp) ans=min(ans,check(x.X));
    return ans;
}
int main(){
    prepare();
    cout<<solve();
}