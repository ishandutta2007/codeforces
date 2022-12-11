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
typedef pair<ll,ll> pll;

const int inf=1e9;
const ll linf=1e18;
const int MOD=1e9+7;
const int N=2e5+10;

int n,a[N];
ll ssum[N];
pll line[N],b[N<<2];
ll cal(pll a,ll x){
    return a.X*x+a.Y;
}
void push_down(int node,int L,int R,pll cur){
//        cout<<node<<" "<<L<<" "<<R<<" "<<'\n';
    ll cL=cal(b[node],L),cR=cal(b[node],R);
    ll nL=cal(cur,L),nR=cal(cur,R);
    if (nL<=cL&&nR<=cR){
        b[node]=cur;
        return;
    }
    if (nL>=cL&&nR>=cR) return;
    int mid=(L+R)/2;
    ll cM=cal(b[node],mid),nM=cal(cur,mid);
    if (nL<=cL){
        if (nM<=cM){
            push_down(node*2+1,mid+1,R,b[node]);
            b[node]=cur;
        }else push_down(node*2,L,mid,cur);
        return;
    }
    if (nM>=cM) push_down(node*2+1,mid+1,R,cur);
    else{
        push_down(node*2,L,mid,b[node]);
        b[node]=cur;
    }
}
void update(int node,int L,int R,int l,int r,pll cur){
//        cout<<node<<" "<<L<<" "<<R<<" "<<l<<" "<<r<<'\n';
    if (L>r||R<l) return;
    if (l<=L&&R<=r){
        push_down(node,L,R,cur);
        return;
    }
    update(node*2,L,(L+R)/2,l,r,cur);
    update(node*2+1,(L+R)/2+1,R,l,r,cur);
}
ll get(int node,int L,int R,int idx){
    if (L>idx||R<idx) return linf;
    ll ans=cal(b[node],idx);
    if (L<R) ans=min(ans,min(get(node*2,L,(L+R)/2,idx),get(node*2+1,(L+R)/2+1,R,idx)));
    return ans;
}
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    FORD(i,n,1) ssum[i]=ssum[i+1]+a[i];
    line[n+1]=pll(0,0);
    FORD(i,n,1) line[i]=pll(-ssum[i],line[i+1].Y+1LL*i*a[i]);
    REP(i,0,N<<2) b[i]=pll(inf,linf);
    FOR(i,1,n+1) update(1,0,n,0,i-1,line[i]);
//    FOR(i,1,n) cout<<ssum[i]<<" \n"[i==n];
//    FOR(i,1,n) cout<<line[i].Y<<" \n"[i==n];
}
ll solve(){
    ll ans=-linf;
    REP(i,0,n)
        ans=max(ans,line[i+1].Y-ssum[i+1]*i-get(1,0,n,i));
    return ans;
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    cout<<solve();
}