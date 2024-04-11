// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <chrono>
#include <random>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890123456789LL
#define tisic 47
#define soclose 1e-8
#define patkan 9
#define ff first
#define ss second
using uint = unsigned int;
using cat = long long;
using dbl = long double;
constexpr dbl pi = 3.14159265358979323846;
using namespace std;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

template <typename T>
T abs(T x) { return (x < 0) ? (-x) : x; }

cat gcd(cat a, cat b) {
	if(a > b) swap(a, b);
	while(a) {
		cat c = b%a;
		b = a;
		a = c;
	}
	return b;
}

cat pw(cat a, cat e, cat mod) {
	if(e <= 0) return 1;
	cat x = pw(a, e/2, mod);
	x = x * x % mod;
	return (e&1) ? x * a % mod : x;
}

template <typename T>
class fin {
	vector<T> node_val;

	int lastone(int x) { return x & (x ^ (x-1)); }

public:
	fin(int N, T init_val) {
		node_val.resize(N+10, init_val);
	}

	void put(int pos, T val) {
		for(int i = pos+1; i < (int)node_val.size(); i += lastone(i))
			node_val[i] += val;
	}

	T get(int pos) {
		T ret = 0;
		for(int i = pos+1; i > 0; i -= lastone(i))
			ret += node_val[i];
		return ret;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	constexpr int MX = 200;
	cout << "? " << MX*MX << endl;
	for(int x = 1; x <= MX; x++) for(int y = 1; y <= MX; y++) {
		if(x > 1 || y > 1) cout << " ";
		cout << x << " " << y;
	}
	cout << endl;
	int S;
	cin >> S;
	vector< pair<int,int> > cand;
	for(int i = 2; i <= min(S-1,MX); i++) if(S%i == 0 && S/i <= MX)
		cand.push_back({i, S/i});
	int C = cand.size();

	while(C > 1) {
		bool done = true;
		for(int i = 0; i < C; i++)
			if(cand[i].ff+cand[i].ss != cand[0].ff+cand[0].ss) done = false;
		if(done) break;
		int da_pick = 0, db_pick = 0, max_sz_cl_pick = C;
		map<int, vector<int> > ans_cand_pick;
		for(int da = 1; da <= MX; da++) for(int db = 1; db <= MX; db++) {
			set<int> ans_cand;
			static vector<int> V[40010];
			for(int i = 0; i < C; i++) {
				auto [a,b] = cand[i];
				for(int k = a/da; k <= (a+da-1)/da; k++) for(int l = b/db; l <= (b+db-1)/db; l++) {
					int ans = k*b+l*a-k*l;
					ans_cand.insert(ans);
					V[ans].push_back(i);
				}
			}
			int n_cl = 0, max_sz_cl = 0;
			for(auto ans : ans_cand) {
				vector<int> & v = V[ans];
				sort(begin(v), end(v));
				auto it = unique(begin(v), end(v));
				int sz = it - begin(v);
				v.resize(sz);
				max_sz_cl = max(max_sz_cl, sz);
				n_cl++;
			}
			if(max_sz_cl >= max_sz_cl_pick) {
				for(auto ans : ans_cand) V[ans].clear();
				continue;
			}
			max_sz_cl_pick = max_sz_cl;
			ans_cand_pick.clear();
			for(auto ans : ans_cand) {
				ans_cand_pick[ans] = V[ans];
				V[ans].clear();
			}
			da_pick = da, db_pick = db;
		}
		if(da_pick == 0) {
			cerr << "F\n";
			return 0;
		}
		vector< pair<int, int> > pts;
		for(int x = 0; x < MX; x++) for(int y = 0; y < MX; y++)
			if(x%da_pick == 0 || y%db_pick == 0) 
				pts.push_back({x+1, y+1});
		cout << "? " << pts.size() << endl;
		for(int i = 0; i < (int)pts.size(); i++) {
			if(i) cout << " ";
			cout << pts[i].ff << " " << pts[i].ss;
		}
		cout << endl;
		int ans;
		cin >> ans;
		vector< pair<int, int> > cand_nw;
		for(auto id : ans_cand_pick[ans]) cand_nw.push_back(cand[id]);
		cand = cand_nw;
		C = cand.size();
	}
	cout << "! " << 2*(cand[0].ff+cand[0].ss-2) << endl;
}

// look at my code
// my code is amazing