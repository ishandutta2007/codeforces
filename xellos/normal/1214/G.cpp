#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ff first
#define ss second

short get_first_dif(vector<uint64_t> & smaller, vector<uint64_t> & larger) {
	for(int i = 0; i < (int)smaller.size(); i++)
		if((smaller[i] & larger[i]) != smaller[i]) return i+1;
	return 0;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N, M, Q, B = 64;
	cin >> N >> M >> Q;
	vector< vector<uint64_t> > X(N, vector<uint64_t>(M/B+1, 0));
	vector< vector<short> > popcount(N, vector<short>(M/B+1, 0));
	vector< pair<short, short> > pop_order(N);
	vector<short> first_dif(N-1, 0);
	for(int i = 0; i < N; i++) pop_order[i] = {0, i};
	for(int q = 0; q < Q; q++) {
		int a, l, r;
		cin >> a >> l >> r;
		a--, l--;
		for(uint64_t x = X[a][l/B]>>(l%B); l%B != 0 && l < r; x >>= 1, l++) {
			if(x&1) popcount[a][l/B] -= 1;
			else popcount[a][l/B] += 1;
			X[a][l/B] ^= 1ULL<<(l%B);
		}
		if(l != r) for(uint64_t x = X[a][(r-1)/B]; r%B != 0 && l < r; r--) {
			if((x>>((r-1)%B))&1) popcount[a][(r-1)/B] -= 1;
			else popcount[a][(r-1)/B] += 1;
			X[a][(r-1)/B] ^= 1ULL<<((r-1)%B);
		}
		for(int i = l/B; i < r/B; i++) {
			X[a][i] = ~X[a][i];
			popcount[a][i] = B-popcount[a][i];
		}
		short pop_new = 0;
		for(int i = 0; i <= M/B; i++) pop_new += popcount[a][i];
		int id = 0;
		while(pop_order[id].ss != a) id++;
		if(pop_new > pop_order[id].ff) {
			int id_new = id+1;
			while(id_new < N && pop_order[id_new].ff < pop_new) id_new++;
			// move [id+1..id_new)
			for(int i = id+1; i < id_new; i++) pop_order[i-1] = pop_order[i];
			for(int i = id+1; i < id_new-1; i++) first_dif[i-1] = first_dif[i];
			pop_order[id_new-1] = {pop_new, a};
			// update first_dif[id-1], first_dif[id_new-1], first_dif[id_new-2]
			if(id_new < N) first_dif[id_new-1] = get_first_dif(X[a], X[pop_order[id_new].ss]);
			if(id_new >= 2) first_dif[id_new-2] = get_first_dif(X[pop_order[id_new-2].ss], X[a]);
			if(id && id_new != id+1) first_dif[id-1] = get_first_dif(X[pop_order[id-1].ss], X[pop_order[id].ss]);
		}
		else if(pop_new < pop_order[id].ff) {
			int id_new = id-1;
			while(id_new >= 0 && pop_order[id_new].ff > pop_new) id_new--;
			// move (id_new..id-1]
			for(int i = id-1; i > id_new; i--) pop_order[i+1] = pop_order[i];
			for(int i = id-2; i > id_new; i--) first_dif[i+1] = first_dif[i];
			pop_order[id_new+1] = {pop_new, a};
			// update first_dif[id], first_dif[id_new], first_dif[id_new+1]
			if(id_new >= 0) first_dif[id_new] = get_first_dif(X[pop_order[id_new].ss], X[a]);
			if(id_new < N-2) first_dif[id_new+1] = get_first_dif(X[a], X[pop_order[id_new+2].ss]);
			if(id < N-1 && id_new != id-1) first_dif[id] = get_first_dif(X[pop_order[id].ss], X[pop_order[id+1].ss]);
		}
		else {
			pop_order[id].ff = pop_new;
			if(id < N-1) first_dif[id] = get_first_dif(X[a], X[pop_order[id+1].ss]);
			if(id) first_dif[id-1] = get_first_dif(X[pop_order[id-1].ss], X[a]);
		}
		bool found = false;
		for(int i = 0; i < N-1; i++) if(first_dif[i]) {
			int r1 = pop_order[i].ss, r2 = pop_order[i+1].ss;
			for(int j = 0; j <= M/B; j++) if((X[r1][j] & X[r2][j]) != X[r2][j]) {
				int c1 = first_dif[i]-1, c2 = j, d1 = 0, d2 = 0;
				while(((X[r1][c1]>>d1)&1) * 2 + ((X[r2][c1]>>d1)&1) != 2) d1++;
				while(((X[r1][c2]>>d2)&1) * 2 + ((X[r2][c2]>>d2)&1) != 1) d2++;
				c1 = c1 * B + d1, c2 = c2 * B + d2;
				if(r1 > r2) swap(r1, r2);
				if(c1 > c2) swap(c1, c2);
				cout << r1+1 << " " << c1+1 << " " << r2+1 << " " << c2+1 << "\n";
				break;
			}
			found = true;
			break;
		}
		if(!found) cout << "-1\n";
	}
}