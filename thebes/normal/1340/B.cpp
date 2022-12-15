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

const int MN = 2002;
int n, k, i, j, dp[MN][MN], nxt[MN][MN], msk[MN], val[1<<7];
int trans[1<<7][1<<7]; vi dig;
inline int convert(string s){
    int bin=0;
    for(int j=0;j<s.size();j++){
        if(s[j]=='1') bin|=(1<<j);
    }
    return bin;
}
int main(){
    for(scanf("%d%d",&n,&k),i=1;i<=n;i++){
        string s; cin >> s;
        msk[i]=convert(s);
    }
    dig.pb(convert("1110111"));
    dig.pb(convert("0010010"));
    dig.pb(convert("1011101"));
    dig.pb(convert("1011011"));
    dig.pb(convert("0111010"));
    dig.pb(convert("1101011"));
    dig.pb(convert("1101111"));
    dig.pb(convert("1010010"));
    dig.pb(convert("1111111"));
    dig.pb(convert("1111011"));
    for(i=0;i<(1<<7);i++){
        for(j=0;j<(1<<7);j++){
            if((i&j)==i){
                int res=(i^j), cnt=0;
                for(int k=0;k<7;k++){
                    if((1<<k)&res) cnt++;
                }
                trans[i][j]=cnt;
            }
            else trans[i][j]=-1;
        }
    }
    dp[n+1][0]=1;
    for(i=n;i>=1;i--){
        for(int l=0;l<dig.size();l++){
            if(trans[msk[i]][dig[l]]==-1) continue;
            int dl = trans[msk[i]][dig[l]];
            for(j=dl;j<=k;j++){
                if(dp[i+1][j-dl]) dp[i][j]=1;
            }
        }
    }
    if(dp[1][k]==0) printf("-1\n");
    else{
        j=k;
        for(i=1;i<=n;i++){
            for(int l=dig.size()-1;l>=0;l--){
                if(trans[msk[i]][dig[l]]==-1) continue;
                int dl = trans[msk[i]][dig[l]];
                if(dp[i+1][j-dl]){
                    printf("%d",l);
                    j-=dl;
                    break;
                }
            }
        }
        pr();
    }
    return 0;
}