#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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

const int MN = 2005, MM = 16000;
const double eps = 1e-8;
int N, Q, i, j, x, ans[MN]; pii qu[MN]; 
double dp[2][MN];

int main(){ // EAT CHEESE
    scanf("%d%d",&N,&Q);
    for(i=1;i<=Q;i++){
        scanf("%d",&qu[i].first);
        qu[i].second=i;
    }
    sort(qu+1,qu+Q+1,[](pii i,pii j){return i.first<j.first;});
    dp[0][N]=1; int cur = 1;
    for(i=0;i<MM;i++){
        for(j=1;j<=N;j++)
            dp[(i+1)&1][j]=0;
        dp[(i+1)&1][0]=dp[i&1][0];
        for(j=N;j>0;j--){
            dp[(i+1)&1][j]+=(N-j)/(double)N*dp[i&1][j];
            dp[(i+1)&1][j-1]+=j/(double)N*dp[i&1][j];
        }
        while(cur<=Q&&2000*dp[(i+1)&1][0]+eps>=(qu[cur].first)){
            ans[qu[cur].second]=i+1;
            cur++;
        }
    }
    for(i=1;i<=Q;i++)
        printf("%d\n",ans[i]);
    return 0;
}