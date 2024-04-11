#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		int R, C, K;
		cin >> R >> C >> K;
		vector<string> S(R);
		int rice = 0;
		for(int i = 0; i < R; i++) {
			cin >> S[i];
			for(int j = 0; j < C; j++) if(S[i][j] == 'R') rice++;
		}
		int cur_r = 0, cur_c = 0, dir = 1;
		for(int k = 0; k < K; k++) {
			char c = 'a' + k;
			if(k >= 26) c = 'A' + (k-26);
			if(k >= 52) c = '0' + (k-52);
			int cur_val = rice / K + (k < rice%K);
			while(cur_val || k == K-1) {
				if(S[cur_r][cur_c] == 'R') cur_val--;
				S[cur_r][cur_c] = c;
				cur_c += dir;
				if(cur_c == -1) {
					if(cur_r == R-1) break;
					cur_c = 0;
					cur_r++;
					dir *= -1;
				}
				if(cur_c == C) {
					if(cur_r == R-1) break;
					cur_c = C-1;
					cur_r++;
					dir *= -1;
				}
			}
		}
		for(int i = 0; i < R; i++) cout << S[i] << "\n";
	}
}