#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n;
ll x[MAXN],y[MAXN],c[MAXN];
ll w[MAXN];
vector<ll> v;
struct segtree{
    P maxi[4*MAXN];
    ll lazy[4*MAXN];
    void pushup(ll k){
        maxi[k]=max(maxi[k*2],maxi[k*2+1]);
    }
    void pushdown(ll k){
        if(!lazy[k]) return;
        for(ll i=k*2;i<=k*2+1;i++){
            maxi[i].F+=lazy[k];
            lazy[i]+=lazy[k];
        }
        lazy[k]=0;
    }
    void build(ll k,ll l,ll r){
        lazy[k]=0;
        if(l==r){
            maxi[k].F=-w[l];
            maxi[k].S=l;
            return;
        }
        ll mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(ll k,ll l,ll r,ll x,ll y,ll v){
        if(x>r||l>y) return;
        if(l>=x&&r<=y){
            maxi[k].F+=v; lazy[k]+=v;
            return;
        }
        pushdown(k);
        ll mid=(l+r)/2;
        update(k*2,l,mid,x,y,v); update(k*2+1,mid+1,r,x,y,v);
        pushup(k);
    }
    P query(ll k,ll l,ll r,ll x,int y){
        if(x>r||l>y) return make_pair(-INF,0);
        if(l>=x&&r<=y) return maxi[k];
        pushdown(k);
        ll mid=(l+r)/2;
        return max(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
    }
}seg;
bool has[MAXN];
vector<P> upd[MAXN];
int main(){
    scanf("%lld",&n);
    memset(has,false,sizeof(has));
    for(ll i=0;i<n;i++){
        scanf("%lld%lld%lld",&x[i],&y[i],&c[i]);
        if(x[i]>y[i]) swap(x[i],y[i]);
        v.push_back(x[i]); v.push_back(y[i]);
        if(x[i]<=1000000) has[x[i]]=true;
        if(y[i]<=1000000) has[y[i]]=true;
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    ll sz=(int)v.size();
    for(ll i=0;i<sz;i++) w[i+1]=v[i]-v[0];
    seg.build(1,1,sz);
    for(ll i=0;i<n;i++){
        x[i]=lower_bound(v.begin(),v.end(),x[i])-v.begin()+1;
        y[i]=lower_bound(v.begin(),v.end(),y[i])-v.begin()+1;
        upd[x[i]].push_back(P(y[i],c[i]));
        seg.update(1,1,sz,y[i],sz,c[i]);
    }
    ll ans=0;
    ll x=-1,y=-1;
    for(int i=1;i<=1000001;i++)
        if(!has[i]){
            x=i;
            y=i;
            break;
        }
    for(ll i=1;i<=sz;i++){
        P p=seg.query(1,1,sz,i,sz);
        if(p.F>ans){
            ans=p.F;
            x=v[i-1];
            y=v[p.S-1];
        }
        for(auto p:upd[i]) seg.update(1,1,sz,p.F,sz,-p.S);
        if(i!=sz) seg.update(1,1,sz,i+1,sz,v[i]-v[i-1]);
    }
    printf("%lld\n",ans);
    printf("%lld %lld %lld %lld\n",x,x,y,y);
}
//QAQ