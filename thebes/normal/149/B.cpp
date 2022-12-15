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
#define fox(i,x,y) for(int i=(x);i<=(y);i++)
#define foxr(i,x,y) for(int i=(x);i>=(y);i--)

string a, b;
int n, i, ok[70], okk[70], mx, mxx;
int idx(char ch){
    if(ch>='0'&&ch<='9') return ch-'0';
    else return ch-'A'+10;
}
int eval(int b,string s){
    int c = 1, r = 0;
    for(int i=s.size()-1;i>=0;i--){
        r += c*idx(s[i]);
        c *= b;
        if(c>60) c = 60;
    }
    return r;
}
int main(){
    cin >> a;
    while(a.back()!=':'){
        b.insert(b.begin(),a.back());
        a.pop_back();
    }
    a.pop_back();
    for(auto v : a) mx=max(mx,idx(v));
    for(i=mx+1;i<70;i++) if(eval(i,a)<24) ok[i]=1;
    mx = 0;
    for(auto v : b) mx=max(mx,idx(v));
    for(i=1;i<=mx;i++) ok[i]=0;
    for(i=mx+1;i<70;i++) if(eval(i,b)>=60) ok[i]=0;
    if(ok[69]) printf("-1\n");
    else{
        int f = 0;
        for(i=1;i<70;i++) if(ok[i]) printf("%d ",i), f=1;
        if(!f) printf("0");
        printf("\n");
    }
    return 0;
}