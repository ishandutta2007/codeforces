// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("trapv")
#include<bits/stdc++.h>
 
// #define int long long
#define double long double
using namespace std;


// namespace std {
 
// template<class Fun>
// class y_combinator_result {
// 	Fun fun_;
// public:
// 	template<class T>
// 	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
 
// 	template<class ...Args>
// 	decltype(auto) operator()(Args &&...args) {
// 		return fun_(std::ref(*this), std::forward<Args>(args)...);
// 	}
// };
 
// template<class Fun>
// decltype(auto) y_combinator(Fun &&fun) {
// 	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
// }
 
// } // namespace std
 
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
 
int dx[]={0,1,0,-1,1,-1};
int dy[]={1,0,-1,0,1,-1};
// const int mod=998244353;
const int INF=LLONG_MAX/4;
const double EPS=1e-9;
const int N=507;
const int K=10;

mt19937 rng(1234);

int n,q;
int a[N],b[N];
bool vis[N];
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    int _;
    cin>>_;
    while (_--){
        vector<pii> ans;
        vector<int> len;
        auto solve=[&](){
            cin>>n;
            rep(i,n) cin>>a[i];
            if (n&1){
                cout<<"-1\n";
                return;
            }
            for (int i=n-1;i>0;i-=2){
                int pos=-1;
                for (int j=i-1;j>-1;--j){
                    if (a[i]==a[j]) {
                        pos=j;
                        break;
                    }
                }
                if (pos==-1){
                    cout<<"-1\n";
                    return;
                }
                int cnt=0;
                for (int k=i-1;k>pos;--k){
                    ans.pb({pos+cnt,a[k]}), cnt++;
                }
                len.pb((i-pos)*2);
                for (int le=pos,ri=i-1;le<ri;le++,ri--) swap(a[le],a[ri]);
            }
            reverse(range(len));
            cout<<sz(ans)<<"\n";
            for (auto c:ans) cout<<c.F<<" "<<c.S<<"\n";
            cout<<sz(len)<<"\n";
            for (auto c:len) cout<<c<<" ";
            cout<<"\n";
        };
        solve();
    }
    return 0;
}

/*
0 0 1 1 0 1 
0 0 1 0 1 0
1 1 0 1 0 0
1 0 1 0 0 0
0 1 0 0 0 0
1 0 0 0 0 0
*/