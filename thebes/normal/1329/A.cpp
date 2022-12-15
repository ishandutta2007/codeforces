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
int n, m, i, ans[MN]; ll sm; pii arr[MN];

int main(){
    for(scanf("%d%d",&n,&m),i=1;i<=m;i++){
        scanf("%d",&arr[i].first);
        arr[i].second=i;
        sm += arr[i].first;
    }
    if(sm<n) printf("-1\n");
    else if(arr[m].first+m-1>n) printf("-1\n");
    else{
        int a=0, b=0;
        for(i=1;i<=m;i++){
            ans[i]=i;
            if(ans[i]+arr[i].first-1>n){
                printf("-1\n");
                return 0;
            }
        }
        int lst=n+1;
        for(i=m;i>=1;i--){
            if(ans[i]+arr[i].first<lst){
                ans[i]+=lst-ans[i]-arr[i].first;
            }
            lst=ans[i];
        }
        if(ans[1]!=1){
            printf("-1\n");
            return 0;
        }
        for(i=1;i<=m;i++) printf("%d ",ans[i]);
        printf("\n");
    }
    return 0;
}