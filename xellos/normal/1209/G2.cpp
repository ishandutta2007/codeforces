#include <iostream>
#include <iomanip>
#include <vector>
#include <cstring>
using namespace std;

struct block {
	int l, r, mx;
};

struct occ_str {
	int l, r, sz;
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N, Q, B = 200, MX = 200000;
	cin >> N >> Q;
	vector<int> A(N);
	vector<occ_str> occ(MX+1, {0, 0, 0});
	for(int i = 0; i < N; i++) {
		A[i] = rand()%MX+1;
		cin >> A[i];
		occ[A[i]].r = i;
		if(occ[A[i]].sz == 0) occ[A[i]].l = i;
		occ[A[i]].sz++;
	}
	int ans_init = 0;
	for(int i = 0, r = 0, mx_occ = 0; i <= N; i++) {
		if(r < i) {
			ans_init += mx_occ;
			mx_occ = 0;
			r = i;
			if(i == N) break;
		}
		r = max(r, occ[A[i]].r);
		mx_occ = max(mx_occ, occ[A[i]].sz);
	}
	cout << N-ans_init << "\n";
	for(int q = 0; q < Q; q += B) {
		static auto U = vector< pair<int, int> >(B);
		static auto is_upd = vector<char>(N, 0);
		for(int i = 0; i < min(Q-q, B); i++) {
			U[i].first = rand()%N+1;
			U[i].second = rand()%MX+1;
			cin >> U[i].first >> U[i].second;
			is_upd[--U[i].first] = 1;
		}
		vector<int> upd_ids;
		static auto next_upd_id = vector<int>(N);
		for(int i = 0; i < N; i++) {
			if(is_upd[i]) {
				next_upd_id[i] = upd_ids.size();
				upd_ids.push_back(i);
			}
			else next_upd_id[i] = N;
		}
		for(int i = N-2; i >= 0; i--) next_upd_id[i] = min(next_upd_id[i], next_upd_id[i+1]);
		memset(occ.data(), 0, sizeof(occ_str)*(MX+1));
		for(int i = 0; i < N; i++) if(!is_upd[i]) {
			occ[A[i]].r = i;
			if(occ[A[i]].sz == 0) occ[A[i]].l = i;
			occ[A[i]].sz++;
		}
		static auto blocks = vector<block>();
		blocks.clear();
		static auto block_id = vector<int>(N);
		static auto block_id_val = vector<int>(MX+1);
		ans_init = 0;
		for(int i = 0, l = 0, r = 0, mx_occ = 0; i <= N; i++) {
			if(r < i) {
				for(int j = l; j <= r; j++) {
					block_id[j] = blocks.size();
					if(!is_upd[j]) block_id_val[A[j]] = blocks.size();
				}
				blocks.push_back({l, r, mx_occ});
				ans_init += mx_occ;
				mx_occ = 0;
				l = r = i;
			}
			if(i == N) break;
			if(is_upd[i]) {
				if(r == i) {
					block_id[i] = blocks.size();
					blocks.push_back({i, i, 0});
					l++, r++;
				}
				continue;
			}
			r = max(r, occ[A[i]].r);
			mx_occ = max(mx_occ, occ[A[i]].sz);
		}
		static vector<int> mx_sum;
		mx_sum.resize(blocks.size()+1, 0);
		for(int i = 0; i < (int)blocks.size(); i++) mx_sum[i+1] = mx_sum[i] + blocks[i].mx;
		vector<int> mx_next_gt(blocks.size(), N);
		static vector<int> st;
		for(int i = 0; i < (int)blocks.size(); i++) {
			while(!st.empty() && blocks[st.back()].mx < blocks[i].mx) {
				mx_next_gt[st.back()] = i;
				st.pop_back();
			}
			st.push_back(i);
		}
		while(!st.empty()) st.pop_back();
		vector<int> max_between(upd_ids.size(), 0);
		for(int i = 0; i < (int)upd_ids.size()-1; i++)
			for(int j = block_id[upd_ids[i]]; j < block_id[upd_ids[i+1]]; j++)
				max_between[i] = max(max_between[i], blocks[j].mx);
		static auto max_right = vector<int>(N+1, 0);
		for(int i = block_id[upd_ids.back()], a = (int)upd_ids.size()-1; i >= 0; i--) {
			while(a > 0 && block_id[upd_ids[a-1]] >= i) a--;
			if(i == block_id[upd_ids[a]]) max_right[i] = blocks[i].mx;
			else max_right[i] = max(max_right[i+1], blocks[i].mx);
		}
		static auto occ_upd = vector<occ_str>(MX+1, {0, 0, 0});
		for(int k = 0; k < min(Q-q, B); k++) {
			A[U[k].first] = U[k].second;
			for(auto x : upd_ids) {
				occ_upd[A[x]].r = x;
				occ_upd[A[x]].sz++;
			}
			int ans = ans_init;
			static auto r_jmp = vector<int>(B);
			for(int i = 0; i < (int)upd_ids.size(); i++) {
				r_jmp[i] = i;
				int a = A[upd_ids[i]];
				if(occ[a].sz && occ[a].l < upd_ids[i]) {
					int id = next_upd_id[blocks[block_id_val[a]].l];
					r_jmp[id] = max(r_jmp[id], i);
				}
			}
			int l_bl = block_id[upd_ids[0]], r_bl = block_id[upd_ids[0]];
			for(int i = 0, l = 0, r = 0, mx = 0; i <= (int)upd_ids.size(); i++) {
				if(r < i) {
					ans -= mx_sum[r_bl+1] - mx_sum[l_bl];
					for(int j = l; j < r; j++) mx = max(mx, max_between[j]);
					if(l_bl < block_id[upd_ids[l]]) mx = max(mx, max_right[l_bl]);
					for(int j = block_id[upd_ids[r]]; j <= r_bl; j++) {
						mx = max(mx, blocks[j].mx);
						j = mx_next_gt[j];
						j--;
					}
					ans += mx;
					l = r = i;
					mx = 0;
					if(i == (int)upd_ids.size()) break;
					l_bl = r_bl = block_id[upd_ids[i]];
				}
				r = max(r, r_jmp[i]);
				int a = A[upd_ids[i]];
				r_bl = max(r_bl, block_id[occ_upd[a].r]);
				if(occ[a].sz) {
					l_bl = min(l_bl, block_id_val[a]);
					r_bl = max(r_bl, block_id_val[a]);
					mx = max(mx, blocks[block_id_val[a]].mx);
				}
				while(r+1 < (int)upd_ids.size() && upd_ids[r+1] <= blocks[r_bl].r) r++;
				mx = max(mx, (int)occ_upd[a].sz+occ[a].sz);
				mx = max(mx, blocks[block_id[upd_ids[i]]].mx);
			}
			cout << N-ans << "\n";
			for(auto x : upd_ids) occ_upd[A[x]].sz = 0;
		}
		for(int i = 0; i < min(Q-q, B); i++) is_upd[U[i].first] = 0;
	}
}