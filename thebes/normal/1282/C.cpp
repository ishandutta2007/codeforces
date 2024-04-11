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
#define foxr(i,x,y) for(int i=(x);i>=(y);i--)

const ll MN = 2e5+5;
struct p{ll t, a;}arr[MN];
ll n, m, T, a, b, i, ans, x, sm, A, B;

int main(){
    scanf("%lld",&m);
    fox(q,1,m){
        scanf("%lld%lld%lld%lld",&n,&T,&a,&b);
        A = B = 0;
        fox(i,1,n){
            scanf("%lld",&x);
            if(!x) arr[i].a = a, A++;
            else arr[i].a = b, B++;
        }
        fox(i,1,n){
            scanf("%lld",&arr[i].t);
        }
        sort(arr+1,arr+n+1,[](p i,p j){return i.t<j.t;});
        ans = 0; sm = 0;
        fox(i,0,n){
            if(i&&arr[i].a==a) A--;
            else if(i) B--;
            sm += arr[i].a;
            if(sm>T) break;
            ll rem;
            if(i==n) rem = T-sm;
            else rem = min(T,arr[i+1].t-1)-sm;
            if(rem<0) continue;
            ll ok1 = rem/a;
            if(ok1>=A){
                ok1 = min(ok1, A);
                ll ok2 = (rem-a*ok1)/b;
                ok2 = min(ok2, B);
                ans = max(ans, i+ok1+ok2);
            }
            else ans = max(ans, i+ok1);
        }
        printf("%lld\n",ans);
    }
    return 0;
}