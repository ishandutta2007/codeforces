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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector< vector<int> > id(N, vector<int>(N));
	vector<int> cnt(2*N-1, 0);
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) id[i][j] = cnt[i+j]++;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(j) cout << " ";
			cout << (id[i][j]%2)*(1LL<<(i+j));
		}
		cout << endl;
	}
	int Q;
	cin >> Q;
	for(int q = 0; q < Q; q++) {
		cat sum;
		cin >> sum;
		vector< pair<int, int> > path(2*N-1);
		path[0] = {0, 0};
		for(int i = 0; i < 2*N-2; i++) {
			path[i+1] = {path[i].ff, path[i].ss};
			cat b = (sum>>(i+1))&1;
			if(path[i].ff < N-1 && id[path[i].ff+1][path[i].ss]%2 == b) path[i+1].ff++;
			else path[i+1].ss++;
		}
		for(int i = 0; i < 2*N-2; i++) cout << path[i].ff+1 << " " << path[i].ss+1 << "\n";
		cout << N << " " << N << endl;
	}
}

// look at my code
// my code is amazing