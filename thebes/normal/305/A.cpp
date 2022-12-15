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

string s;
map<int,int> ok; vi heh, sna;
int n, i, j, x, ans, ree; string arr[105];

int main(){
    scanf("%d",&n);
    fox(i,1,n){
        cin >> s; arr[i]=s;
        int m = 0;
        for(j=0;j<s.size();j++){
            m*=2;
            if(s[j]!='0') m++;
        }
        if(!m){
            ree++;
        }
        else ok[m]=i;
    }
    for(auto v : ok) heh.pb(v.first);
    for(int m=0;m<(1<<ok.size());m++){
        int hm = 0, f = 0, cnt = 0;
        vi wew;
        for(i=0;i<heh.size();i++){
            if((1<<i)&m){
                cnt ++;
                if(hm&heh[i]){
                    f = 1;
                    break;
                }
                hm |= heh[i];
                wew.pb(ok[heh[i]]);
            }
        }
        if(!f){
            if(cnt>ans){
                ans = cnt;
                sna = wew;
            }
        }
    }
    printf("%d\n",ans+ree);
    for(auto v : sna) printf("%s ",arr[v].c_str());
    for(;ree;ree--) printf("0 ");
    printf("\n");
    return 0;
}