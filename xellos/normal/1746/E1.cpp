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
	int N;
	cin >> N;
	vector<int> S(N);
	for(int i = 1; i <= N; i++) S[i-1] = i;
	while(S.size() > 3) {
		vector<int> P[4];
		for(int i = 0; i < (int)S.size(); i++) P[i&3].push_back(S[i]);
		string s0, s1;
		cout << "? " << P[0].size()+P[1].size();
		for(auto v : P[0]) cout << " " << v;
		for(auto v : P[1]) cout << " " << v;
		cout << endl;
		cin >> s0;
		cout << "? " << P[0].size()+P[2].size();
		for(auto v : P[0]) cout << " " << v;
		for(auto v : P[2]) cout << " " << v;
		cout << endl;
		cin >> s1;
		int bad;
		if(s0 == "YES" && s1 == "YES") bad = 3;
		if(s0 == "YES" && s1 == "NO") bad = 2;
		if(s0 == "NO" && s1 == "YES") bad = 1;
		if(s0 == "NO" && s1 == "NO") bad = 0;
		vector<int> S_nw;
		for(int i = 0; i < 4; i++) if(i != bad) for(auto v : P[i]) S_nw.push_back(v);
		S = S_nw;
	}
	if(S.size() == 1) {
		cout << "! " << S[0] << endl;
		string s;
		cin >> s;
		return 0;
	}
	if(S.size() == 2) {
		cout << "! " << S[0] << endl;
		string s;
		cin >> s;
		if(s == ":)") return 0;
		cout << "! " << S[1] << endl;
		cin >> s;
		return 0;
	}
	if(S.size() == 3) {
		cout << "? 1 " << S[0] << endl;
		string s0;
		cin >> s0;
		cout << "? 1 " << S[1] << endl;
		string s1;
		cin >> s1;
		if(s0 == "NO" && s1 == "NO") {
			cout << "? 1 " << S[1] << endl;
			string s1r;
			cin >> s1r;
			if(s1r == "NO") {
				cout << "! " << S[0] << endl;
				string s;
				cin >> s;
				if(s == ":)") return 0;
				cout << "! " << S[2] << endl;
				cin >> s;
				return 0;
			}
			cout << "! " << S[1] << endl;
			string s;
			cin >> s;
			if(s == ":)") return 0;
			cout << "? 1 " << S[0] << endl;
			string s0r;
			cin >> s0r;
			cout << "! " << ((s0r == "YES") ? S[0] : S[2]) << endl;
			cin >> s;
			return 0;
		}
		cout << "! " << ((s0 == "YES") ? S[0] : S[1]) << endl;
		string s;
		cin >> s;
		if(s == ":)") return 0;
		int id;
		if(s0 == "YES" && s1 == "YES") id = 1;
		if(s0 == "YES" && s1 == "NO") id = 2;
		if(s0 == "NO" && s1 == "YES") id = 2;
		cout << "! " << S[id] << endl;
		cin >> s;
		return 0;
	}
}

// look at my code
// my code is amazing