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

const int MN = 4e5+12;
string s; ll n, i, pre, ans=-1, pog, bit[MN], mn, kek;
void upd(ll p,ll v){for(;p<=2*n+10;p+=p&-p)bit[p]=min(bit[p],v);}
ll qu(ll p){ll r=1<<30;for(;p;p-=p&-p)r=min(r,bit[p]); return r;}

int main(){
    cin >> s; n = s.size();
    memset(bit,0x3f,sizeof(bit));
    for(auto c : s){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U') kek--;
        else kek+=2;
        mn = min(mn, kek);
    }
    i=1;
    upd(0-mn+1,0);
    for(auto c : s){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U') pre--;
        else pre+=2;
        ll heh = qu(pre-mn+1);
        if(i-heh>ans){
            ans = i-heh;
            pog = 1;
        }
        else if(i-heh==ans) pog++;
        upd(pre-mn+1,i);
        i++;
    }
    if(ans==-1) printf("No solution\n");
    else printf("%lld %lld\n",ans,pog);
    return 0;
}