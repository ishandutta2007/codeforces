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
    template<class T1,class... T2>
    void print(const T1&t1,const T2&...t2){__(t1);if(sizeof...(t2))__(" "),print(t2...);else __("\n");}
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

int main(){
    vi p{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
    int c=0;
    for(auto v : p){
        printf("%d\n",v); fflush(stdout);
        string s; cin >> s; if(s=="yes") c++;
        if(s=="yes"&&v*v<=100){
            printf("%d\n",v*v); fflush(stdout);
            cin >> s; if(s=="yes") c++;
        }
    }
    if(c>=2) printf("composite\n");
    else printf("prime\n");
    fflush(stdout);
    return 0;
}