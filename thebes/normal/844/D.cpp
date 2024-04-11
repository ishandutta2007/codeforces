#include <bits/stdc++.h>
using namespace std;

namespace debug{
    void __(short x){cout<<x;}
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

mt19937 mt(time(0));
int rng(int l,int r){return (mt()%(r-l+1))+l;}
int n, s, x, i, vs[50004], q; vector<pii> a;
pii qu(int x){
    printf("? %d\n",x); fflush(stdout);
    pii r; cin >> r.first>>r.second; return r;
}

int main(){
    scanf("%d%d%d",&n,&s,&x);
    if(n<=1999){
        int ans = 1<<30;
        for(i=1;i<=n;i++){
            pii c = qu(i);
            if(c.first>=x) ans=min(ans,c.first);
        }
        printf("! %d\n",ans==1<<30?-1:ans);
        fflush(stdout);
    }
    else{
        q = 998; a.pb(qu(s)); vs[s]=1;
        while(q--){
            int y = rng(1,n);
            while(vs[y]) y=rng(1,n);
            a.pb(qu(y));
        }
        sort(a.begin(),a.end());
        for(i=a.size()-1;i>=0;i--)
            if(a[i].first<x) break;
        if(i==-1){
            printf("! %d\n",a[0].first);
            fflush(stdout);
            return 0;
        }
        else if(i==a.size()){
            printf("! -1\n");
            fflush(stdout);
            return 0;
        }
        pii cur = a[i]; int ans = -1;
        while(1){
            if(cur.first>=x){ans=cur.first; break;}
            if(cur.second==-1) break;
            else cur = qu(cur.second);
        }
        printf("! %d\n",ans);
        fflush(stdout);
    }
    return 0;
}