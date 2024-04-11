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
        if (n==4&&k==3){
            cout<<"-1\n";
            continue;
        }
        if (k<n-1){
            if (!k) rep(i,n/2) cout<<i<<" "<<n-1-i<<"\n";
            else{
                rep(i,n/2){
                    if (i==0||i==k||i==n-1-k) continue;
                    cout<<i<<" "<<n-1-i<<"\n"; 
                }
                cout<<0<<" "<<n-1-k<<"\n";
                cout<<n-1<<" "<<k<<"\n";
            } 
        }
        else{
            for (int i=3;i<n/2;++i) cout<<i<<" "<<n-1-i<<"\n";
            cout<<"0 2\n1 "<<n-3<<"\n"<<n-1<<" "<<n-2<<"\n";
        }
    }
    return 0;
}