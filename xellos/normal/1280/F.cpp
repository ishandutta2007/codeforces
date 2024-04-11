#include <iostream>
using namespace std;

int A[2][60];
int G[2][60];
int K;
string ans;

int goal_pos(int x) {
	int pos = 0;
	while(G[pos/(2*K+1)][pos%(2*K+1)] != x) pos++;
	return pos;
}

void rot_lc() {
	for(int i = K-1; i >= 0; i--) A[0][i+1] = A[0][i];
	A[0][0] = A[1][0];
	for(int i = 0; i < K; i++) A[1][i] = A[1][i+1];
	A[1][K] = A[0][K];
	A[0][K] = -1;
}

void rot_rc() {
	for(int i = 0; i < K; i++) A[0][K+i] = A[0][K+i+1];
	A[0][2*K] = A[1][2*K];
	for(int i = K-1; i >= 0; i--) A[1][K+i+1] = A[1][K+i];
	A[1][K] = A[0][K];
	A[0][K] = -1;
}

void swap_pairs(auto pl, auto pr) {
	if(pl.first > K && pl.second < K) swap(pl.first, pl.second);
	if(pl.first < pl.second && pl.second < K) swap(pl.first, pl.second);
	if(pl.first > pl.second && pl.second >= K) swap(pl.first, pl.second);
	int a = A[pl.first/K][pl.first%K], b = A[pl.second/K][pl.second%K];
	int c = A[pr.first/K][K+1+pr.first%K], d = A[pr.second/K][K+1+pr.second%K];
	int e = A[1][K];
	for(int k = 0; k < 3; k++) {
		while(A[1][K] != c) {
			rot_rc();
			ans += 'Y';
		}
		while(A[1][K] != a) {
			rot_lc();
			ans += 'X';
		}
		while(A[1][K] != e) {
			rot_rc();
			ans += 'Y';
		}
		while(A[1][K] != c) {
			rot_lc();
			ans += 'X';
		}
		while(A[1][K] != a) {
			rot_rc();
			ans += 'Y';
		}
		while(A[1][K] != e) {
			rot_lc();
			ans += 'X';
		}
		swap(a, b);
		swap(c, d);
	}
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		cin >> K;
		string Rl = "", Rr = "";
		for(int i = 0; i < K; i++) Rl += 'l';
		Rl += 'd';
		for(int i = 0; i < K; i++) Rl += 'r';
		Rl += 'u';
		for(int i = 0; i < K; i++) Rr += 'r';
		Rr += 'd';
		for(int i = 0; i < K; i++) Rr += 'l';
		Rr += 'u';
		int e_pos;
		for(int i = 0; i < 4*K+2; i++) {
			string s;
			cin >> s;
			if(s == "E") {
				e_pos = i;
				A[i/(2*K+1)][i%(2*K+1)] = -1;
			}
			else {
				int x = s[0]-'0';
				if(s.length() == 2U) x = 10*x + s[1]-'0';
				A[i/(2*K+1)][i%(2*K+1)] = x-1;
			}
		}
		ans = "";
		while(A[0][K] != -1) {
			if(e_pos > 2*K+1) {
				ans += 'l';
				A[1][e_pos-2*K-1] = A[1][e_pos-2*K-2];
				A[1][e_pos-2*K-2] = -1;
				e_pos--;
			}
			else if(e_pos == 2*K+1) {
				ans += 'u';
				A[1][0] = A[0][0];
				A[0][0] = -1;
				e_pos = 0;
			}
			else if(e_pos > K) {
				ans += 'l';
				A[0][e_pos] = A[0][e_pos-1];
				A[0][--e_pos] = -1;
			}
			else {
				ans += 'r';
				A[0][e_pos] = A[0][e_pos+1];
				A[0][++e_pos] = -1;
			}
		}
		for(int i = 0; i < K; i++) G[0][i] = i;
		for(int i = 0; i < K; i++) G[0][i+K+1] = K+i;
		for(int i = 0; i < 2*K; i++) G[1][i] = 2*K+1+i;
		G[1][2*K] = 2*K;
		G[0][K] = -1;
		while(true) {
			if(int p = goal_pos(A[1][K])%(2*K+1); p < K)
				while(goal_pos(A[1][K])%(2*K+1) < K) {
					rot_lc();
					ans += 'X';
				}
			else if(p > K)
				while(goal_pos(A[1][K])%(2*K+1) > K) {
					rot_rc();
					ans += 'Y';
				}
			else {
				bool stop = true;
				for(int i = 0; i < 2*K; i++) if(goal_pos(A[i/K][i%K])%(2*K+1) > K) {
					int x = A[i/K][i%K];
					while(A[1][K] != x) {
						rot_lc();
						ans += 'X';
					}
					stop = false;
					break;
				}
				if(stop) break;
			}
		}
		while(true) {
			pair<int, int> pl = {0, 1}, pr = {0, 1};
			int cl = 0, cr = 0;
			for(int i = 0; i < 2*K; i++) if(A[i/K][i%K] != G[i/K][i%K]) {
				cl++;
				for(int j = 0; j < 2*K; j++) if(A[j/K][j%K] == G[i/K][i%K])
					pl = {i, j};
			}
			for(int i = 0; i < 2*K; i++) if(A[i/K][K+1+i%K] != G[i/K][K+1+i%K]) {
				cr++;
				for(int j = 0; j < 2*K; j++) if(A[j/K][K+1+j%K] == G[i/K][K+1+i%K])
					pr = {i, j};
			}
			if(cl == 0 && cr == 0) break;
			if(cl == 0 && cr == 2) break;
			if(cl == 2 && cr == 0) break;
			swap_pairs(pl, pr);
		}
		bool ok = true;
		for(int i = 0; i < 2; i++) for(int j = 0; j < 2*K+1; j++) if(A[i][j] != G[i][j]) {
			ok = false;
			break;
		}
		if(!ok) {
			cout << "SURGERY FAILED\n";
			continue;
		}
		for(int i = 0; i < K; i++) ans += 'r';
		ans += 'd';
		cout << "SURGERY COMPLETE\n" << ans << "\nX " << Rl << "\nY " << Rr << "\nDONE\n";
	}
}