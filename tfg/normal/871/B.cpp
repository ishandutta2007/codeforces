#include <iostream>

int qry(int i, int j) {
	std::cout << "? " << i << ' ' << j << std::endl;
	int ans;
	std::cin >> ans;
	return ans;
}

int q[2][5050];

int f[5050];
int g[5050];
int ans[5050];

int main() {
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		q[0][i] = qry(i, 0);
		q[1][i] = qry(0, i);
	}
	int got = 0;
	for(int i = 0; i < n; i++) {
		f[0] = i;
		for(int j = 0; j < n; j++) {
			g[j] = f[0] ^ q[1][j];
			f[j] = g[0] ^ q[0][j];
		}
		bool valid = true;
		for(int j = 0; j < n; j++) {
			valid = valid && j == f[g[j]];
		}
		if(valid) {
			got++;
			for(int j = 0; j < n; j++) {
				ans[j] = f[j];
			}
		}
	}
	std::cout << '!' << std::endl << got << std::endl;
	for(int i = 0; i < n; i++) {
		if(i) std::cout << ' ';
		std::cout << ans[i];
	}
	std::cout << std::endl;
}