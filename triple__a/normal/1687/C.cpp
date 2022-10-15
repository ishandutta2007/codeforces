// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
#pragma GCC optimize("O2")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("trapv")
#include<bits/stdc++.h>
// #include <bits/extc++.h>
#define int long long
// #define double long double
// #define i128 long long
// #define double long double
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
 
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
const int mod=1e9+7;
const double EPS=1e-9;
const double pi=acos(-1);
const int INF=1e18;
const int N=200007;
mt19937 rng(1235);
const int M=30;

int n,m;
int a[N],b[N],sa[N],sb[N];
int l[N],r[N],cnt[N];
vi seg[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout.precision(15);
    int _;
    cin>>_;
    while (_--){
        cin>>n>>m;
        rep1(i,n) cin>>a[i];
        rep1(i,n) cin>>b[i];
        rep1(i,n) sa[i]=sa[i-1]+a[i];
        rep1(i,n) sb[i]=sb[i-1]+b[i];
        rep(i,n+1) seg[i].clear();
        rep1(i,m) cnt[i]=0;
        rep1(i,m){
            int x,y;
            cin>>x>>y;
            x--;
            seg[x].pb(i), seg[y].pb(i);
            l[i]=x, r[i]=y;
        }
        set<int> rem_bad;
        rem_bad.insert(1e9);
        vector<pii> good_seg;
        rep(i,n+1) rem_bad.insert(i);
        auto add=[&](int i){
            // rem_bad.erase(i);
            for (auto c:seg[i]){
                cnt[c]++;
                if (cnt[c]==2) good_seg.pb({l[c],r[c]});
            }
        };
        rep(i,n+1){
            if (sa[i]==sb[i]) {rem_bad.erase(i); add(i);}
        }
        while (sz(good_seg)){
            auto ret=good_seg.back();
            good_seg.pop_back();
            int L=*rem_bad.upper_bound(ret.F);
            vi rem;
            while (L<=ret.S) {
                rem.pb(L);
                add(L), L=*rem_bad.upper_bound(L);
            }
            for (auto c:rem) rem_bad.erase(c);
        }
        if (sz(rem_bad)>1) cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}
/*

*/