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

const int MN = 1e5+5;
struct nd{int mn, delta, low;}st[3*MN];
int n, i, t, x, p, elem[MN];

void upd(int i,int s,int e,int ind,int val){
    if(s!=e){
        if((s+e)/2<ind) upd(2*i+1,(s+e)/2+1,e,ind,val);
        else upd(2*i,s,(s+e)/2,ind,val);
        st[i].mn = min(st[2*i].mn, st[2*i+1].mn+st[2*i].delta);
        st[i].low = max(st[2*i].low, st[2*i+1].low-st[2*i].delta);
        st[i].delta = st[2*i].delta+st[2*i+1].delta;
    }
    else{
        st[i].delta = val;
        st[i].low = -val;
        st[i].mn = val;
    }
}

int qu(int i,int s,int e,int res){
    if(s==e) return s;
    if(st[2*i].delta+st[2*i+1].mn>res) return qu(2*i,s,(s+e)/2,res);
    else return qu(2*i+1,(s+e)/2+1,e,res-st[2*i].delta);
}

int main(){
    for(scanf("%d",&n),i=1;i<=n;i++){
        scanf("%d%d",&p,&t);
        if(t==0) upd(1,0,n,p,-1);
        else{
            scanf("%d",&elem[p]);
            upd(1,0,n,p,1);
        }
        int res = max(0,st[1].low)+st[1].delta;
        if(!res) printf("-1\n");
        else printf("%d\n",elem[qu(1,0,n,res-1-max(0,st[1].low))+1]);
    }
    return 0;

}