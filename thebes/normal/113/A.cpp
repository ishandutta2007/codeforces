#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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

vector<string> tok;
int flag, i, idx, fnd, c1, c2;
string get(string s,int x){
    if(s.size()<x) return "";
    else{
        string t="";
        for(int i=x-1;i>=0;i--)
            t += s[s.size()-i-1];
        return t;
    }
}
int main(){
    string s, t;
    getline(cin,s);
    for(i=0;i<s.size();i++){
        if(s[i]==' '){
            tok.pb(t);
            t = "";
        }
        else t += s[i];
    }
    tok.pb(t);
    for(auto v : tok){
        if(get(v,4)=="etra"||get(v,3)=="etr"){
            if(get(v,3)=="etr") c2++;
            else c1++;
            if(fnd) flag=1;
            else fnd=1;
        }
        else if(get(v,4)=="lios"||get(v,5)=="liala"){
            if(get(v,4)=="lios") c2++;
            else c1++;
            if(fnd) flag=1;
        }
        else if(get(v,6)=="initis"||get(v,6)=="inites"){
            if(get(v,6)=="initis") c2++;
            else c1++;
            if(!fnd) flag=1;
        }
        else flag=2;
    }
    if(tok.size()==1){
        printf("%s\n",flag==2?"NO":"YES");
        return 0;
    }
    printf("%s\n",(!flag&&fnd&&(!c1||!c2))?"YES":"NO");
    return 0;
}