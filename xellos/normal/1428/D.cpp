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
#define OVER9000 1234567890123LL
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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	vector<int> pos(N);
	vector< vector<int> > seq;
	vector<int> free1;
	int last3 = N, last2 = N;
	for(int i = N-1; i >= 0; i--) {
		if(A[i] == 0) continue;
		if(A[i] == 3) {
			if(last3 != N) pos[i] = pos[last3], seq[pos[last3]].push_back(i);
			else if(last2 != N) pos[i] = pos[last2], seq[pos[last2]].push_back(i);
			else if(free1.empty()) {
				cout << "-1\n";
				return 0;
			}
			else {
				pos[i] = pos[free1.back()] = seq.size();
				seq.push_back({free1.back(), i});
				free1.pop_back();
			}
			last3 = i;
			continue;
		}
		if(A[i] == 1) {
			free1.push_back(i);
			continue;
		}
		// A[i] == 2
		if(free1.empty()) {
			cout << "-1\n";
			return 0;
		}
		pos[i] = pos[free1.back()] = seq.size();
		seq.push_back({free1.back(), i});
		free1.pop_back();
		last2 = i;
	}
	while(!free1.empty()) {
		pos[free1.back()] = seq.size();
		seq.push_back({free1.back()});
		free1.pop_back();
	}
	int R = 0;
	vector< pair<int, int> > ans;
	for(auto & v : seq) {
		int L = v.size();
		reverse(begin(v), end(v));
		if(L == 1) {
			ans.push_back({R, v[0]});
			R++;
			continue;
		}
		for(int i = 0; i < L-1; i++) if(A[v[i]] == 3) {
			ans.push_back({R, v[i]});
			ans.push_back({R, v[i+1]});
			R++;
		}
		if(A[v[L-2]] == 2) {
			ans.push_back({R, v[L-2]});
			ans.push_back({R, v[L-1]});
			R++;
		}
		else {
			ans.push_back({R, v[L-1]});
			R++;
		}
	}
	cout << ans.size() << "\n";
	for(auto p : ans) cout << p.ff+1 << " " << p.ss+1 << "\n";
}

// look at my code
// my code is amazing