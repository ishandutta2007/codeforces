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
using uchar = unsigned char;
using cat = long long;
using dbl = long double;
constexpr dbl pi = 3.14159265358979323846;
using namespace std;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

vector< vector<uchar> > M;

bool cmp_v(int v, int w) {
	return M[v][w];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	M.resize(N, vector<uchar>(N, 0));
	vector<int> indeg(N, N-1);
	for(int i = 0; i < N; i++) {
		string S;
		cin >> S;
		for(int j = 0; j < N/4; j++) {
			uchar c = (S[j] <= '9') ? (S[j]-'0') : (S[j]-'A'+10);
			for(int k = 0; k < 4; k++) M[i][4*j+3-k] = (c>>k)&1;
		}
		for(int j = 0; j < N; j++) indeg[i] -= M[i][j];
	}
	cat ans = 0;
	vector<char> live(N, 1);
	int n = N;
	while(true) {
		bool stop = true;
		for(int i = 0; i < N; i++) if(!indeg[i] && live[i]) {
			ans += (614LL*N+1)*(n-1);
			for(int j = 0; j < N; j++) indeg[j] -= M[i][j];
			live[i] = 0;
			stop = false;
			n--;
			break;
		}
		if(stop) break;
	}
	if(n == 0) {
		cout << ans << "\n";
		return 0;
	}
	ans += n * (n-1) / 2;
	vector<int> seq[2];
	seq[0].dibs(n);
	seq[1].dibs(n);
	for(int s = 0; s < 2; s++) while(true) {
		bool stop = true;
		for(int i = 0; i < N; i++) if(live[i]) {
			int id = 0;
			if(!seq[s].empty())
				if(M[i][seq[s][0]] && !M[i][seq[s].back()]) continue;
			while(id < (int)seq[s].size() && !M[i][seq[s][id]]) id++;
			seq[s].insert(begin(seq[s])+id, i);
			live[i] = false;
			stop = false;
		}
		if(stop) break;
	}
	for(int i = 0; i < N; i++) if(live[i]) return -1;
	int dist3 = 0;
	for(int s = 0; s < 2; s++) for(auto v : seq[s]) {
		static vector<int> seq_in[2];
		for(int k = 0; k < 2; k++) {
			seq_in[k].clear();
			for(auto w : seq[k]) if(v != w && !M[v][w])
				seq_in[k].push_back(w);
		}
		static vector<int> seq_in_m;
		seq_in_m.clear();
		merge(begin(seq_in[0]), end(seq_in[0]), begin(seq_in[1]), end(seq_in[1]), back_inserter(seq_in_m), &cmp_v);
		for(int i = 0; i < (int)seq_in_m.size(); i++)
			if(indeg[seq_in_m[i]] == i) dist3++;
	}
	ans += n * (n-1) / 2 * 2 + dist3;
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing