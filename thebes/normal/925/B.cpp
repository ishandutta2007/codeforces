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
typedef pair<double,double> pdd;
typedef pair<ld,ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back
#define fox(i,x,y) for(int i=(x);i<=(y);i++)
#define foxr(i,x,y) for(int i=(y);i>=(x);i--)

const int MN = 3e5+5;
int n, a, b, i, j, p, ok[MN], f; pii arr[MN];
vi c, d;

void go(int id){
    p = -1;
    for(i=1;i<=n;i++){
        if(1LL*arr[i].first*i>=a){
            p = i;
            break;
        }
    }
    if(p!=-1){
        for(i=p+1;i<=n;i++){
            if(1LL*arr[i].first*(i-p)>=b){
                f = id;
                c.clear();
                d.clear();
                for(int j=1;j<=p;j++) c.pb(arr[j].second);
                for(int j=p+1;j<=i;j++) d.pb(arr[j].second);
                return;
            }
        }
    }
}

int main(){
    scanf("%d%d%d",&n,&a,&b);
    for(i=1;i<=n;i++){
        scanf("%d",&arr[i].first);
        arr[i].second = i;
    }
    sort(arr+1,arr+n+1,[](pii i,pii j){return i.first>j.first;});
    go(1);
    swap(a,b);
    go(2);
    if(f){
        printf("Yes\n");
        if(f==2) swap(c,d);
        printf("%d %d\n",c.size(),d.size());
        for(auto v : c) printf("%d ",v);
        printf("\n");
        for(auto v : d) printf("%d ",v);
        printf("\n");
    }
    else printf("No\n");
    return 0;
}