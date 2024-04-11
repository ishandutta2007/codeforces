// #pragma comment(linker, "/STACK:102400000,102400000")
// #pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("unroll-loops")
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


const int maxn=300007;
const int mod=998244353;
int n;
int a[maxn],b[maxn],c[maxn];
priority_queue<pii,vector<pii>> pq;
vi reach[maxn];
vi ans;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.precision(15), cerr.precision(10);
    cin>>n;
    rep1(i,n) cin>>a[i];
    rep1(i,n) cin>>b[i];
    rep1(i,n){
        c[b[i]+i]=max(c[b[i]+i],i);
    }
    rep1(i,n){
        reach[max(0ll,i-a[i])].pb(i);
    }
    int cur=0;
    for (auto d:reach[0]){
        pq.push({c[d],d});
    }
    while (sz(pq)&&cur<n-a[n]){
        auto [u,v]=pq.top();
        pq.pop();
        if (u<=cur) continue;
        for (int i=cur+1;i<=u;++i){
            for (auto idx:reach[i]){
                pq.push({c[idx],idx});
            }
        }
        ans.pb(u);
        cur=u;
    }
    if (cur<n-a[n]) cout<<-1;
    else{
        reverse(range(ans));
        ans.pb(0);
        cout<<sz(ans)<<"\n";
        for (auto c:ans) cout<<c<<" ";
    }
    return 0;
}