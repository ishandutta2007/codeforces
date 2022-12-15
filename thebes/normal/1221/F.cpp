#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

const int MN = 5e5+5;
struct nou{ll x, y, w;}arr[MN];
ll n, m, i, j, st[6*MN], lz[6*MN], id[6*MN], x, y, ans=-1LL<<60, A, B;
map<ll,ll> mp, rev;

void build(ll i,ll s,ll e){
    if(s!=e){
        build(2*i+1,(s+e)/2+1,e);
        build(2*i,s,(s+e)/2);
        st[i]=max(st[2*i],st[2*i+1]);
        id[i]=id[2*i];
    }
    else st[i]=-rev[s], id[i]=s;
}

inline void upd_lz(ll i,ll s,ll e){
    st[i]+=lz[i];
    if(s!=e) lz[2*i]+=lz[i], lz[2*i+1]+=lz[i];
    lz[i]=0;
}

void upd(ll i,ll s,ll e,ll ss,ll se,ll v){
    upd_lz(i,s,e);
    if(s>=ss&&e<=se){
        lz[i]=v;
        upd_lz(i,s,e);
    }
    else{
        if((s+e)/2<ss) upd(2*i+1,(s+e)/2+1,e,ss,se,v), upd_lz(2*i,s,(s+e)/2);
        else if((s+e)/2>=se) upd(2*i,s,(s+e)/2,ss,se,v), upd_lz(2*i+1,(s+e)/2+1,e);
        else upd(2*i,s,(s+e)/2,ss,se,v), upd(2*i+1,(s+e)/2+1,e,ss,se,v);
        if(st[2*i]>st[2*i+1]){
            id[i] = id[2*i];
            st[i] = st[2*i];
        }
        else{
            id[i] = id[2*i+1];
            st[i] = st[2*i+1];
        }
    }
}

pll qu(ll i,ll s,ll e,ll ss,ll se){
    upd_lz(i,s,e);
    if(s>=ss&&e<=se) return make_pair(st[i],id[i]);
    else if((s+e)/2<ss) return qu(2*i+1,(s+e)/2+1,e,ss,se);
    else if((s+e)/2>=se) return qu(2*i,s,(s+e)/2,ss,se);
    else{
        pll a=qu(2*i,s,(s+e)/2,ss,se), b=qu(2*i+1,(s+e)/2+1,e,ss,se);
        if(a.first>b.first) return a;
        else return b;
    }
}
mt19937 mt(time(0));
int main(){
    for(scanf("%lld",&n),i=1;i<=n;i++){
        scanf("%lld%lld%lld",&arr[i].x,&arr[i].y,&arr[i].w);
        if(arr[i].x>arr[i].y) swap(arr[i].x,arr[i].y);
        mp[arr[i].x]=mp[arr[i].y]=0;
    }
    i=0;
    for(auto it=mp.begin();it!=mp.end();it++) it->second=++i, rev[i]=it->first;
    m = mp.size();
    build(1,1,m);
    sort(arr+1,arr+n+1,[](nou i,nou j){return i.x>j.x;});
    for(i=1;i<=n;i=j){
        for(j=i;j<=n&&arr[i].x==arr[j].x;j++)
            upd(1,1,m,mp[arr[j].y],m,arr[j].w);
        pll wtf = qu(1,1,m,mp[arr[i].x],m);
        wtf.first += arr[i].x;
        if(wtf.first>ans){
            ans = wtf.first;
            A = arr[i].x;
            B = rev[wtf.second];
        }
    }
    if(ans<0){
        ans = 0;
        A = 1000000001;
        B = 1000000001;
    }
    printf("%lld\n",ans);
    printf("%lld %lld %lld %lld\n",A,A,B,B);
    return 0;
}