// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

bool is_scc(auto & seq, auto & deg_in, auto & deg_out) {
	int N = seq.size(), dif = 0;
	for(int i = 0; i < N-1; i++) {
		dif += deg_out[seq[i]] - deg_in[seq[i]];
		if(dif == (i+1)*(N-i-1)) return false;
	}
	return true;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector< vector<char> > G(N, vector<char>(N, 0));
	for(int i = 0; i < N; i++) {
		string S;
		cin >> S;
		for(int j = 0; j < N; j++) G[i][j] = S[j]-'0';
	}
	vector<int> seq(N);
	for(int i = 0; i < N; i++) {
		seq[i] = i;
		for(int j = i; j > 0; j--) {
			if(G[seq[j]][seq[j-1]]) swap(seq[j], seq[j-1]);
			else break;
		}
	}
	vector<int> deg_in(N), deg_out(N);
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
		if(G[i][j]) deg_in[j]++, deg_out[i]++;
	if(is_scc(seq, deg_in, deg_out)) {
		cout << "0 1\n";
		return 0;
	}
	if((N == 4 && G[seq[0]][seq[3]] && (G[seq[2]][seq[0]] || G[seq[3]][seq[1]])) || N == 2) {
		cout << "-1\n";
		return 0;
	}
	if(N == 6 && G[seq[2]][seq[0]] && G[seq[5]][seq[3]]) {
		cout << "2 18\n";
		return 0;
	}
	int ans = 0;
	for(int i = 0; i < N; i++) {
		swap(deg_in[i], deg_out[i]);
		for(int j = 0; j < N; j++) if(j != i) {
			if(G[i][j]) deg_in[j]--, deg_out[j]++;
			else deg_in[j]++, deg_out[j]--;
		}
		int pos[2], fin[2];
		for(int j = 0; j < N; j++) if(seq[j] == i) {
			pos[0] = 0, pos[1] = j+1;
			fin[0] = j, fin[1] = N;
			break;
		}
		vector<int> seq_m(N);
		for(int j = 0; j < N-1; j++) {
			if(pos[0] == fin[0]) seq_m[j] = seq[pos[1]++];
			else if(pos[1] == fin[1]) seq_m[j] = seq[pos[0]++];
			else if(G[seq[pos[0]]][seq[pos[1]]]) seq_m[j] = seq[pos[0]++];
			else seq_m[j] = seq[pos[1]++];
		}
		seq_m[N-1] = i;
		for(int j = N-1; j > 0; j--) {
			if(!G[seq_m[j]][seq_m[j-1]]) swap(seq_m[j], seq_m[j-1]);
			else break;
		}
		if(is_scc(seq_m, deg_in, deg_out)) ans++;
		swap(deg_in[i], deg_out[i]);
		for(int j = 0; j < N; j++) if(j != i) {
			if(G[i][j]) deg_in[j]++, deg_out[j]--;
			else deg_in[j]--, deg_out[j]++;
		}
	}
	cout << "1 " << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing