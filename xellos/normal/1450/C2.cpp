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
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		vector<string> S(N);
		for(int i = 0; i < N; i++) cin >> S[i];
		int n[3][2] = {{0,0},{0,0},{0,0}};
		for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) {
			if(S[i][j] == 'X') n[(i+j)%3][0]++;
			if(S[i][j] == 'O') n[(i+j)%3][1]++;
		}
		int mx_id = 0;
		for(int i = 0; i < 3; i++)
			if(n[i][0]+n[i][1] > n[mx_id][0]+n[mx_id][1]) mx_id = i;
		int cost[2] = {0,0};
		for(int i = 0, k = 0; i < 3; i++) if(i != mx_id) {
			cost[0] += n[i][k];
			cost[1] += n[i][1-k];
			k++;
		}
		int mi = (cost[0] < cost[1]) ? 0 : 1;
		for(int i = 0, k = 0; i < 3; i++) if(i != mx_id) {
			for(int j = 0; j < N*N; j++) if(((j/N)+(j%N)-i)%3 == 0) {
				if(S[j/N][j%N] == '.') continue;
				if(k == 0) S[j/N][j%N] = (mi == 0) ? 'O' : 'X';
				if(k == 1) S[j/N][j%N] = (mi == 0) ? 'X' : 'O';
			}
			k++;
		}
		for(int i = 0; i < N; i++) cout << S[i] << "\n";
	}
}

// look at my code
// my code is amazing