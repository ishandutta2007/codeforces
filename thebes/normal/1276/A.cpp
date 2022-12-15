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

const int MM = 2e6+6;
int t, n, i, j, x, y, tp, st[MM];
string s; vi ans;

int main(){
    scanf("%d",&t);
    fox(q,1,t){
        cin >> s; tp = -1; ans.clear();
        for(i=0;i<s.size();i++){
            if(tp>=1){
                if(s[i]=='o'&&s[st[tp]]=='w'&&s[st[tp-1]]=='t'){
                    if(i+1!=s.size()&&s[i+1]=='o'){
                        ans.pb(st[tp]);
                        st[tp]=i;
                    }
                    else{
                        ans.pb(i);
                    }
                }
                else if(s[i]=='e'&&s[st[tp]]=='n'&&s[st[tp-1]]=='o'){
                    ans.pb(st[tp]);
                    st[tp]=i;
                }
                else st[++tp]=i;
            }
            else st[++tp]=i;
        }
        printf("%d\n",ans.size());
        for(auto v : ans) printf("%d ",v+1);
        printf("\n");
    }
    return 0;
}