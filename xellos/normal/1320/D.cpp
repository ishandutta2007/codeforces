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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, Q;
	string S;
	cin >> N >> S >> Q;
	vector<int> end1(N, N), start1(N, -1), pref1(N+1, 0);
	for(int i = 0; i < N; i++) pref1[i+1] = pref1[i] + (S[i] == '1');
	for(int i = 0; i < N; i++) if(S[i] == '1') {
		if(!i || S[i-1] != '1') start1[i] = i;
		else start1[i] = start1[i-1];
	}
	for(int i = N-1; i >= 0; i--) if(S[i] == '1') {
		if(i == N-1 || S[i+1] != '1') end1[i] = i;
		else end1[i] = end1[i+1];
	}
	vector< pair< pair<int, int>, int> > seg1o;
	for(int i = 0; i < N; i++) if(!i || S[i-1] == '0') if(S[i] == '1') {
		int j = i;
		while(j < N && S[j] == '1') j++;
		if((j-i)%2) seg1o.push_back({{i, j}, 0});
	}
	int K = seg1o.size();
	for(int i = 0; i < K-1; i++) {
		int n = pref1[seg1o[i+1].ff.ff]-pref1[seg1o[i].ff.ss];
		seg1o[i].ss = seg1o[i+1].ff.ff-seg1o[i].ff.ss-n; // number of 0
	}
	cat mod[3] = {1000000007, 1000000009, 988244353};
	cat p[3] = {999983, 999983, 12345};
	vector<cat> H[3];
	vector<cat> p_pw[3];
	for(int k = 0; k < 3; k++) {
		H[k].resize(K, 0);
		for(int i = 0; i < K-1; i++) H[k][i+1] = (H[k][i] * p[k] + seg1o[i].ss+1) % mod[k];
		p_pw[k].resize(K+1, 1);
		for(int i = 0; i < K; i++) p_pw[k][i+1] = p_pw[k][i] * p[k] % mod[k];
	}
	for(int q = 0; q < Q; q++) {
		int id[2];
		int l;
		cin >> id[0] >> id[1] >> l;
		id[0]--, id[1]--;
		if(pref1[id[0]+l]-pref1[id[0]] != pref1[id[1]+l]-pref1[id[1]]) {
			cout << "NO\n";
			continue;
		}
		if(pref1[id[0]+l]-pref1[id[0]] == l) {
			cout << "YES\n";
			continue;
		}
		int f[2] = {id[0]+l-1, id[1]+l-1};
		int add_start[2] = {-1, -1};
		int add_end[2] = {-1, -1};
		for(int k = 0; k < 2; k++) {
			if(S[id[k]] == '1' && (end1[id[k]]-id[k])%2 == 0) {
				add_start[k] = 0;
				id[k] = end1[id[k]]+1;
			}
			if(S[f[k]] == '1' && (f[k]-start1[f[k]])%2 == 0) {
				add_end[k] = 0;
				f[k] = start1[f[k]]-1;
			}
		}
		int start_id[2] = {-1, -1};
		int end_id[2] = {-1, -1};
		int start_l[2];
		int end_l[2];
		for(int k = 0; k < 2; k++) {
			pair< pair<int, int>, int> pp = {{id[k], 0}, 0};
			auto it = lower_bound(begin(seg1o), end(seg1o), pp);
			if(it != end(seg1o) && it->ff.ss <= f[k]+1) start_id[k] = it-begin(seg1o);
			else continue;
			pp = {{f[k]+1, 0}, 0};
			it = lower_bound(begin(seg1o), end(seg1o), pp);
			if(it == begin(seg1o)) continue;
			it--;
			if(it->ff.ss > f[k]+1) {
				if(it == begin(seg1o)) continue;
				it--;
			}
			end_id[k] = it-begin(seg1o);
			start_l[k] = seg1o[start_id[k]].ff.ff-id[k]-(pref1[seg1o[start_id[k]].ff.ff]-pref1[id[k]]);
			end_l[k] = f[k]+1-seg1o[end_id[k]].ff.ss-(pref1[f[k]+1]-pref1[seg1o[end_id[k]].ff.ss]);
		}
		bool is_eq = true;
		for(int k = 0; k < 3; k++) {
			cat h_cur[2];
			int L[2];
			for(int j = 0; j < 2; j++) {
				if(start_id[j] != -1 && end_id[j] != -1) {
					h_cur[j] = (H[k][end_id[j]] - p_pw[k][end_id[j]-start_id[j]] * H[k][start_id[j]]) % mod[k];
					h_cur[j] = (h_cur[j] * p[k] + end_l[j]+1) % mod[k];
					L[j] = end_id[j]-start_id[j]+1;
					h_cur[j] = (h_cur[j] + p_pw[k][L[j]] * (start_l[j]+1)) % mod[k];
					L[j]++;
				}
				else {
					h_cur[j] = f[j]+1-id[j]-(pref1[f[j]+1]-pref1[id[j]])+1;
					L[j] = 1;
				}
				if(add_start[j] == 0) {
					h_cur[j] = (h_cur[j] + p_pw[k][L[j]]) % mod[k];
					L[j]++;
				}
				if(add_end[j] == 0) {
					h_cur[j] = (h_cur[j] * p[k] + 1) % mod[k];
					L[j]++;
				}
			}
			if(L[0] != L[1] || (h_cur[0]-h_cur[1]) % mod[k] != 0) {
				is_eq = false;
				break;
			}
		}
		if(is_eq) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}

// look at my code
// my code is amazing