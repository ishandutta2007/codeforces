/**
 *    author:  otera    
**/
#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll INF=1LL<<60;
#define rep(i, n) for(int i = 0; i < n; ++ i)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
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
            if(res + i <= (int)node.size() && node[res + i - 1] < k) {
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

void solve() {
    int n; string s; cin >> n >> s;
    string t = s; reverse(all(t));
    const int N = 26;
    vector<deque<int>> g(N);
    rep(i, n) {
        int c = s[i] - 'a';
        g[c].push_back(i);
    }
    vector<int> res(n, -1);
    rep(i, n) {
        int c = t[i] - 'a';
        res[i] = g[c].front();
        g[c].pop_front();
    }
    ll ans = 0;
    BIT<int> bit(n);
    rep(i, n) {
        ans += bit.sum(res[i], n);
        bit.add(res[i], 1);
    }
    cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}