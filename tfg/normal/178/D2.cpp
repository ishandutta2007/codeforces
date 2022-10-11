//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

int n;
int sum = 0;
int a[16];
int mat[4][4];
int rows[4], cols[4];
int gotx[4], goty[4], gotd[2];
int x[16], y[16];
int diag[2];

bool dfs(int state, int mask) {
	//std::cout << "on state " << state << ", mask " << mask << std::endl;
	/*if(state == 0) {
		if(n == 1) {
			mat[0][0] = a[0];
			return true;
		} else if(n == 2) {
			for(int i = 0; i < n * n; i++) {
				if((mask & 1 << i) == 0) continue;
				for(int j = i + 1; j < n * n; j++) {
					if((mask & 1 << j) == 0) continue;
					if(a[i] + a[j] == sum) {
						int nxtMask = mask;
						mat[0][0] = a[i];
						nxtMask ^= 1 << i;
						mat[1][1] = a[j];
						nxtMask ^= 1 << j;
						rows[0] = cols[0] = a[i];
						rows[1] = cols[1] = a[j];
						if(dfs(state + 1, nxtMask)) {
							return true;
						}
					}
				}
			}
		} else if(n == 3) {
			for(int i = 0; i < n * n; i++) {
				if((mask & 1 << i) == 0) continue;
				for(int j = i + 1; j < n * n; j++) {
					if((mask & 1 << j) == 0) continue;
					for(int k = j + 1; k < n * n; k++) {
						if((mask & 1 << k) == 0) continue;
						if(a[i] + a[j] + a[k] == sum) {
							int nxtMask = mask;
							mat[0][0] = a[i];
							nxtMask ^= 1 << i;
							mat[1][1] = a[j];
							nxtMask ^= 1 << j;
							mat[2][2] = a[k];
							nxtMask ^= 1 << k;
							rows[0] = cols[0] = a[i];
							rows[1] = cols[1] = a[j];
							rows[2] = cols[2] = a[k];
							//std::cout << "choosing diagonal (" << i << ", " << j << ", " << k << ")\n";
							if(dfs(state + 1, nxtMask)) {
								return true;
							}
						}
					}
				}
			}
		} else {
			for(int i = 0; i < n * n; i++) {
				if((mask & 1 << i) == 0) continue;
				for(int j = i + 1; j < n * n; j++) {
					if((mask & 1 << j) == 0) continue;
					for(int k = j + 1; k < n * n; k++) {
						if((mask & 1 << k) == 0) continue;
						for(int l = k + 1; l < n * n; l++) {
							if((mask & 1 << l) == 0) continue;
							if(a[i] + a[j] + a[k] + a[l] == sum) {
								int nxtMask = mask;
								mat[0][0] = a[i];
								nxtMask ^= 1 << i;
								mat[1][1] = a[j];
								nxtMask ^= 1 << j;
								mat[2][2] = a[k];
								nxtMask ^= 1 << k;
								mat[3][3] = a[l];
								nxtMask ^= 1 << l;
								rows[0] = cols[0] = a[i];
								rows[1] = cols[1] = a[j];
								rows[2] = cols[2] = a[k];
								rows[3] = cols[3] = a[l];
								if(dfs(state + 1, nxtMask)) {
									return true;
								}
							}
						}
					}
				}
			}
		}
	} else if(state == 2) {
		if(n == 2) {
			for(int i = 0; i < n * n; i++) {
				if((mask & 1 << i) == 0) continue;
				for(int j = 0; j < n * n; j++) {
					if((mask & 1 << j) == 0) continue;
					if(a[i] + a[j] == sum) {
						int nxtMask = mask;
						mat[n][0] = a[i];
						nxtMask ^= 1 << i;
						mat[1][1] = a[j];
						nxtMask ^= 1 << j;
						rows[0] = cols[0] = a[i];
						rows[1] = cols[1] = a[j];
						if(dfs(state + 1, nxtMask)) {
							return true;
						}
					}
				}
			}
		} else if(n == 3) {
			for(int i = 0; i < n * n; i++) {
				if((mask & 1 << i) == 0) continue;
				for(int j = 0; j < n * n; j++) {
					if((mask & 1 << j) == 0) continue;
					for(int k = 0; k < n * n; k++) {
						if((mask & 1 << k) == 0) continue;
						if(a[i] + a[j] + a[k] == sum) {
							int nxtMask = mask;
							mat[0][0] = a[i];
							nxtMask ^= 1 << i;
							mat[1][1] = a[j];
							nxtMask ^= 1 << j;
							mat[2][2] = a[k];
							nxtMask ^= 1 << k;
							rows[0] = cols[0] = a[i];
							rows[1] = cols[1] = a[j];
							rows[2] = cols[2] = a[k];
							//std::cout << "choosing diagonal (" << i << ", " << j << ", " << k << ")\n";
							if(dfs(state + 1, nxtMask)) {
								return true;
							}
						}
					}
				}
			}
		} else {
			for(int i = 0; i < n * n; i++) {
				if((mask & 1 << i) == 0) continue;
				for(int j = 0; j < n * n; j++) {
					if((mask & 1 << j) == 0) continue;
					for(int k = 0; k < n * n; k++) {
						if((mask & 1 << k) == 0) continue;
						for(int l = 0; l < n * n; l++) {
							if((mask & 1 << l) == 0) continue;
							if(a[i] + a[j] + a[k] + a[l] == sum) {
								int nxtMask = mask;
								mat[0][0] = a[i];
								nxtMask ^= 1 << i;
								mat[1][1] = a[j];
								nxtMask ^= 1 << j;
								mat[2][2] = a[k];
								nxtMask ^= 1 << k;
								mat[3][3] = a[l];
								nxtMask ^= 1 << l;
								rows[0] = cols[0] = a[i];
								rows[1] = cols[1] = a[j];
								rows[2] = cols[2] = a[k];
								rows[3] = cols[3] = a[l];
								if(dfs(state + 1, nxtMask)) {
									return true;
								}
							}
						}
					}
				}
			}
		}
	} else if(n == 2 || (state - 1) / (n - 1) == n) {
		//std::cout << "ended " << (state - 1) / (n - 1) << ", " << n << std::endl;
		return true;
	} else {*/
	for(int i = 0; i < 2; i++) {
		if(gotd[i] == n && diag[i] != sum) {
			return false;
		}
	}
	if(state == n * n) return true;
	int row = x[state];
	int col = y[state];
	bool d1 = row == col;
	bool d2 = row + col == n - 1;
	for(int i = 0; i < n * n; i++) {
		if((mask & (1 << i)) != 0 && rows[row] + a[i] <= sum && cols[col] + a[i] <= sum && (!d1 || diag[0] + a[i] <= sum) && (!d2 || diag[1] + a[i] <= sum)) {
			if(gotx[row] + 1 == n && rows[row] + a[i] < sum) {
				continue;
			}
			if(goty[col] + 1 == n && cols[col] + a[i] < sum) {
				continue;
			}
			gotx[row]++;
			goty[col]++;
			rows[row] += a[i];
			cols[col] += a[i];
			if(d1) {
				gotd[0]++;
				diag[0] += a[i];
			}
			if(d2) {
				gotd[1]++;
				diag[1] += a[i];
			}
			if(dfs(state + 1, mask ^ (1 << i))) {
				mat[row][col] = a[i];
				return true;
			}
			gotx[row]--;
			goty[col]--;
			if(d1) {
				gotd[0]--;
				diag[0] -= a[i];
			}
			if(d2) {
				gotd[1]--;
				diag[1] -= a[i];
			}
			rows[row] -= a[i];
			cols[col] -= a[i];
		}
	}
	//}
	return false;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n;
	int mn = 1e9;
	long long ans = 0;
	for(int i = 0; i < n * n; i++) {
		std::cin >> a[i];
		mn = std::min(mn, a[i]);
		ans += a[i];
	}
	std::cout << ans / n << std::endl;
	if(n == 1) {
		std::cout << a[0] << std::endl;
		return 0;
	} else if(n == 2) {
		x[0] = 0;
		x[1] = 1;
		x[2] = 0;
		x[3] = 1;
		y[0] = 0;
		y[1] = 1;
		y[2] = 1;
		y[3] = 0;
	} else if(n == 3) {
		x[0] = 0;
		x[1] = 1;
		x[2] = 2;
		x[3] = 0;
		x[4] = 2;
		x[5] = 0;
		x[6] = 1;
		x[7] = 1;
		x[8] = 2;
		y[0] = 0;
		y[1] = 1;
		y[2] = 2;
		y[3] = 2;
		y[4] = 0;
		y[5] = 1;
		y[6] = 0;
		y[7] = 2;
		y[8] = 1;
	} else if(n == 4) {
		int wtfx[] = {0, 1, 2, 3, 0, 1, 2, 3, 0, 0, 1, 1, 2, 2, 3, 3};
		int wtfy[] = {0, 1, 2, 3, 3, 2, 1, 0, 1, 2, 0, 3, 0, 3, 1, 2};
		for(int i = 0; i < 16; i++) {
			x[i] = wtfx[i];
			y[i] = wtfy[i];
		}
	}
	long long cur = 0;
	for(int i = 0; i < n * n; i++) {
		a[i] -= mn;
		cur += a[i];
		//std::cout << a[i] << (i + 1 == n * n ? '\n' : ' ');
	}
	srand(time(0));
	std::random_shuffle(a, a + n * n);
	sum = cur / n;
	dfs(0, (1 << (n * n)) - 1);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			std::cout << mat[i][j] + mn << (j + 1 == n ? '\n' : ' ');
		}
	}
}