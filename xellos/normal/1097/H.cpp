#include <iostream>
#include <vector>
using namespace std;

using cat = long long;

int D, M;
vector<int> gen;

cat cnt[80][20][20][8];

void solve_cnt() {
	vector< vector<cat> > cnt_sum(81, vector<cat>(M, 0));
	cnt_sum[0][0] = 1;
	for(int i = 0; i < 80; i++)
		for(int j = 0; j < M; j++)
			for(int k = 0; k < D; k++)
				cnt_sum[i+1][(j+gen[k])%M] += cnt_sum[i][j];
	for(int i = 0; i < 80; i++)
		for(int j = 0; j < M; j++)
			for(int k = 0; k < D; k++)
				cnt[i][k][((j+gen[k])%M)/3][1<<((j+gen[k])%M%3)] = cnt_sum[i][j];
	for(int i = 0; i < 80; i++) for(int k = 0; k < D; k++) for(int j = 0; j < 20; j++) {
		cnt[i][k][j][3] = cnt[i][k][j][1] + cnt[i][k][j][2];
		cnt[i][k][j][5] = cnt[i][k][j][1] + cnt[i][k][j][4];
		cnt[i][k][j][6] = cnt[i][k][j][2] + cnt[i][k][j][4];
		cnt[i][k][j][7] = cnt[i][k][j][1] + cnt[i][k][j][2] + cnt[i][k][j][4];
	}
	for(int i = 0; i < 80; i++) for(int j = 0; j < 20*8; j++)
		for(int k = 1; k < D; k++) cnt[i][k][j/8][j%8] += cnt[i][k-1][j/8][j%8];
}

vector<cat> masks_pos[80][20];
vector<cat> masks_neg[80][20];
cat ans = 0;

constexpr int L_masks = 100;

cat __attribute__((optimize("Ofast,unroll-loops"))) fast_inner_loop(const cat * __restrict masks_ptr, const cat * __restrict cnt_ptr) {
	cat ret = 0;
	for(int l = 0; l < L_masks; l++, masks_ptr++) {
		cat m = *masks_ptr;
		for(const cat * __restrict p = cnt_ptr; m;) {
			ret += p[m&7];
			p += 8;
			m >>= 3;
			ret += p[m&7];
			p += 8;
			m >>= 3;
			ret += p[m&7];
			p += 8;
			m >>= 3;
			ret += p[m&7];
			p += 8;
			m >>= 3;
		}
	}
	return ret;
}

void solve_leaf(cat A_mask, cat Xl, cat Xr) {
	static vector<char> Vl;
	Vl.clear();
	static vector<char> Vr;
	Vr.clear();
	while(Xl) {
		Vl.push_back(Xl%D);
		Xl /= D;
	}
	while(Xr) {
		Vr.push_back(Xr%D);
		Xr /= D;
	}
	while(!Vl.empty() && !Vr.empty() && Vl.size() == Vr.size() && Vl.back() == Vr.back()) {
		int s = gen[Vl.back()];
		A_mask = (A_mask >> s) | ((A_mask & ((1LL<<s)-1)) << (M-s));
		Vl.pop_back();
		Vr.pop_back();
	}
	for(int i = (int)Vr.size()-1, s = 0; i >= 0; i--) {
		cat mask = (A_mask >> s) | ((A_mask & ((1LL<<s)-1)) << (M-s));
		if(mask && Vr[i]) {
			masks_pos[i][Vr[i]-1].push_back(mask);
			if((int)masks_pos[i][Vr[i]-1].size() == L_masks) {
				cat * cnt_ptr = &(cnt[i][Vr[i]-1][0][0]);
				const cat * masks_ptr = masks_pos[i][Vr[i]-1].data();
				ans += fast_inner_loop(masks_ptr, cnt_ptr);
				masks_pos[i][Vr[i]-1].clear();
			}
		}
		s += gen[Vr[i]];
		if(s >= M) s -= M;
	}
	for(int i = (int)Vl.size()-1, s = 0; i >= 0; i--) {
		cat mask = (A_mask >> s) | ((A_mask & ((1LL<<s)-1)) << (M-s));
		if(mask && Vl[i]) {
			masks_neg[i][Vl[i]-1].push_back(mask);
			if((int)masks_neg[i][Vl[i]-1].size() == L_masks) {
				cat * cnt_ptr = &(cnt[i][Vl[i]-1][0][0]);
				const cat * masks_ptr = masks_neg[i][Vl[i]-1].data();
				ans -= fast_inner_loop(masks_ptr, cnt_ptr);
				masks_neg[i][Vl[i]-1].clear();
			}
		}
		s += gen[Vl[i]];
		if(s >= M) s -= M;
	}
}

void solve_recursive(vector<cat> & A_mask, cat Xl, cat Xr) {
	int N = A_mask.size();
	// number of indices (i < Xr) minus (i < Xl): A[i+j] in A_mask[j]
	for(int i = 0; i < D; i++) { // i%D
		if(Xr-1-i < 0) break;
		vector<cat> A_mask_new;
		A_mask_new.reserve(A_mask.size()/D+2);
		for(int j = 0, k = i, l = 0; j < N; j++, k++) {
			if(A_mask[j] == 0) return;
			if(k == D) k = 0, l++;
			int g = gen[k];
			cat mask_new = (A_mask[j] >> g) | ((A_mask[j] & ((1LL<<g)-1)) << (M-g));
			if((int)A_mask_new.size() == l) A_mask_new.push_back((1LL<<M)-1);
			A_mask_new[l] &= mask_new;
		}
		if(A_mask_new.size() == 1) solve_leaf(A_mask_new[0], (Xl-1-i >= 0) ? (Xl-1-i)/D+1 : 0, (Xr-1-i)/D+1);
		else solve_recursive(A_mask_new, (Xl-1-i >= 0) ? (Xl-1-i)/D+1 : 0, (Xr-1-i)/D+1);
	}
}

void solve(vector<int> & B, cat Xl, cat Xr) {
	int N = B.size();
	// number of indices (i < Xr) minus (i < Xl): A[i..i+N-1] <= B[0..N-1]
	vector<cat> A_mask(N);
	for(int i = 0; i < N; i++) A_mask[i] = (1LL<<(B[i]+1))-1;
	if(N == 1) solve_leaf(A_mask[0], Xl, Xr);
	else solve_recursive(A_mask, Xl, Xr);
}

int main() {
	cin.sync_with_stdio(0);
	cin >> D >> M;
	gen.resize(D);
	for(int i = 0; i < D; i++) cin >> gen[i];
	solve_cnt();
	int N;
	cin >> N;
	vector<int> B(N);
	for(int i = 0; i < N; i++) cin >> B[i];
	cat L, R;
	cin >> L >> R;
	L--, R--;
	solve(B, L, R-N+2);
	for(int i = 0; i < 80; i++) for(int j = 0; j < D; j++) {
		masks_pos[i][j].resize(L_masks, 0);
		ans += fast_inner_loop(masks_pos[i][j].data(), &(cnt[i][j][0][0]));
	}
	for(int i = 0; i < 80; i++) for(int j = 0; j < D; j++) {
		masks_neg[i][j].resize(L_masks, 0);
		ans -= fast_inner_loop(masks_neg[i][j].data(), &(cnt[i][j][0][0]));
	}
	cout << ans << "\n";
}