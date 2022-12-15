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

const int MN = 1e5+5;
ll T, n, x, i, arr[MN], ans;
map<ll,ll> cnt;

int main(){
    for(scanf("%lld",&T);T;T--){
        scanf("%lld%lld",&n,&x);
        getchar(); cnt.clear();
        for(i=1;i<=n;i++){
            char c = getchar();
            if(c=='0') arr[i]=arr[i-1]+1;
            else arr[i]=arr[i-1]-1;
            cnt[arr[i]]++;
        }
        ans = 0;
        if(x==0) ans++;
        if(arr[n]==0){
            if(cnt.count(x)) printf("-1\n");
            else printf("0\n");
        }
        else{
            ll lo = 0, hi = 1e9;
            while(lo<hi){
                ll m = (lo+hi)/2;
                if(arr[n]>0){
                    if(m*arr[n]+2*n<=x) lo=m+1;
                    else hi=m;
                }
                else{
                    if(m*arr[n]-2*n>=x) lo=m+1;
                    else hi=m;
                }
            }
            lo=max(0LL,lo-1);
            x -= lo*arr[n];
            while(1){
                ans += cnt[x];
                x -= arr[n];
                if(arr[n]>0&&x<-2*n) break;
                if(arr[n]<0&&x>2*n) break;
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}