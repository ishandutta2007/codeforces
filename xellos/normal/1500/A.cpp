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

void find_ans(vector<int> A, int a, int b, int c, int d) {
	int N = A.size();
	int bl[4] = {-1, -1, -1, -1};
	for(int i = 0; i < N; i++) if(A[i] == a) {
		bl[0] = i;
		break;
	}
	for(int i = 0; i < N; i++) if(A[i] == b && i != bl[0]) {
		bl[1] = i;
		break;
	}
	for(int i = 0; i < N; i++) if(A[i] == c && i != bl[0] && i != bl[1]) {
		bl[2] = i;
		break;
	}
	for(int i = 0; i < N; i++) if(A[i] == d && i != bl[0] && i != bl[1] && i != bl[2]) {
		bl[3] = i;
		break;
	}
	cout << "YES\n" << bl[0]+1 << " " << bl[1]+1 << " " << bl[2]+1 << " " << bl[3]+1 << "\n";
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N;
	cin >> N;
	int MX = 5000000;
	vector<int> cnt(MX+1, 0), A(N);
	for(int i = 0; i < N; i++) {
		cin >> A[i];
		cnt[A[i]]++;
	}
	vector<int> val;
	int n_dif = 0;
	for(int i = 0; i <= MX; i++) if(cnt[i]) {
		val.push_back(i);
		n_dif++;
		if(n_dif * (n_dif-1) / 2 > MX) break;
	}
	for(int i = 0; i < n_dif; i++) if(cnt[val[i]] >= 4)
		find_ans(A, val[i], val[i], val[i], val[i]);
	for(int i = 0; i < n_dif; i++) for(int j = 0; j < i; j++)
		if(cnt[val[i]] >= 2 && cnt[val[j]] >= 2)
			find_ans(A, val[i], val[j], val[i], val[j]);
	vector<int> n_sums(MX+1, 0);
	for(int i = 0; i < n_dif; i++) for(int j = 0; j < i; j++) n_sums[val[i]+val[j]]++;
	for(int i = 0; i <= MX; i++) if(n_sums[i] >= 2) {
		int a = 0, b = 0;
		for(int j = 0; j < n_dif; j++) if(val[j] < i && i-val[j] < val[j] && cnt[i-val[j]]) {
			if(a == 0) a = val[j];
			else if(b == 0) b = val[j];
			else break;
		}
		find_ans(A, a, i-a, b, i-b);
	}
	for(int i = 0; i <= MX; i++) if(cnt[i] > 1)
		for(int j = 0; j < N; j++) if(A[j] < i && cnt[2*i-A[j]])
			for(int k = 0; k < N; k++) if(A[k] == 2*i-A[j]) {
				cout << "YES\n" << j+1 << " " << k+1 << " ";
				int a = 0, b = 0;
				for(int l = 0; l < N; l++) if(A[l] == i) {
					if(a == 0) a = l;
					else if(b == 0) b = l;
					else break;
				}
				cout << a+1 << " " << b+1 << "\n";
				return 0;
			}
	cout << "NO\n";
}

// look at my code
// my code is amazing