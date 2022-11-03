/**
 *    author:  otera    
**/
#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<deque>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
using namespace std;

#define int long long
typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
typedef long double ld;
const int inf=1e9+7;
const ll INF=1LL<<60 ;
const ll mod=1e9+7 ;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<int, int> P;
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
#define pb push_back
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template <class Abel> struct BIT {
private:
	vector<Abel> node; int n;
    Abel UNITY_SUM = 0; //to be set
public:
	BIT(int n_) {
		n = n_; node.resize(n, UNITY_SUM);
	}
	//0-indexed
	void add(int a, Abel w) {
		for (int i = a; i < n; i |= i + 1)node[i] += w;
	}
	//[0,a)
	Abel sum(int a) {
		Abel ret = UNITY_SUM;
		for (int i = a - 1; i >= 0; i = (i&(i + 1)) - 1)ret += node[i];
		return ret;
	}
	//[a,b)
	Abel sum(int a, int b) {
		return sum(b) - sum(a);
	}
	//k-th number (k is 0-indexed)
    int get(int k) {
        ++k;
        int res = 0;
        int n = 1; while(n < (int)node.size()) n *= 2;
        for(int i = n / 2; i > 0; i /= 2) {
            if(res + i < (int)node.size() && node[res + i - 1] < k) {
                k -= node[res + i - 1];
                res += i;
            }
        }
        return res; //0-indexed
    }
    //debug
    void print() {
        for(int i = 0; i < n; ++i) cout << sum(i, i + 1) << ",";
        cout << endl;
    }
};

template<typename T>
vector<T> compress(vector<T> A){
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    return A;
}

void solve() {
	int n; cin >> n;
    vector<P> ps(n);
	vector<int> v(n);
	rep(i, n) {
		cin >> ps[i].fr;
	}
	rep(i, n) {
		cin >> ps[i].sc;
		v[i] = ps[i].sc;
	}
	auto vcomp = compress(v);
	int sz = vcomp.size();
	sort(all(ps));
	BIT<int> bit1(sz + 3), bit2(sz + 3);
	int ans = 0;
	rep(i, n) {
		int k = lower_bound(all(vcomp), ps[i].sc) - vcomp.begin();
		ans += ps[i].fr * bit1.sum(0, k + 1) - bit2.sum(0, k + 1);
		bit1.add(k, 1);
		bit2.add(k, ps[i].fr);
	}
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}