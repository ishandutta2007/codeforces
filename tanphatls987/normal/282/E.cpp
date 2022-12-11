#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("E.inp","r",stdin)
#define OUTPUT freopen("E.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const ll inf=1e12;
const int MOD=1e9+7;
const int N=1e5+10,M=int(log2(inf)),alp=2;

int n;
ll a[N],L[N],R[N];
struct node{
    node *h[alp];
    node (){
        REP(i,0,alp) h[i]=NULL;
    }
};
node *root;
void tinsert(ll v){
    node *cur=root;
    FORD(i,M,0){
        int val=(v&(1LL<<i))>0;
        if (cur->h[val]==NULL) cur->h[val]=new node();
        cur=cur->h[val];
    }
}
ll get(ll v){
    node *cur=root;
    ll ans=0;
    FORD(i,M,0){
        int val=(v&(1LL<<i))>0;
        if (cur->h[val^1]!=NULL){
            cur=cur->h[val^1];
            ans+=1LL<<i;
        }else cur=cur->h[val];
    }
    return ans;
}
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%lld",a+i);
    root=new node();
}
ll solve(){
    ll ans=0;
    FOR(i,1,n) L[i]=L[i-1]^a[i];
    FORD(i,n+1,1){
        R[i]=a[i]^R[i+1];
        tinsert(R[i]);
        ans=max(ans,get(L[i-1]));
//        cout<<ans<<" "<<L[i-1]<<" "<<R[i]<<'\n';
    }
    return ans;
}
int main(){
    prepare();
    cout<<solve();
}