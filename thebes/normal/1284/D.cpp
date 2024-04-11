#include <bits/stdc++.h>
using namespace std;

namespace debug{
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
    template<class P1,class P2>
    void __(const pair<P1,P2>&x){__("("),__(x.first),__(", "),__(x.second),__(")");}
    template<class T>
    void __(const vector<T>&x){__("{");bool _ffs=0;for(const auto&v:x)__(_ffs?", ":""),__(v),_ffs=1;__("}");}
    template<class T>
    void __(const set<T>&x){__("{");bool _ffs=0;for(const auto&v:x)__(_ffs?", ":""),__(v),_ffs=1;__("}");}
    template<class T,class T2>
    void __(const map<T,T2>&x){__("{");bool _ffs=0;for(const auto&v:x)__(_ffs?", ":""),__(make_pair(v.first,v.second)),_ffs=1;__("}");}
    void screm(){__("\n");}
    template<class T1,class... T2>
    void screm(const T1&t1,const T2&...t2){__(t1);if(sizeof...(t2))__(" | "),screm(t2...);else __("\n");}
    void pr(){__("\n");}
    template<class T1,class... T2>
    void pr(const T1&t1,const T2&...t2){__(t1);if(sizeof...(t2))__(" "),pr(t2...);else __("\n");}
}

using namespace debug;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<ld,ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back
#define fox(i,x,y) for(int i=(x);i<=(y);i++)
#define foxr(i,x,y) for(int i=(y);i>=(x);i--)

const int MN = 1e5+5;
int n, i, ord[MN], flg;
pii a[MN], b[MN], st[3*MN];

void upd(int i,int s,int e,int idx,int val,int aa){
    if(s!=e){
        if((s+e)/2<idx) upd(2*i+1,(s+e)/2+1,e,idx,val,aa);
        else upd(2*i,s,(s+e)/2,idx,val,aa);
        st[i].first=max(st[2*i].first,st[2*i+1].first);
        st[i].second=min(st[2*i].second,st[2*i+1].second);
    }
    else{
        if(aa) st[i].first=max(st[i].first,val);
        else st[i].second=min(st[i].second,val);
    }
}

pii qu(int i,int s,int e,int ss,int se){
    if(ss>se) return make_pair(0,1<<30);
    if(s>=ss&&e<=se) return st[i];
    else if((s+e)/2<ss) return qu(2*i+1,(s+e)/2+1,e,ss,se);
    else if((s+e)/2>=se) return qu(2*i,s,(s+e)/2,ss,se);
    else{
        pii a=qu(2*i,s,(s+e)/2,ss,se),b=qu(2*i+1,(s+e)/2+1,e,ss,se);
        return make_pair(max(a.first,b.first),min(a.second,b.second));
    }
}

void solve(){
    memset(st,0,sizeof(st));
    fox(i,1,3*MN-1) st[i].second=1<<30;
    fox(i,1,n) ord[i]=i;
    sort(ord+1,ord+n+1,[](int i,int j){return a[i].first<a[j].first;});
    fox(i,1,n) upd(1,1,n,i,b[ord[i]].first,1),upd(1,1,n,i,b[ord[i]].second,0);
    foxr(i,1,n){
        ll lo=i+1, hi=n+1;
        while(lo<hi){
            ll mi = (lo+hi)/2;
            if(a[ord[mi]].first<=a[ord[i]].second) lo=mi+1;
            else hi=mi;
        }
        lo--;
        if(lo>i){
            pii z = qu(1,1,n,i+1,lo);
            if(z.first>b[ord[i]].second||z.second<b[ord[i]].first){
                flg = 1;
                return;
            }
        }
    }
}

int main(){
    scanf("%d",&n);
    fox(i,1,n){
        scanf("%d%d%d%d",&a[i].first,&a[i].second,&b[i].first,&b[i].second);
    }
    solve();
    if(flg){
        printf("NO\n");
        return 0;
    }
    fox(i,1,n) swap(a[i],b[i]);
    solve();
    if(flg){
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    return 0;
}