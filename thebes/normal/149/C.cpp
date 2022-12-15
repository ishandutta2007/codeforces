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

const int MN = 1e5+5;
pii arr[MN];
int n, i;
vi a, b;

int main(){
    for(scanf("%d",&n),i=1;i<=n;i++){
        scanf("%d",&arr[i].first);
        arr[i].second = i;
    }
    sort(arr+1,arr+n+1,[](pii i,pii j){return i.first>j.first;});
    for(i=1;i<n;i++){
        if(i%2) a.pb(arr[i].second);
        else b.pb(arr[i].second);
    }
    if(n%2) b.pb(arr[n].second);
    else b.pb(arr[n].second);
    printf("%d\n",a.size());
    for(auto v : a) printf("%d ",v);
    printf("\n%d\n",b.size());
    for(auto v : b) printf("%d ",v);
    printf("\n");
    return 0;
}