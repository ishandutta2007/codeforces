#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
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

const int MN = 88;
vector<pii> c[MN][MN]; pii aa[MN][MN][6]; int sz[MN][MN];
int n, k, i, ii[7], st[7], adj[MN][MN], j, l, f; ll ans = 1LL<<60;

int main(){
    scanf("%d%d",&n,&k);
    k = (k-2)/2;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++) scanf("%d",&adj[i][j]);
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            for(ll l=1;l<=n;l++){
                if(l!=i&&l!=j) c[i][j].pb({adj[i][l]+adj[l][j],l});
            }
            sort(c[i][j].begin(),c[i][j].end(),[](pll i,pll j){return i.first<j.first;});
            while(c[i][j].size()>6) c[i][j].erase(c[i][j].end()-1);
            //sort(c[i][j].begin(),c[i][j].end(),[](pll i,pll j){return i.second<j.second;});
            sz[i][j]=c[i][j].size();
            for(l=0;l<sz[i][j];l++) aa[i][j][l]=c[i][j][l];
        }
    }
    if(!k){
        printf("%d\n",c[1][1][0].first);
        return 0;
    }
    ll T = pow(n,k), rem, x, tmp;
    for(ll msk=0;msk<=T;msk++){
        rem = msk;
        for(i=0;i<k;i++){
            x = rem/n;
            st[i+1]=rem-x*n+1;
            rem = x;
        }
        st[k+1]=st[0]=1;
        tmp = 0;
        for(i=0;i<=k;i++){
            for(l=0;l<sz[st[i]][st[i+1]];l++){
                f = 0;
                for(j=0;j<=k+1;j++) if(st[j]==aa[st[i]][st[i+1]][l].second){f=1; break;}
                if(!f){
                    tmp += aa[st[i]][st[i+1]][l].first;
                    break;
                }
            }
            if(tmp>=ans) break;
        }
        ans = min(ans, tmp);
    }
    printf("%lld\n",ans);
    return 0;
}