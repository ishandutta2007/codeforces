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
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		string S[10];
		for(int i = 0; i < N; i++) cin >> S[i];
		int occ[52][20];
		for(int i = 0; i < 52; i++) {
			char c = (i < 26) ? ('a'+i) : ('A'+i-26);
			for(int j = 0; j < 20; j++) occ[i][j] = -1;
			for(int j = 0; j < N; j++) for(int k = 0, a = 0; k < (int)S[j].length(); k++)
				if(S[j][k] == c) occ[i][2*j+(a++)] = k;
		}
		int L = S[0].length();
		vector< vector< pair<char,char> > > LCS(L, vector< pair<char,char> >(1<<(2*N), pair<char,char>(0, 0)));
		int ans_l = 0;
		pair<int,int> st_best;
		for(int i = 0; i < L; i++) {
			int id = (S[0][i] >= 'a' && S[0][i] <= 'z') ? (S[0][i]-'a') : (S[0][i]-'A'+26);
			int st = (occ[id][0] == i) ? (1<<0) : (1<<1);
			for(int j = 1; j < N; j++) {
				if(occ[id][2*j] == -1) {
					st = -1;
					break;
				}
				st += (1<<(2*j));
			}
			if(st == -1) continue;
			if(LCS[i][st].ff == 0) LCS[i][st] = pair<char,char>(1,0);
			for(int j = 0; j < (1<<(2*N)); j++) if(LCS[i][j].ff > 0) {
				ans_l = max(ans_l, 1*LCS[i][j].ff);
				if(ans_l == LCS[i][j].ff) st_best.ff = i, st_best.ss = j;
				int pos[10];
				for(int k = 0; k < N; k++) {
					if((j>>(2*k))&1) pos[k] = occ[id][2*k];
					else pos[k] = occ[id][2*k+1];
				}
				for(int k = 0; k < 52; k++) {
					int nxt = 0, d = 0;
					for(int a = 0; a < N; a++) {
						int b = 2*a;
						if(occ[k][b] <= pos[a]) b++;
						if(occ[k][b] <= pos[a]) b++;
						if(b == 2*a+2) {
							nxt = -1;
							break;
						}
						nxt += 1<<b;
						if(a == 0) d = occ[k][b];
					}
					if(nxt == -1) continue;
					if(LCS[d][nxt].ff < LCS[i][j].ff+1) {
						LCS[d][nxt].ff = LCS[i][j].ff+1;
						LCS[d][nxt].ss = i;
					}
				}
			}
		}
		cout << ans_l << "\n";
		if(ans_l == 0) {
			cout << "\n";
			continue;
		}
		string ans;
		for(int i = 0; i < ans_l; i++) {
			ans += S[0][st_best.ff];
			int id = (S[0][st_best.ff] >= 'a' && S[0][st_best.ff] <= 'z') ? (S[0][st_best.ff]-'a') : (S[0][st_best.ff]-'A'+26);
			if(i == ans_l-1) break;
			int prev_pos = LCS[st_best.ff][st_best.ss].ss;
			int prev_id = (S[0][prev_pos] >= 'a' && S[0][prev_pos] <= 'z') ? (S[0][prev_pos]-'a') : (S[0][prev_pos]-'A'+26);
			int pos[10];
			for(int k = 0; k < N; k++) {
				if((st_best.ss>>(2*k))&1) pos[k] = occ[id][2*k];
				else pos[k] = occ[id][2*k+1];
			}
			pair<int,int> st_prev = {prev_pos,0};
			for(int j = 0; j < (1<<(2*N)); j++) if(LCS[prev_pos][j].ff == ans_l-1-i) {
				bool ok = true;
				for(int k = 0; k < N; k++) {
					int a = ((j>>(2*k))&1) ? occ[prev_id][2*k] : occ[prev_id][2*k+1];
					if(a != -1 && a < pos[k]) continue;
					ok = false;
					break;
				}
				if(ok) {
					st_prev.ss = j;
					break;
				}
			}
			st_best = st_prev;
		}
		reverse(begin(ans), end(ans));
		cout << ans << "\n";
	}
}

// look at my code
// my code is amazing