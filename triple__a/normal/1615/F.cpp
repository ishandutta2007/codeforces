// #pragma comment(linker, "/STACK:102400000,102400000")
// #pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("trapv")
#include<bits/stdc++.h>

#define int long long
using namespace std;
 
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
const int mod=1e9+7;
const int INF=LLONG_MAX/4;
const int maxn=2007;
const double EPS=1e-9;

int n;
int dp1[maxn][2*maxn],dp2[maxn][2*maxn];
string s,t;
const int OFFSET=maxn;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int _;
    cin>>_;
    while (_--){
        cin>>n>>s>>t;
        for (int i=1;i<=n;++i){
            for (int j=-n;j<=n;++j) dp1[i][OFFSET+j]=dp2[i][OFFSET+j]=0;
        }
        dp1[0][OFFSET]=1;
        auto inc=[&](char s1,char s2, char t1,char t2){
            if (s1!='?'&&s1!=t1) return 0;
            if (s2!='?'&&s2!=t2) return 0;
            return 1;
        };
        for (int i=1;i<=n;++i){
            if (i&1) swap(s[i],t[i]);
            for (int j=-i+1;j<=i-1;++j){
                if (inc(s[i-1],t[i-1],'0','0')) dp1[i][j+OFFSET]=(dp1[i][j+OFFSET]+dp1[i-1][j+OFFSET])%mod, dp2[i][j+OFFSET]=(dp2[i][j+OFFSET]+dp2[i-1][j+OFFSET])%mod;
                if (inc(s[i-1],t[i-1],'1','1')) dp1[i][j+OFFSET]=(dp1[i][j+OFFSET]+dp1[i-1][j+OFFSET])%mod, dp2[i][j+OFFSET]=(dp2[i][j+OFFSET]+dp2[i-1][j+OFFSET])%mod;
                if (inc(s[i-1],t[i-1],'0','1')) dp1[i][j+1+OFFSET]=(dp1[i][j+1+OFFSET]+dp1[i-1][j+OFFSET])%mod, dp2[i][j+1+OFFSET]=(dp2[i][j+1+OFFSET]+dp2[i-1][j+OFFSET]+(j>=0?-1:1)*i*dp1[i-1][j+OFFSET])%mod;
                if (inc(s[i-1],t[i-1],'1','0')) dp1[i][j-1+OFFSET]=(dp1[i][j-1+OFFSET]+dp1[i-1][j+OFFSET])%mod, dp2[i][j-1+OFFSET]=(dp2[i][j-1+OFFSET]+dp2[i-1][j+OFFSET]+(j<=0?-1:1)*i*dp1[i-1][j+OFFSET])%mod;
            }
        }
        cout<<(dp2[n][OFFSET]+mod)%mod<<"\n";
    }

    return 0;
}

/*
5 3 
3 0 2 3 
3 3 0 1
4 0 1 3 4

2 0 3 1 4

1 0 3 4 
*/