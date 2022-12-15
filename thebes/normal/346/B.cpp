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
#define F first
#define S second

const int MN = 105;
int dp[MN][MN][MN], i, j, k, n, m, l, ans, f[MN];
struct idk{int x, y, w;}ptr[MN][MN][MN], sna;
string s, t, v;

int main(){
    cin >> s >> t >> v;
    n = s.size(), m = t.size(), l = v.size();
    s.insert(s.begin(),' ');
    t.insert(t.begin(),' ');
    f[0]=0;
    for(i=1,j=0;i<l;i++){
        while(j>0&&v[i]!=v[j])
            j=f[j-1];
        if(j>=0&&v[i]==v[j]) f[i]=++j;
        else f[i]=j++;
    }
    for(i=0;i<=n;i++){
        for(j=0;j<=m;j++){
            for(k=1;k<=l;k++)
                dp[i][j][k]=-1<<30;
            if(i&&j) dp[i][j][0]=-1<<30;
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            for(k=0;k<=l;k++){
                if(dp[i-1][j][k]>dp[i][j][k]){
                    dp[i][j][k]=dp[i-1][j][k];
                    ptr[i][j][k]={i-1,j,k};
                }
                if(dp[i][j-1][k]>dp[i][j][k]){
                    dp[i][j][k]=dp[i][j-1][k];
                    ptr[i][j][k]={i,j-1,k};
                }
                if(s[i]==t[j]){
                    if(k==l) continue;
                    int t = k;
                    while(s[i]!=v[t]&&t>0)
                        t=f[t-1];
                    if(s[i]==v[t]){
                        if(dp[i-1][j-1][k]+1>dp[i][j][t+1]){
                            dp[i][j][t+1]=dp[i-1][j-1][k]+1;
                            ptr[i][j][t+1]={i-1,j-1,k};
                        }
                    }
                    else{
                        if(dp[i-1][j-1][k]+1>dp[i][j][0]){
                            dp[i][j][0]=dp[i-1][j-1][k]+1;
                            ptr[i][j][0]={i-1,j-1,k};
                        }
                    }
                }
            }
            for(k=0;k<l;k++){
                if(dp[i][j][k]>ans){
                    ans=dp[i][j][k];
                    sna={i,j,k};
                }
            }
            /*for(k=0;k<=l;k++){
                pr(">",i,j,k,dp[i][j][k]);
            }*/
        }
    }
    if(ans==0) printf("0\n");
    else{
        int x=sna.x, y=sna.y, w=sna.w;
        string res;
        while(x&&y){
            int px=ptr[x][y][w].x;
            int py=ptr[x][y][w].y;
            int pw=ptr[x][y][w].w;
            if(dp[px][py][pw]<dp[x][y][w]) res+=s[x];
            x = px, y = py, w = pw;
        }
        reverse(res.begin(),res.end());
        printf("%s\n",res.c_str());
    }
    return 0;
}