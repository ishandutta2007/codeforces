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

const int MN = 2002;
int n, m, i, j, k, h[MN], c[MN], p[2*MN], pre[2][2*MN][MN], dp[2][2*MN][MN], cnt[MN*2], lim[2*MN];

int main(){
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&h[i]);
        cnt[h[i]]++;
    }
    for(i=1;i<=n+m;i++){
        lim[i]=cnt[i]+(lim[i-1]/2);
    }
    for(i=1;i<=n;i++){
        scanf("%d",&c[i]);
    }
    for(i=1;i<=n+m;i++)
        scanf("%d",&p[i]);
    for(i=1;i<=n+m;i++){
        for(j=0;j<=n;j++){
            dp[0][i][j]=dp[1][i][j]=-1<<30;
            pre[0][i][j]=pre[1][i][j]=-1<<30;
        }
    }
    for(k=1;k<=n;k++){
        for(j=n+m;j>=1;j--){
            for(i=0;i<=lim[j];i++)
                dp[k&1][j][i]=dp[(k+1)&1][j][i];
            for(i=0;2*i<=lim[j];i++){
                pre[k&1][j][2*i]=dp[k&1][j+1][i]+2*i*p[j];
                pre[k&1][j][2*i+1]=pre[k&1][j][2*i]+p[j];
            }
            for(i=0;i<=lim[j];i++)
                dp[k&1][j][i]=max(dp[k&1][j][i],pre[k&1][j][i]);
            if(j==h[k]){
                for(i=1;i<=lim[j];i++){
                    dp[k&1][j][i-1]=max(dp[k&1][j][i-1],dp[k&1][j][i]-c[k]);
                }
            }
        }
    }
    printf("%d\n",dp[n&1][1][0]);
    return 0;
}