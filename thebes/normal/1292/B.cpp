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

const ll MN = 105, MM = 1e16;
unsigned long long x, y, ax, ay, bx, by, sx, sy, t, ans;
vector<pair<unsigned long long,unsigned long long >> pnt;
unsigned long long abs(unsigned long long x,unsigned long long y){return x>y?x-y:y-x;}
int main(){
    scanf("%llu%llu%llu%llu%llu%llu",&x,&y,&ax,&ay,&bx,&by);
    scanf("%llu%llu%llu",&sx,&sy,&t);
    pnt.pb({x,y});
    while(1){
        if(x*(ax-1)+bx>MM&&x>2*MM) break;
        if(y*(ay-1)+by>MM&&y>2*MM) break;
        x=x*ax+bx;
        y=y*ay+by;
        pnt.pb({x,y});
    }
    for(unsigned long long  i=0;i<(unsigned long long)pnt.size();i++){
        for(unsigned long long j=i;j<(unsigned long long)pnt.size();j++){
            unsigned long long d = abs(pnt[i].first,pnt[j].first)+abs(pnt[i].second,pnt[j].second);
            if(d>t) continue;
            d += min(abs(pnt[i].first,sx)+abs(pnt[i].second,sy),abs(pnt[j].first,sx)+abs(pnt[j].second,sy));
            if(d<=t) ans=max(j-i+1,ans);
        }
    }
    printf("%llu\n",ans);
    return 0;
}