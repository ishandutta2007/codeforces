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

const ll MN = 2505;
const long double PI = 4*atan((long double)1);
long double ang[MN];
ll n, i, j, k, sna, ans; pll pnt[MN];
vector<long double> arr;

ll C(ll n,ll k){
    if(n<k) return 0;
    ll ret = 1;
    fox(i,n-k+1,n) ret *= i;
    fox(i,1,k) ret /= i;
    return ret;
}

int main(){
    scanf("%lld",&n); sna = C(n-1,4);
    fox(i,1,n) scanf("%lld%lld",&pnt[i].first,&pnt[i].second);
    fox(j,1,n){
        arr.clear();
        fox(i,1,n){
            if(i!=j)
                arr.pb(atan2(pnt[i].second-pnt[j].second,pnt[i].first-pnt[j].first));
        }
        sort(arr.begin(),arr.end());
        for(i=0;i<n-1;i++) arr.pb(arr[i]);
        ans += sna;
        for(i=0,k=1;i<n-1;i++){
            while(k<i+n-1){
                long double aa = arr[k]-arr[i];
                if(aa<0) aa+=2*PI;
                if(aa<PI) k++;
                else break;
            }
            ll a = k-i-1;
            ans -= C(a,3);
        }
    }
    printf("%lld\n",ans);
    return 0;
}