// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
#pragma GCC optimize("O2")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("trapv")
#include<bits/stdc++.h>
 
// #define int long long
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
 
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
const int mod=998244353;
const int INF=LLONG_MAX/2;
const double EPS=1e-9;
const int N=100007;
const int K=250;
mt19937 rng(1234);

int n;
int a[N];
int cnt[N*502];
int solve_small(int L,int R){
    int mx=0;
    for (int i=L;i<=R;++i){
        vi reached;
        for (int j=i+1;j<=R;++j){
            if ((a[j]-a[i])%(j-i)) continue;
            cnt[(a[j]-a[i])/(j-i)+N]++;
            reached.pb((a[j]-a[i])/(j-i)+N);
        }
        for (auto u:reached) mx=max(mx,cnt[u]);
        for (auto u:reached) cnt[u]--;
    }
    return mx+1;
}

int solve_large(){
    int ans=0;
    for (int i=-400;i<=400;++i){
        vi reached;
        for (int j=0;j<n;++j){
            cnt[j*i+a[j]+max(0,-i)*N]++;
            reached.pb(j*i+a[j]+max(0,-i)*N);
        }
        for (auto u:reached) ans=max(ans,cnt[u]);
        for (auto u:reached) cnt[u]--;
    }
    return ans;
}
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    cin>>n;
    rep(i,n) cin>>a[i];
    int ans=solve_large();
    for (int i=0;i<n;i+=K){
        ans=max(ans,solve_small(i,min(n-1,i+2*K)));
    }
    cout<<n-ans;
    return 0;
}


/*

*/