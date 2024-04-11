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

const int MN = 1e5+5;
struct idk{int l, v, r, id;}arr[MN];
int n, i, j, ans, l, r, st[3*MN], id[3*MN], lz[3*MN]; vi sna;

void build(int i,int s,int e){
    if(s!=e){
        build(2*i,s,(s+e)/2);
        build(2*i+1,(s+e)/2+1,e);
        id[i]=st[2*i]>st[2*i+1]?id[2*i]:id[2*i+1];
        st[i]=max(st[2*i],st[2*i+1]);
    }
    else st[i]=0, id[i]=s;
}

inline void upd_lz(int i,int s,int e){
    if(lz[i]){
        st[i]+=lz[i];
        if(s!=e) lz[2*i]+=lz[i],lz[2*i+1]+=lz[i];
        lz[i]=0;
    }
}

void upd(int i,int s,int e,int ss,int se,int val){
    upd_lz(i,s,e);
    if(s>=ss&&e<=se){lz[i]=val;upd_lz(i,s,e);}
    else{
        if((s+e)/2<ss) upd(2*i+1,(s+e)/2+1,e,ss,se,val),upd_lz(2*i,s,(s+e)/2);
        else if((s+e)/2>=se) upd(2*i,s,(s+e)/2,ss,se,val),upd_lz(2*i+1,(s+e)/2+1,e);
        else upd(2*i,s,(s+e)/2,ss,se,val),upd(2*i+1,(s+e)/2+1,e,ss,se,val);
        id[i]=st[2*i]>st[2*i+1]?id[2*i]:id[2*i+1];
        st[i]=max(st[2*i],st[2*i+1]);
    }
}

pii qu(int i,int s,int e,int ss,int se){
    upd_lz(i,s,e);
    if(s>=ss&&e<=se) return make_pair(st[i],id[i]);
    else if((s+e)/2<ss) return qu(2*i+1,(s+e)/2+1,e,ss,se);
    else if((s+e)/2>=se) return qu(2*i,s,(s+e)/2,ss,se);
    else{
        pii l=qu(2*i,s,(s+e)/2,ss,se),r=qu(2*i+1,(s+e)/2+1,e,ss,se);
        return make_pair(max(l.first,r.first),l.first>r.first?l.second:r.second);
    }
}
map<int,int> mp;
pii evt[MN], go;
int main(){
    for(scanf("%d",&n),i=1;i<=n;i++){
        scanf("%d%d%d",&arr[i].l,&arr[i].v,&arr[i].r);
        mp[arr[i].v]=0; arr[i].id=i;
    }
    sort(arr+1,arr+n+1,[](idk i,idk j){return i.v<j.v;});
    build(1,1,n);
    i=0; auto it=mp.begin();
    for(;it!=mp.end();it++)
        it->second=++i;
    for(i=1;i<=n;i++){
        auto it=mp.lower_bound(arr[i].l);
        arr[i].l=it->second;
        it=mp.upper_bound(arr[i].r); it--;
        arr[i].r=it->second;
        arr[i].v=mp[arr[i].v];
        evt[i]={arr[i].l,i};
    }
    sort(evt+1,evt+n+1,[](pii i,pii j){return i.first<j.first;});
    for(i=j=1;i<=n;i++){
        while(j<=n&&evt[j].first<=arr[i].v){
            int id=evt[j].second;
            upd(1,1,n,arr[id].v,arr[id].r,1);
            j++;
        }
        pii c=qu(1,1,n,arr[i].v,arr[i].r);
        if(c.first>ans){
            ans=c.first;
            go={arr[i].v,c.second};
        }
        upd(1,1,n,arr[i].v,arr[i].r,-1);
    }
    printf("%d\n",ans);
    for(i=1;i<=n;i++){
        if(arr[i].l<=go.first&&arr[i].r>=go.second&&arr[i].v>=go.first&&arr[i].v<=go.second){
            printf("%d ",arr[i].id);
        }
    }
    pr();
    return 0;
}