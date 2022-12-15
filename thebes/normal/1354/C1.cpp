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
#define F first
#define S second

const ld PI = (ld)acos((ld)-1);
pdd vec, dlt;
int T, N, i, j;

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        vec = {0,0};
        ld ang = PI-(2*N-2)*PI/(ld)(2*N);
        ld cur = 0;
        ld ans;
        if(N&1){
            dlt = {0.5*cos(cur),0.5*sin(cur)};
            vec.F += dlt.F, vec.S += dlt.S;
            cur += ang;
            for(i=1;i<=(N-3)/2;i++){
                dlt = {cos(cur),sin(cur)};
                vec.F += dlt.F, vec.S += dlt.S;
                cur += ang;
            }
            dlt = {cos(cur),sin(cur)};
            vec.F += dlt.F, vec.S += dlt.S;
            ans = 2*max(abs(vec.F),abs(vec.S));
        }
        else{
            dlt = {0.5*cos(cur),0.5*sin(cur)};
            vec.F += dlt.F, vec.S += dlt.S;
            cur += ang;
            for(i=1;i<=(N-2)/2;i++){
                dlt = {cos(cur),sin(cur)};
                vec.F += dlt.F, vec.S += dlt.S;
                cur += ang;
            }
            dlt = {0.5*cos(cur),0.5*sin(cur)};
            vec.F += dlt.F, vec.S += dlt.S;
            ans = 2*max(abs(vec.F),abs(vec.S));
        }
        printf("%.7Lf\n",ans);
    }
    return 0;
}