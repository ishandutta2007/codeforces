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
using dbl = double;
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

bool is_pw2_arith_seq(vector<int> & V) {
	// test {2^k+i*2^l}_i with l >= k
	int N = V.size();
	for(int i = 0; i < N; i++) if(V[i]&(V[0]-1)) return false;
	if(N == 1) return true;
	int D = V[1]-V[0];
	if(D&(D-1)) return false;
	for(int i = 1; i < N; i++) if(V[i]-V[i-1] != D) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		if(N == 2) {
			cout << "-1\n";
			continue;
		}
		int F = 1, E = 0;
		while(F < N) F *= 2, E++;
		vector< pair<int,int> > ans;
		vector<int> cnt_pw2(E+1, 0);
		queue< vector<int> > q;
		vector<int> init(N);
		for(int i = 0; i < N; i++) init[i] = i+1;
		q.push(init);
		while(!q.empty()) {
			auto v = q.front();
			// for(auto x : v) cout << x << " ";
			// cout << endl;
			q.pop();
			if(!is_pw2_arith_seq(v)) return -1;
			int f = 1, e = 0;
			while(f < v.back()) f *= 2, e++;
			if(v.back() == f) {
				cnt_pw2[e]++;
				v.pop_back();
			}
			if((int)v.empty()) continue;
			vector<int> v1, v2;
			for(auto x : v) {
				if(x&v[0]) v1.push_back(x);
				else v2.push_back(x);
			}
			v = v1;
			v1.clear();
			while(!v.empty() && v.back() > f/2) {
				cnt_pw2[e]++;
				ans.push_back({v.back(), f-v.back()});
				v1.push_back(2*v.back()-f);
				v.pop_back();
			}
			if(v.back() == f/2) {
				cnt_pw2[e-1]++;
				v.pop_back();
			}
			for(int i = 0; i < (int)v1.size(); i++) v.pop_back();
			reverse(begin(v1), end(v1));
			if(!v.empty()) q.push(v);
			if(!v1.empty()) q.push(v1);
			if(!v2.empty()) q.push(v2);
		}
		bool all1 = true;
		for(int i = 0; i < E; i++) if(cnt_pw2[i] > 1) all1 = false;
		if(all1) {
			vector<int> id1;
			for(int i = 0; i < E; i++) if(cnt_pw2[i]) id1.push_back(i);
			if((int)id1.size() <= 2) return -2;
			for(int i = id1[1]; i < id1[2]; i++) {
				ans.push_back({1<<i, 1<<id1[0]});
				ans.push_back({(1<<i)+(1<<id1[0]), (1<<i)-(1<<id1[0])});
				cnt_pw2[id1[0]]--;
				cnt_pw2[id1[0]+1]++;
				cnt_pw2[i]--;
				cnt_pw2[i+1]++;
				id1[0]++;
			}
		}
		for(int i = 0; i < E; i++) if(cnt_pw2[i] > 1) {
			ans.push_back({1<<i, 1<<i});
			cnt_pw2[i] -= 2;
			cnt_pw2[i+1]++;
			for(int j = 0; j <= E; j++) if(cnt_pw2[j] >= 1) {
				ans.push_back({0, 1<<j});
				cnt_pw2[j]++;
				break;
			}
		}
		for(int i = 0; i < E; i++) {
			if(cnt_pw2[i]%2 != 0) {
				ans.push_back({1<<i, 1<<i});
				ans.push_back({0, 1<<i});
				cnt_pw2[i]--;
				cnt_pw2[i+1]++;
			}
			while(cnt_pw2[i] > 0) {
				ans.push_back({1<<i, 1<<i});
				ans.push_back({2<<i, 0});
				cnt_pw2[i+1] += 2;
				cnt_pw2[i] -= 2;
			}
		}
		cout << ans.size() << "\n";
		for(auto p : ans) cout << p.ff << " " << p.ss << "\n";
	}
}

// look at my code
// my code is amazing