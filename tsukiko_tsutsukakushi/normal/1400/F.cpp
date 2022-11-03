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
#include<unordered_set>
#include<utility>
#include<array>
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

template <int K, class T>
struct PatternMatching {
    struct Node {
        int c;
        std::array<int, K> nxt;
        int fail;
        bool matched;
        explicit Node(int c)
            : c(c), fail(0), matched(false) { nxt.fill(-1); }
    };
 
    std::vector<Node> nodes;
    std::function<int(T)> enc;
 
    explicit PatternMatching(T base) {
        nodes.emplace_back(-1);
        enc = [=](T c) { return c - base; };
    }
 
    explicit PatternMatching(const std::function<int(T)>& enc)
        : enc(enc) { nodes.emplace_back(-1); }
 
    template <class Container>
    void add(const Container& s) {
        int pos = 0;
        for (T ci : s) {
            int c = enc(ci);
 
            int npos = nodes[pos].nxt[c];
            if (npos == -1) {
                npos = nodes.size();
                nodes[pos].nxt[c] = npos;
                nodes.emplace_back(c);
            }
            pos = npos;
        }
        nodes[pos].matched = true;
    }
 
    int next(int pos, int c) const {
        while (nodes[pos].nxt[c] == -1) pos = nodes[pos].fail;
        return nodes[pos].nxt[c];
    }
 
    void build() {
        std::queue<int> que;
        for (int& pos : nodes[0].nxt) {
            if (pos == -1) {
                pos = 0;
            } else {
                que.push(pos);
            }
        }
 
        while (!que.empty()) {
            int pos = que.front();
            que.pop();
 
            for (int c = 0; c < K; ++c) {
                int npos = nodes[pos].nxt[c];
                if (npos == -1) continue;
 
                int p = nodes[pos].fail;
                while (nodes[p].nxt[c] == -1) p = nodes[p].fail;
                int fpos = next(nodes[pos].fail, c);
 
                nodes[npos].fail = fpos;
                if (nodes[fpos].matched) nodes[pos].matched = true;
 
                que.push(npos);
            }
        }
    }
 
    Node& operator[](int pos) { return nodes[pos]; }
    Node operator[](int pos) const { return nodes[pos]; }
};

string s; int x;
vector<string> ps;

bool judge(string t) {
	int n = (int)t.size();
	for(int l = 0; l < n; ++ l) {
		int sum = 0;
		for(int r = l; r < n; ++ r) {
			sum += t[r] - '0';
			if(sum != x and x % sum == 0) {
				return true;
			}
		}
	}
	return false;
}

void dfs(string& t, int num) {
	if(num == x and !judge(t)) ps.push_back(t);
	for(int d = 1; d <= 9 and num + d <= x; ++ d) {
		t.push_back('0' + d);
		dfs(t, num + d);
		t.pop_back(); 
	}
}

void solve() {
    cin >> s >> x;
    string tmp = "";
	dfs(tmp, 0);
	PatternMatching<9, char> pm('1');
	for(auto p: ps) pm.add(p);
	pm.build();
	int n = (int)pm.nodes.size();
	vector<int> dp(n, INF);
	vector<int> ndp(n, INF);
	dp[0] = 0;
	for(char c: s) {
		ndp.assign(n, INF);
		for(int pos = 0; pos < n; ++ pos) {
			chmin(ndp[pos], dp[pos] + 1);
			int npos = pm.next(pos, pm.enc(c));
			if(!pm[npos].matched) {
				chmin(ndp[npos], dp[pos]);
			}
		}
		swap(ndp, dp);
	}
	cout << *min_element(all(dp)) << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}