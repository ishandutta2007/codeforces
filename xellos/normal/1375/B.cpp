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
	int T;
	cin >> T;
	while(T--) {
		int N, M;
		cin >> N >> M;
		vector< vector<int> > A(N, vector<int>(M));
		for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) cin >> A[i][j];
		vector< vector<int> > mx(N, vector<int>(M, 0));
		for(int i = 0; i < N; i++) for(int j = 0; j < M-1; j++) mx[i][j]++, mx[i][j+1]++;
		for(int i = 0; i < N-1; i++) for(int j = 0; j < M; j++) mx[i][j]++, mx[i+1][j]++;
		bool ok = true;
		for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) if(A[i][j] > mx[i][j]) ok = false;
		if(!ok) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) cout << mx[i][j] << ((j == M-1) ? "\n" : " ");
	}
}

// look at my code
// my code is amazing