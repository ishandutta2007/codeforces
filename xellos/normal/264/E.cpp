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

class IntervalTree {
	struct node {
		int max_L;
	};

	int b;
	vector<node> T;

public:
	IntervalTree(int N) {
		b = 1;
		while(b < N) b *= 2;
		T.resize(2*b+10, {0});
	}

	void set_max_L(int pos, int val, int cur = 1, int l = 0, int r = 0) {
		if(cur == 1) r = b;
		if(l == pos && r == pos+1) {
			T[cur].max_L = val;
			return;
		}
		if(pos < (l+r)/2) set_max_L(pos, val, 2*cur, l, (l+r)/2);
		else set_max_L(pos, val, 2*cur+1, (l+r)/2, r);
		T[cur].max_L = max(T[2*cur].max_L, T[2*cur+1].max_L);
	}

	int get_max_L(int I_l, int I_r, int cur = 1, int l = 0, int r = 0) {
		if(cur == 1) r = b;
		I_r = min(I_r, r);
		I_l = max(I_l, l);
		if(I_r <= l || r <= I_l) return 0;
		if(l == I_l && r == I_r) return T[cur].max_L;
		int val_l = get_max_L(I_l, I_r, 2*cur, l, (l+r)/2);
		int val_r = get_max_L(I_l, I_r, 2*cur+1, (l+r)/2, r);
		return max(val_l, val_r);
	}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, M;
	cin >> N >> M;
	set<int> ids;
	vector<int> H(N, OVER9000);
	vector< pair<int, int> > upd;
	IntervalTree I_pos(N), I_val(M+20);
	for(int i = 0; i < M; i++) {
		int type, pos;
		cin >> type >> pos;
		if(type == 1) {
			int h;
			cin >> h;
			vector< pair<int, int> > to_upd;
			for(int j = 0; j < min(h+1, (int)upd.size()); j++)
				if(H[upd[upd.size()-1-j].ss] < h+M-i)
					to_upd.push_back(upd[upd.size()-1-j]);
			h += M-i;
			H[--pos] = h;
			to_upd.push_back({h, pos});
			upd.push_back({h, pos});
			ids.insert(pos);
			// update
			sort(begin(to_upd), end(to_upd));
			reverse(begin(to_upd), end(to_upd));
			for(auto & p : to_upd) I_pos.set_max_L(p.ss, 0);
			for(auto p : to_upd) {
				int max_L = I_pos.get_max_L(p.ss+1, N) + 1;
				I_pos.set_max_L(p.ss, max_L);
				I_val.set_max_L(p.ff, max_L);
			}
		}
		else {
			auto it = begin(ids);
			vector< pair<int, int> > to_upd;
			for(int j = 0; j < pos-1; j++) {
				if(H[*it] != OVER9000) to_upd.push_back({H[*it], *it});
				it++;
			}
			I_val.set_max_L(H[*it], 0);
			I_pos.set_max_L(*it, 0);
			H[*it] = OVER9000;
			ids.erase(it);
			// update
			reverse(begin(to_upd), end(to_upd));
			for(auto p : to_upd) I_val.set_max_L(p.ff, 0);
			for(auto p : to_upd) {
				int max_L = I_val.get_max_L(p.ff+1, M+20) + 1;
				I_pos.set_max_L(p.ss, max_L);
				I_val.set_max_L(p.ff, max_L);
			}
		}
		cout << I_pos.get_max_L(0, N) << "\n";
	}
	return 0;
}

// look at my code
// my code is amazing