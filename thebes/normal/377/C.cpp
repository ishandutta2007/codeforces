#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
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

const int MN = 105, MM = 22;
int n, m, i, j, k, a[MN], dp[2][1<<21], ok[2][1<<21], op[MM], id[MM];
inline void stmax(int &x,int y,int id){x=id==1?max(x,y):min(x,y);}

int main(){
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    scanf("%d",&m);
    for(i=0;i<m;i++)
        a[i+1]=a[n-m+1+i];
    for(i=1;i<=m;i++){
        char ch;
        scanf(" %c%d",&ch,&id[i]);
        op[i]=ch=='p';
    }
    ok[(m+1)&1][0]=1;
    for(i=m;i>=1;i--){
        int coef=id[i]==1?1:-1;
        for(j=0;j<(1<<m);j++){
            ok[i&1][j]=0;
            for(int k=0;k<m;k++){
                if(((1<<k)&j)&&ok[(i+1)&1][j^(1<<k)]){
                    if(!ok[i&1][j]){
                        ok[i&1][j]=1;
                        dp[i&1][j]=dp[(i+1)&1][j^(1<<k)]+(op[i]==1?coef*a[k+1]:0);
                    }
                    else stmax(dp[i&1][j],dp[(i+1)&1][j^(1<<k)]+(op[i]==1?coef*a[k+1]:0),id[i]);
                }
            }
        }
    }
    printf("%d\n",dp[1][(1<<m)-1]);
    return 0;
}