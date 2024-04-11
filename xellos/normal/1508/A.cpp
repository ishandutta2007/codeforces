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
#define OVER9000 1234567890
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

template <typename T>
class minfin {
	vector<T> node_val;
	T init_val_;

	int lastone(int x) { return x & (x ^ (x-1)); }

public:
	minfin(int N, T init_val) {
		init_val_ = init_val;
		node_val.resize(N+10, init_val);
	}

	void put(int pos, T val) {
		for(int i = pos+1; i < (int)node_val.size(); i += lastone(i))
			node_val[i] = min(node_val[i], val);
	}

	T get(int pos) {
		T ret = init_val_;
		for(int i = pos+1; i > 0; i -= lastone(i))
			ret = min(ret, node_val[i]);
		return ret;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int T;
	cin >> T;
	while(T--) {
		int N;
		string S[3];
		cin >> N >> S[0] >> S[1] >> S[2];
		int n[2][3] = {{0, 0, 0}, {0, 0, 0}};
		for(int k = 0; k < 3; k++) {
			for(int i = 0; i < 2*N; i++) n[0][k] += (S[k][i] == '0');
			n[1][k] = 2*N-n[0][k];
		}
		for(int c = 0; c < 2; c++) {
			int id[2] = {-1, -1};
			for(int k = 0; k < 3; k++) if(n[c][k] >= N) {
				if(id[0] == -1) id[0] = k;
				else id[1] = k;
			}
			if(id[1] == -1) continue;
			string ans;
			int pos[2] = {0, 0};
			while(pos[0] < 2*N || pos[1] < 2*N) {
				if(pos[0] < 2*N && S[id[0]][pos[0]] != '0'+c) {
					ans += '0'+1-c;
					pos[0]++;
					if(pos[1] < 2*N && S[id[1]][pos[1]] != '0'+c) pos[1]++;
					continue;
				}
				if(pos[1] < 2*N && S[id[1]][pos[1]] != '0'+c) {
					ans += '0'+1-c;
					pos[1]++;
					if(pos[0] < 2*N && S[id[0]][pos[0]] != '0'+c) pos[0]++;
					continue;
				}
				if(pos[0] == 2*N) {
					ans += S[id[1]][pos[1]];
					pos[1]++;
					continue;
				}
				if(pos[1] == 2*N) {
					ans += S[id[0]][pos[0]];
					pos[0]++;
					continue;
				}
				ans += '0'+c;
				pos[0]++, pos[1]++;
			}
			cout << ans << "\n";
			break;
		}
	}
}

// look at my code
// my code is amazing