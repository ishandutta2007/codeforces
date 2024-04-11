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
#include <bitset>
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
	int T;
	cin >> T;
	while(T--) {
		int N[2];
		vector<int> L[2];
		for(int k = 0; k < 2; k++) {
			cin >> N[k];
			L[k].resize(N[k]);
			for(int i = 0; i < N[k]; i++) cin >> L[k][i];
		}
		if(N[0] != N[1]) {
			cout << "No\n";
			continue;
		}
		vector<int> seg[2][2];
		bool ok = true;
		for(int k = 0; k < 2; k++) {
			sort(begin(L[k]), end(L[k]));
			bitset<(1<<20)> B[501];
			B[0][1<<19] = 1;
			for(int i = 0; i < N[0]; i++) {
				int l = L[k][i];
				B[i+1] = (B[i] << l) | (B[i] >> l);
			}
			if(B[N[0]][1<<19]) {
				vector<int> dir(N[0]);
				int cur = 1<<19;
				for(int i = N[0]-1; i >= 0; i--) {
					int l = L[k][i];
					if(cur-l >= 0 && B[i][cur-l]) dir[i] = -1, cur -= l;
					else dir[i] = 1, cur += l;
				}
				for(int i = 0; i < N[0]; i++) {
					if(dir[i] == -1) seg[k][1].push_back(L[k][i]);
					else seg[k][0].push_back(L[k][i]);
				}
				if(seg[k][0].size() < seg[k][1].size()) swap(seg[k][0], seg[k][1]);
			}
			else ok = false;
		}
		if(!ok) cout << "No\n";
		else {
			cout << "Yes\n";
			int x = 0, y = 0;
			int A = seg[0][0].size(), B = seg[0][1].size();
			int C = seg[1][0].size(), D = seg[1][1].size();
			for(int i = 0; i < B; i++) {
				x += seg[0][1][B-1-i];
				cout << x << " " << y << "\n";
				y += seg[1][0][C-1-i];
				cout << x << " " << y << "\n";
			}
			for(int i = 0; i < N[0]-B-D; i++) {
				x -= seg[0][0][i];
				cout << x << " " << y << "\n";
				y += seg[1][0][i];
				cout << x << " " << y << "\n";
			}
			for(int i = 0; i < D; i++) {
				x -= seg[0][0][A-1-(D-1-i)];
				cout << x << " " << y << "\n";
				y -= seg[1][1][i];
				cout << x << " " << y << "\n";
			}
		}
	}
}

// look at my code
// my code is amazing