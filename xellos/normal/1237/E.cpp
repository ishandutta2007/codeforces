#include <iostream>
#include <cstring>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	int cnt[100][4];
	int r[100][4];
	memset(cnt, 0, 400*sizeof(int));
	cnt[0][0] = 1, cnt[0][1] = 2;
	r[0][0] = 0;
	r[0][1] = 1;
	for(int d = 1; d < 100; d++) for(int k = 0; k < 4; k++) {
		for(int i = 0; i < 2; i++) for(int j = 0; j < 2; j++) {
			if(!cnt[d-1][(k&1)+2*i]) continue;
			if(!cnt[d-1][j+2*(k/2)]) continue;
			if((cnt[d-1][(k&1)+2*i]-r[d-1][(k&1)+2*i])%2 == 0) continue;
			if(r[d-1][j+2*(k/2)]%2 == 0) continue;
			r[d][k] = cnt[d-1][(k&1)+2*i];
			cnt[d][k] = cnt[d-1][(k&1)+2*i] + cnt[d-1][j+2*(k/2)] + 1;
		}
	}
	int B = 1, D = 0;
	while(B+(2<<D) <= N) {
		B += 2<<D;
		D++;
	}
	int ans = 0;
	for(int k = 0; k < 4; k++) if(cnt[D][k] == N) ans++;
	cout << ans << "\n";
}