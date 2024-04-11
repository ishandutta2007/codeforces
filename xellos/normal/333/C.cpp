#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

vector< vector<int> > all_K[5];
vector< vector<int> > all_val[5];

void solve(int x, int d, auto & list) {
	int x_l = x;
	list.push_back(x);
	for(int i = 0, pw = 1; i < d-1; i++) {
		x_l /= 10;
		pw *= 10;
		int x_r = x - x_l * pw;
		vector<int> list_l, list_r;
		solve(x_l, d-i-1, list_l);
		solve(x_r, i+1, list_r);
		for(auto v_l : list_l) for(auto v_r : list_r) {
			list.push_back(v_l+v_r);
			list.push_back((v_l > v_r) ? (v_l-v_r) : (v_r-v_l));
			list.push_back(v_l * v_r);
		}
	}
	sort(begin(list), end(list));
	auto it = unique(begin(list), end(list));
	list.resize(it-begin(list));
}

uint64_t * found;

void search(int K, int M) {
	int found_cnt = 0;
	for(int j = 0; j < 10000; j++) {
		if(K+j >= 10000) continue;
		vector<int> ans_l = all_val[4][K+j];
		vector<int> ans_r = all_val[4][j];
		for(auto v_l : ans_l) for(auto v_r : ans_r) {
			int x = v_l*10000+v_r;
			if((found[x/64]>>(x&63))&1) continue;
			found[x/64] |= 1ULL<<(x&63);
			found_cnt++;
		}
		if(found_cnt >= M) break;
	}
	for(int j = 0; j < 10000; j++) {
		if(j-K >= 10000 || K-j >= 10000) continue;
		vector<int> ans_l = all_val[4][(j > K) ? (j-K) : (K-j)];
		vector<int> ans_r = all_val[4][j];
		for(auto v_l : ans_l) for(auto v_r : ans_r) {
			int x = v_l*10000+v_r;
			if((found[x/64]>>(x&63))&1) continue;
			found[x/64] |= 1ULL<<(x&63);
			found_cnt++;
		}
		if(found_cnt >= M) break;
	}
	for(int j = 1; j < 10000; j++) if(K%j == 0) {
		if(K/j >= 10000) continue;
		vector<int> ans_l = all_val[4][K/j];
		vector<int> ans_r = all_val[4][j];
		for(auto v_l : ans_l) for(auto v_r : ans_r) {
			int x = v_l*10000+v_r;
			if((found[x/64]>>(x&63))&1) continue;
			found[x/64] |= 1ULL<<(x&63);
			found_cnt++;
		}
		if(found_cnt >= M) break;
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	for(int j = 1; j <= 4; j++) {
		int mx = 1;
		for(int i = 0; i < j; i++) mx *= 10;
		all_K[j].resize(mx);
		all_val[j].resize(mx);
		for(int i = 0; i < mx; i++) {
			solve(i, j, all_K[j][i]);
			for(auto k : all_K[j][i]) all_val[j][k].push_back(i);
		}
	}

	found = new uint64_t[100000000/64];
	memset(found, 0, 100000000/8);

	int K, M;
	cin >> K >> M;
	vector<int> ans;
	if(K == 0) for(int i = 0; i < M; i++) found[i/64] |= 1ULL<<(i&63);
	else search(K, M);
	for(int i = 0; i < 100000000/64; i++) if(found[i]) {
		for(int j = 0; j < 64; j++) if((found[i]>>j)&1) ans.push_back(i*64+j);
		if((int)ans.size() >= M) break;
	}
	if((int)ans.size() < M) return 1;
	ans.resize(M);

	int pw[8] = {10000000, 1000000, 100000, 10000, 1000, 100, 10, 1};
	for(int i = 0; i < (int)ans.size(); i++) {
		for(int j = 0; j < 8; j++) cout << (ans[i]/pw[j])%10;
		cout << "\n";
	}

	delete[] found;
}