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

const int MN = 1e4+5;
int n, m, i, j, nxt[MN], cur;
short dp[MN][MN];
string s, t; stack<pii> pre;

int main(){
    cin >> s >> t;
    n = (int)s.size();
    m = (int)t.size();
    pre.push({n,0});
    memset(nxt,-1,sizeof(nxt));
    for(i=n-1;i>=0;i--){
        if(s[i]=='.') cur++;
        else cur--;
        if(cur>pre.top().S){
            pre.push({i,cur});
            continue;
        }
        pre.pop();
        if(pre.size()){
            nxt[i]=pre.top().F;
            pre.pop();
        }
        pre.push({i,cur});
    }
    for(i=0;i<=n;i++){
        for(j=0;j<=m;j++){
            dp[i][j]=30000;
        }
    }
    dp[0][0]=0;
    for(i=0;i<n;i++){
        for(j=0;j<=m;j++){
            if(j&&s[i]=='.')
                dp[i+1][j-1]=min(dp[i+1][j-1],dp[i][j]);
            if(j+1<=m&&s[i]==t[j])
                dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]);
            if(~nxt[i])
                dp[nxt[i]][j]=min(dp[nxt[i]][j],dp[i][j]);
            dp[i+1][j]=min(dp[i+1][j],(short)(dp[i][j]+1));
        }
    }
    printf("%d\n",dp[n][m]);
    return 0;
}