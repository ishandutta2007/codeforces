#include <iostream>
#include <vector>

const int ms = 100100;

int gcd(int a, int b) {
	if(!b) {
		return a;
	} else {
		return gcd(b, a % b);
	}
}

std::vector<int> mat[ms];
int got[ms];

bool gen(int n, int m, int i = 0, int j = 0) {
	if(i == n) {
		return true;
	}
	if(j == m) {
		return gen(n, m, i + 1, 0);
	}
	for(int num = 1; num <= n * m; num++) {
		if(got[num]) {
			continue;
		}
		int adjs[4];
		adjs[0] = num + m;
		adjs[3] = num - m;
		if(num % m == 0) {
			adjs[2] = -1;
			adjs[1] = num - 1;
		} else if(num % m == 1) {
			adjs[2] = -1;
			adjs[1] = num + 1;
		} else {
			adjs[2] = num + 1;
			adjs[1] = num - 1;
		}
		//std::cout << "adjs for " << num << " are ";
		/*for(int k = 0; k < 4; k++) {
			std::cout << adjs[k] << ' ';
		}*/
		//std::cout << '\n';
		bool can = true;
		if(j) {
			for(int k = 0; k < 4; k++) {
				can = can && mat[i].back() != adjs[k];
			}
		}
		if(i) {
			for(int k = 0; k < 4; k++) {
				can = can && mat[i - 1][j] != adjs[k];
			}
		}
		if(can) {
			got[num]++;
			mat[i].push_back(num);
			//std::cout << "trying " << num << "\n";
			if(gen(n, m, i, j + 1)) {
				return true;
			}
			got[num]--;
			mat[i].pop_back();
		}
	}
	return false;
}

int perm[ms];

int main() {
	int n, m;
	std::cin >> n >> m;
	bool change = false;
	if(m > 6 || n > 6) {
		if(n > 6) {
			std::swap(n, m);
			change = true;
		}
		/*int g = 2;
		for(int i = 2; i <= m; i++) {
			if(gcd(i, m + 1) == 1 && (long long) m * i % (m + 1) != 1) {
				g = i;
				break;
			}
		}*/
		if(m % 2 == 0) {
			for(int i = 0; i < m / 2; i++) {
				perm[i] = i * 2 + 1;
				perm[i + m / 2] = i * 2 + 2;
			}
			std::swap(perm[0], perm[1]);
			std::swap(perm[m - 1], perm[m - 2]);
		} else {
			m -= 1;
			for(int i = 0; i < m / 2; i++) {
				perm[i] = i * 2 + 1;
				perm[i + m / 2] = i * 2 + 2;
			}
			std::swap(perm[0], perm[1]);
			std::swap(perm[m - 1], perm[m - 2]);
			m += 1;
			/*perm[m - 5] = m - 4;
			perm[m - 4] = m - 1;
			perm[m - 3] = m;
			perm[m - 2] = m - 3;
			perm[m - 1] = m - 2;*/
			perm[m - 1] = m;
		}
		int tot = 0;
		int start = 0;
		for(int i = 0; i < n; i++) {
			int cur = start;
			start = (start + 1) % m;
			for(int j = 0; j < m; j++) {
				mat[i].push_back(i * m + perm[cur]);
				cur = (cur + 1) % m;
			}
		}
	} else if(!gen(n, m)) {
		std::cout << "NO\n";
		return 0;
	}
	std::cout << "YES\n";
	if(change) {
		for(int j = 0; j < m; j++) {
			for(int i = 0; i < n; i++) {
				int x = (mat[i][j] - 1) / m;
				int y = mat[i][j] - 1 - x * m;
				mat[i][j] = y * n + x + 1;
				std::cout << mat[i][j] << (i + 1 == n ? '\n' : ' ');
			}
		}
	} else {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				std::cout << mat[i][j] << (j + 1 == m ? '\n' : ' ');
			}
		}
	}
}