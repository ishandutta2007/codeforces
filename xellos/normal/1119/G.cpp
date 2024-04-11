#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ff first
#define ss second

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	vector< pair<int, int> > H(M);
	int sum_H = 0;
	for(int i = 0; i < M; i++) {
		cin >> H[i].ff;
		sum_H += H[i].ff;
		H[i].ss = i;
	}
	int T = (sum_H+N-1)/N;
	vector<int> max_div(T*N+1, 0);
	for(int i = 1; i <= T; i++) for(int j = i; j <= T*N; j += i) max_div[j] = i;
	vector<int> sz(M, 0);
	vector< vector<int> > att(T, vector<int>(M, 0));
	int g = 0, f = 0;

	sort(begin(H), end(H));

	bool ignore_mod = false;
	for(int i = 0; i < M; i++) if(H[i].ff <= T && H[i].ff) {
		sz[g] = 1;
		for(int j = 0; j < H[i].ff; j++) att[j][g] = H[i].ss;
		int t = T-H[i].ff;
		H[i].ff = 0;
		for(int j = 0; j < t; j++) {
			if(!ignore_mod)
				while(f < M && (H[f].ff%T == 0 || H[f].ff < T)) f++;
			if(f == M) ignore_mod = true, f = 0;
			if(ignore_mod) while(f < M && H[f].ff == 0) f++;
			att[T-1-j][g] = H[f].ss;
			H[f].ff--;
		}
		g++;
	}

	vector< pair<int, int> > H_by_mod(M);
	for(int i = 0; i < M; i++) H_by_mod[i] = {T-H[i].ff%T, i};
		sort(begin(H_by_mod), end(H_by_mod));
	int D = T*N-sum_H;
	for(int i = 0; i < M; i++) if(D >= H_by_mod[i].ff && H_by_mod[i].ff < T) {
		D -= H_by_mod[i].ff;
		H[H_by_mod[i].ss].ff += H_by_mod[i].ff;
	}
	for(int i = 0; i < M; i++) if(H[i].ff && H[i].ff%T == 0) {
		sz[g] = H[i].ff/T;
		for(int j = 0; j < T; j++) att[j][g] = H[i].ss, H[i].ff -= sz[g];
		g++;
	}
	{
		auto H_old = H;
		H.clear();
		for(int i = 0; i < M; i++) if(H_old[i].ff) H.push_back(H_old[i]);
		f = 0;
		M = H.size();
	}

	for(int i = 0; i < M; i++) if(H[i].ff) {
		int a = H[i].ff / max_div[H[i].ff];
		int bl = 0;
		for(int j = 0; j < M; j++) bl += H[j].ff/a;
		if(bl < T) continue;
		sz[g] = a;
		int t = 0;
		for(int j = 0; j < H[i].ff/a; j++, t++) att[j][g] = H[i].ss;
		H[i].ff = 0;
		for(int j = 0; j < M; j++) while(t < T && H[j].ff >= a) {
			att[t][g] = H[j].ss, H[j].ff -= sz[g];
			t++;
		}
		g++;
	}
	{
		auto H_old = H;
		H.clear();
		for(int i = 0; i < M; i++) if(H_old[i].ff) H.push_back(H_old[i]);
		f = 0;
		M = H.size();
	}

	for(int i = 0; i < M; i++) for(int j = 0; j < M; j++) if(H[i].ff && H[j].ff && i != j) {
		int a = (H[i].ff+H[j].ff+T-1)/T-1;
		if(a == 0) continue;
		int b = H[i].ff/a;
		int c = H[i].ff-b*a;
		for(; b <= T && a*b <= H[i].ff; b++, c -= a) {
			if(c > T || H[j].ff < a*(T-b)) continue;
			if(H[j].ff > T-c+a*(T-b)) break;
			int d = H[j].ff-a*(T-b);
			sz[g] = 1;
			sz[g+1] = a;
			for(int k = 0; k < b; k++) att[k][g+1] = H[i].ss, H[i].ff -= a;
			for(int k = b; k < T; k++) att[k][g+1] = H[j].ss, H[j].ff -= a;
			for(int k = 0; k < c; k++) att[k][g] = H[i].ss, H[i].ff--;
			for(int k = c; k < c+d; k++) att[k][g] = H[j].ss, H[j].ff--;
			for(int k = 0; k < T-c-d; k++) {
				while(f < M && H[f].ff == 0) f++;
				att[T-1-k][g] = H[f].ss;
				H[f].ff--;
			}
			g += 2;
			break;
		}
	}
	{
		auto H_old = H;
		H.clear();
		for(int i = 0; i < M; i++) if(H_old[i].ff) H.push_back(H_old[i]);
		f = 0;
		M = H.size();
	}

	while(g < (int)sz.size()) {
		int a = 1, sum = 0;
		for(int i = 0; i < M; i++) sum += H[i].ff;
		if(sum == 0) break;
		while(true) {
			int b = 0;
			for(int i = 0; i < M; i++) b += H[i].ff/a;
			if(b >= T) a++;
			else break;
		}
		if(a > 1) a--;
		sz[g] = a;
		int t = 0;
		for(int i = 0; i < M; i++) while(H[i].ff >= a && t < T) {
			att[t][g] = H[i].ss;
			H[i].ff -= a;
			t++;
		}
		g++;
	}
	{
		auto H_old = H;
		H.clear();
		for(int i = 0; i < M; i++) if(H_old[i].ff) H.push_back(H_old[i]);
		f = 0;
		M = H.size();
	}

	for(int i = 0; i < (int)sz.size(); i++) N -= sz[i];
	if(N < 0) return 1;
	if(M == 1) {
		sz[g] = N;
		for(int i = 0; i < T; i++) att[i][g] = H[0].ss;
	}
	else if(M == 0) sz[0] += N;
	else return 2;

	M = sz.size();
	cout << T << "\n";
	for(int i = 0; i < M; i++) cout << sz[i] << ((i == M-1) ? "\n" : " ");
	for(int k = 0; k < T; k++)
		for(int i = 0; i < M; i++) cout << att[k][i]+1 << ((i == M-1) ? "\n" : " ");
}