// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("trapv")
#include<bits/stdc++.h>
 
#define int long long
#define double long double
using namespace std;
 
namespace std {
 
template<class Fun>
class y_combinator_result {
	Fun fun_;
public:
	template<class T>
	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
 
	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};
 
template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
 
} // namespace std
 
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
const int mod=1e9+7;
const int INF=LLONG_MAX/4;
const double EPS=1e-9;
const int N=100007;
const int K=407;
int n,k;
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15);
    int _;
    cin>>_;
    while (_--){
        cin>>n>>k;
        vi cnt(n+1,0), a(n,0);
        rep(i,n) cin>>a[i], cnt[a[i]]++;
        for (int i=1;i<=n;++i) cnt[i]+=cnt[i-1];
        int l=0, r=1;
        int ansl=-INF,ansr=INF;
        while (1){
            while (r<=n&&2*(cnt[r]-cnt[l])<n+k) r++;
            if (r!=n+1&&r-l<ansr-ansl) ansr=r, ansl=l;
            if (r==n+1) break;
            l++;
        }
        cout<<ansl+1<<" "<<ansr<<"\n";
        int cur=0,prv=0;
        vector<pii> ans;
        rep(i,n){
            if (a[i]>ansl&&a[i]<=ansr) cur++;
            else cur--;
            if (cur>0&&k) ans.pb({prv,i}), cur=0, prv=i+1, k--;
        }
        auto [u,v]=ans.back();
        ans.pop_back();
        ans.pb({u,n-1});
        for (auto [u,v]:ans) cout<<u+1<<" "<<v+1<<"\n"; 
    }
    return 0;
}