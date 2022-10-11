#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false);std::cin.tie(NULL);
	int n, m, k;
	std::cin >> n >> m >> k;
	std::vector<std::vector<int>> mat(n, std::vector<int>(m, 0));
	for(int id = 1; id <= k; id++) {
		int x, y;
		std::cin >> x >> y;
		x--;y--;
		mat[x][y] = 1;
		bool got = false;
		for(int i = 0; i < 2; i++) {
			for(int j = 0; j < 2; j++) {
				if(x + i <= 0 || j + y <= 0 || x + i >= n || y + j >= m) {
					continue;
				}
				int sum = mat[x+i][y+j] + mat[x+i-1][y+j] + mat[x+i][y+j-1] + mat[x+i-1][y+j-1];
				got = got || sum == 4;
			}
		}
		if(got) {
			std::cout << id << std::endl;
			return 0;
		}
	}
	std::cout << "0\n";
}