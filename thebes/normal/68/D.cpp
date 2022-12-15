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

const int MN = 33;
int h, q, i, x, y, f; double ans;
string s; map<int,int> sm, val;

int main(){
    scanf("%d%d",&h,&q);
    for(;q;q--){
        cin >> s;
        if(s=="add"){
            scanf("%d%d",&x,&y);
            val[x] += y;
            while(x){
                sm[x] += y;
                x >>= 1;
            }
            f=1;
        }
        else{
            if(f){
                x = 1; int mx=0; double prob=1; ans=0;
                for(i=0;i<h;i++){
                    int lsum=val[x]+sm[x<<1], rsum=val[x]+sm[(x<<1)|1];
                    if(lsum>rsum){
                        ans+=prob/2.0*max(mx,lsum);
                        mx=max(mx,rsum);
                        x=(x<<1);
                    }
                    else{
                        ans+=prob/2.0*max(mx,rsum);
                        mx=max(mx,lsum);
                        x=(x<<1)|1;
                    }
                    prob/=2;
                }
                ans+=prob*max(mx,val[x]);
                f=0;
            }
            printf("%.6lf\n",ans);

        }
    }
    return 0;
}