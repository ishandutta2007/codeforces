#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
#define DEBUG 1
using namespace std;

namespace output{
    void __(short x){cout<<x;}
    void __(unsigned x){cout<<x;}
    void __(int x){cout<<x;}
    void __(long long x){cout<<x;}
    void __(unsigned long long x){cout<<x;}
    void __(double x){cout<<x;}
    void __(long double x){cout<<x;}
    void __(char x){cout<<x;}
    void __(const char*x){cout<<x;}
    void __(const string&x){cout<<x;}
    void __(bool x){cout<<(x?"true":"false");}
    template<class S,class T>
    void __(const pair<S,T>&x){__(DEBUG?"(":""),__(x.first),__(DEBUG?", ":" "),__(x.second),__(DEBUG?")":"");}
    template<class T>
    void __(const vector<T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    template<class T>
    void __(const set<T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    template<class T>
    void __(const multiset<T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    template<class S,class T>
    void __(const map<S,T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    void pr(){cout<<"\n";}
    template<class S,class... T>
    void pr(const S&a,const T&...b){__(a);if(sizeof...(b))__(' ');pr(b...);}
}

using namespace output;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,char> pic;
typedef pair<double,double> pdd;
typedef pair<ld,ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back
#define fox(i,x,y) for(int i=(x);i<=(y);i++)
#define foxr(i,x,y) for(int i=(y);i>=(x);i--)

const int MN = 2e5+5;
int n, m, i, j, x, y, on[MN], mrk[MN];
pii evt[2*MN], pos[MN]; ll sm[2], ans;

struct dblseg{
    struct idk{
        ll mn, sm, cnt;
    };
    struct nd{
        idk a; ll lz;
    }st[2][2*MN];
    ll n, m;
    void build(int id,int i,int s,int e){
        if(s<e){
            build(id,2*i,s,(s+e)/2);
            build(id,2*i+1,(s+e)/2+1,e);
            st[id][i].lz=st[id][i].a.mn=0;
            st[id][i].a.sm=st[id][2*i].a.sm+st[id][2*i+1].a.sm;
            st[id][i].a.cnt=st[id][2*i].a.cnt+st[id][2*i+1].a.cnt;
        }
        else if(s==e){
            st[id][i].a.mn=st[id][i].lz=0;
            st[id][i].a.sm=2*s-1+id;
            st[id][i].a.cnt=1;
        }
    }
    void init(int sz){
        n=ceil(sz/2.0);
        m=sz/2;
        build(0,1,1,n);
        build(1,1,1,m);
    }
    inline void upd_lz(int id,int i,int s,int e){
        if(st[id][i].lz){
            st[id][i].a.mn+=st[id][i].lz;
            if(s!=e){
                st[id][2*i].lz+=st[id][i].lz;
                st[id][2*i+1].lz+=st[id][i].lz;
            }
            st[id][i].lz=0;
        }
    }
    void upd(int id,int i,int s,int e,int ss,int se,int val){
        if(ss>se) return;
        upd_lz(id,i,s,e);
        if(s>=ss&&e<=se){st[id][i].lz=val;upd_lz(id,i,s,e);}
        else{
            if((s+e)/2<ss) upd(id,2*i+1,(s+e)/2+1,e,ss,se,val),upd_lz(id,2*i,s,(s+e)/2);
            else if((s+e)/2>=se) upd(id,2*i,s,(s+e)/2,ss,se,val),upd_lz(id,2*i+1,(s+e)/2+1,e);
            else upd(id,2*i,s,(s+e)/2,ss,se,val),upd(id,2*i+1,(s+e)/2+1,e,ss,se,val);
            st[id][i].a.mn=min(st[id][2*i].a.mn,st[id][2*i+1].a.mn);
            st[id][i].a.sm=(st[id][2*i].a.mn==st[id][i].a.mn?st[id][2*i].a.sm:0)+(st[id][2*i+1].a.mn==st[id][i].a.mn?st[id][2*i+1].a.sm:0);
            st[id][i].a.cnt=(st[id][2*i].a.mn==st[id][i].a.mn?st[id][2*i].a.cnt:0)+(st[id][2*i+1].a.mn==st[id][i].a.mn?st[id][2*i+1].a.cnt:0);
        }
    }
    idk qu(int id,int i,int s,int e,int ss,int se){
        if(ss>se) return {1<<30,0,0};
        upd_lz(id,i,s,e);
        if(s>=ss&&e<=se) return st[id][i].a;
        else if((s+e)/2<ss) return qu(id,2*i+1,(s+e)/2+1,e,ss,se);
        else if((s+e)/2>=se) return qu(id,2*i,s,(s+e)/2,ss,se);
        else{
            idk l=qu(id,2*i,s,(s+e)/2,ss,se), r=qu(id,2*i+1,(s+e)/2+1,e,ss,se);
            ll mn=min(l.mn,r.mn);
            return {mn,(l.mn==mn?l.sm:0)+(r.mn==mn?r.sm:0),(l.mn==mn?l.cnt:0)+(r.mn==mn?r.cnt:0)};
        }
    }
    inline void upd(int id,int s,int e,int delta){
        if(((s+1)&1)!=id) s++;
        if(((e+1)&1)!=id) e--;
        if(s>e) return;
        int l=(s-1)/2+1,r=(e-1)/2+1;
        upd(id,1,1,id?m:n,l,r,delta);
    }
    inline void upd(int s,int e,int delta){
        upd(0,s,e,delta);
        upd(1,s,e,delta);
    }
    inline pll qu(int s,int e){
        idk a[2];
        for(int i=0;i<2;i++){
            int l=s,r=e;
            if(((l+1)&1)!=i) l++;
            if(((r+1)&1)!=i) r--;
            if(l>r){
                a[i]={1<<30,0,0};
                continue;
            }
            l=(l-1)/2+1,r=(r-1)/2+1;
            a[i]=qu(i,1,1,i?m:n,l,r);
        }
        return make_pair((!a[0].mn?a[0].sm:0)+(!a[1].mn?a[1].sm:0),(!a[0].mn?a[0].cnt:0)+(!a[1].mn?a[1].cnt:0));
    }
}seg[2];

int main(){
    for(scanf("%d%d",&n,&m),i=1;i<=n;i++){
        scanf("%d%d",&x,&y);
        evt[2*i-1]={x,i};
        evt[2*i]={y+1,i};
        pos[i]={x,y};
        mrk[x]++; mrk[y+1]--;
    }
    int cnt=0;
    for(i=1;i<=m;i++){
        mrk[i]+=mrk[i-1];
        if(!mrk[i]) cnt++;
        else cnt=0;
        ans-=1LL*cnt*(cnt+1)/2;
    }
    seg[0].init(m); seg[1].init(m);
    sort(evt+1,evt+2*n+1,[](pii i,pii j){return i.first<j.first;});
    for(i=j=1;i<=m;i++){
        while(j<=2*n&&evt[j].first<=i){
            int id=evt[j++].second;
            if(!on[id]){
                seg[(i&1)^1].upd(1,i-1,1);
                seg[(i&1)^1].upd((i&1)^1,pos[id].first,pos[id].second,1);
                seg[i&1].upd(i&1,pos[id].first,pos[id].second,1);
            }
            else{
                int sta=pos[id].first;
                if((pos[id].second-pos[id].first+1)&1){
                    seg[(sta&1)^1].upd(1,sta-1,-1);
                    seg[(sta&1)^1].upd((sta&1)^1,pos[id].first,pos[id].second,-1);
                    seg[(sta&1)^1].upd(sta&1,pos[id].first,pos[id].second,1);
                }
                else{
                    seg[sta&1].upd(sta&1,pos[id].first,pos[id].second,-1);
                    seg[sta&1].upd(1,sta-1,1);
                    seg[sta&1].upd((sta&1)^1,pos[id].first,pos[id].second,1);
                }
            }
            on[id]^=1;
        }
        pll res=seg[i&1].qu(1,i);
        ans+=1LL*(i+1)*res.second-res.first;
    }
    printf("%lld\n",ans);
    return 0;
}