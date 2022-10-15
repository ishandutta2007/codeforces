// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
#pragma GCC optimize("O2")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("trapv")
#include<bits/stdc++.h>
 
#define int long long
// #define i128 long long
#define double long double
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
// typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
int dx[]={1,1,2,2,-1,-1,-2,-2};
int dy[]={2,-2,1,-1,2,-2,1,-1};
const int mod=1e9+7;
const int INF=LLONG_MAX/5000;
const double EPS=1e-9;
// const int MAXN=2003*2003;
const int N=200027;
const int K=360*10000;
mt19937 rng(1234);


signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    int _;
    cin>>_;
    while (_--){
        int n,m;
        cin>>n>>m;
        vi cand;
        for (int i=1;i*i<=2*(n+m-2);++i){
            if ((2*(n+m-2))%i) continue;
            cand.pb(i), cand.pb(2*(n+m-2)/i);
        }
        sort(range(cand)), cand.erase(unique(range(cand)),cand.end());
        auto check=[&](int n,int m,int u){
            if (u==1) return 1;
            if (n%u>1) return 0;
            int now=m+(n%u)-1;
            if (now%u>1) return 0;
            now=n+(now%u)-1;
            if (now%u>1) return 0;
            now=m+(now%u)-1;
            if (now%u==1) return 1;
            return 0;
        };
        vi ans;
        for (auto c:cand) if (check(n,m,c)||check(m,n,c)) ans.pb(c);
        cout<<sz(ans)<<" ";
        for (auto c:ans) cout<<c<<" ";
        cout<<"\n";
    }
    
    return 0;
}