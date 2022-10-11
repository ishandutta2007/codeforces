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
#define abs(x) (((x) < 0)?-(x):(x))
using uint = unsigned int;
using cat = long long;
using dbl = long double;
constexpr dbl pi = 3.14159265358979323846;
using namespace std;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int N, K;
	cin >> N >> K;
	// . = 0, R = 1, Y = 2, B = 3
	vector<uint64_t> st(N, 0);
	for(int i = 0; i < N; i++) st[i] = 9;
	constexpr int B = 64;
	vector< vector<uint64_t> > eq_coef;
	vector<char> eq_res;
	for(int i = 0; i < K; i++) {
		string type;
		int M;
		cin >> type >> M;
		if(type == "mix") {
			static vector<uint64_t> V0(2*N/B+1);
			static vector<uint64_t> V1(2*N/B+1);
			memset(&(V0[0]), 0, 2*N/8+1);
			memset(&(V1[0]), 0, 2*N/8+1);
			for(int j = 0, id; j < M; j++) {
				cin >> id;
				id--;
				V0[2*id/B] |= (st[id]&3)<<((2*id)&(B-1));
				V1[2*id/B] |= (st[id]>>2)<<((2*id)&(B-1));
			}
			eq_coef.push_back(V0);
			eq_coef.push_back(V1);
			string res;
			cin >> res;
			eq_res.push_back(res == "R" || res == "B");
			eq_res.push_back(res == "Y" || res == "B");
			continue;
		}
		for(int j = 0, id; j < M; j++) {
			cin >> id;
			char b = st[--id];
			if(type == "RB") st[id] ^= (b&3)<<2;
			else if(type == "YB") st[id] ^= b>>2;
			else { // if(type == "RY")
				b = (b&3)^(b>>2);
				st[id] ^= b|(b<<2);
			}
		}
	}
	int E = eq_res.size(), a = 0;
	vector<int> pivot(E);
	for(int v = 0; v < 2*N; v++) {
		int cur = -1;
		for(int i = a; i < E; i++) {
			auto b = (eq_coef[i][v/B])>>(v&(B-1));
			if(!(b&1)) continue;
			cur = i;
			break;
		}
		if(cur == -1) continue;
		pivot[a] = v;
		swap(eq_res[cur], eq_res[a]);
		swap(eq_coef[cur], eq_coef[a]);
		for(int i = a+1; i < E; i++) {
			auto b = (eq_coef[i][v/B])>>(v&(B-1));
			if(!(b&1)) continue;
			eq_res[i] ^= eq_res[a];
			for(int j = 0; j <= 2*N/B; j++) eq_coef[i][j] ^= eq_coef[a][j];
		}
		a++;
	}
	for(int i = a; i < E; i++) if(eq_res[i]) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	vector<char> val(2*N, 0);
	for(int i = a-1; i >= 0; i--) {
		val[pivot[i]] = eq_res[i];
		for(int j = 0; j < 2*N; j++) if(j != pivot[i])
			val[pivot[i]] ^= (eq_coef[i][j/B]>>(j&(B-1)))&1&val[j];
	}
	string ans;
	for(int i = 0; i < N; i++) {
		if(val[2*i] == 0 && val[2*i+1] == 0) ans += '.';
		if(val[2*i] == 1 && val[2*i+1] == 0) ans += 'R';
		if(val[2*i] == 0 && val[2*i+1] == 1) ans += 'Y';
		if(val[2*i] == 1 && val[2*i+1] == 1) ans += 'B';
	}
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing