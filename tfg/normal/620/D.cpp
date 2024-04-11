#include <iostream>
#include <vector>
#include <algorithm>

long long abss(long long x) {
	return std::max(x, -x);
}

long long cur;
long long ans[3] = {0, -1, -1};
long long sum[2] = {0, 0};

void solve(std::vector<long long> &a, std::vector<long long> &b, int idx) {
	if(idx == 1) {
		for(int i = 0; i < a.size(); i++) {
			for(int j = 0; j < b.size(); j++) {
				long long cur_sum = abss(sum[0] - sum[1] - 2LL * ((long long)a[i] - b[j]));
				if(cur_sum < cur) {
					cur = cur_sum;
					ans[0] = idx;
					ans[1] = i;
					ans[2] = j;
				}
			}
		}
	} else {
		for(int i = 0, j = 0; i < a.size(); i++) {
			while(j < b.size() && sum[0] - sum[1] + 2LL * ((long long) -a[i] + b[j]) < 0) {
				//std::cout << "was " << sum[0] - sum[1] - 2LL * ((long long) a[i] - b[j]) << std::endl;
				j++;
			}
			while(j > 0 && sum[0] - sum[1] + 2LL * ((long long) -a[i] + b[j - 1]) > 0) {
				j--;
			}
			//std::cout << "is " << sum[0] - sum[1] - 2LL * ((long long) a[i] - b[j]) << std::endl;
			if(j < b.size()) {
				long long cur_sum = abss(sum[0] - sum[1] - 2LL * ((long long)a[i] - b[j]));
				if(cur_sum < cur) {
					cur = cur_sum;
					ans[0] = idx;
					ans[1] = a[i];
					ans[2] = b[j];
				}
			}
			if(j - 1 >= 0 && j - 1 < b.size()) {
				j--;
				long long cur_sum = abss(sum[0] - sum[1] - 2LL * ((long long)a[i] - b[j]));
				if(cur_sum < cur) {
					cur = cur_sum;
					ans[0] = idx;
					ans[1] = a[i];
					ans[2] = b[j];
				}
				j++;
			}
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int sizes[2];
	std::vector<long long> vecs[2];
	std::vector<long long> pairs[2];
	for(int j = 0; j < 2; j++) {
		std::cin >> sizes[j];
		vecs[j].resize(sizes[j]);
		pairs[j].resize(sizes[j] * (sizes[j] - 1) / 2);
		for(int i = 0; i < sizes[j]; i++) {
			std::cin >> vecs[j][i];
			sum[j] += vecs[j][i];
		}
		int lul = 0;
		for(int i = 0; i < sizes[j]; i++) {
			for(int k = i + 1; k < sizes[j]; k++) {
				pairs[j][lul++] = vecs[j][i] + vecs[j][k];
			}
		}
		std::sort(pairs[j].begin(), pairs[j].end());
	}
	cur = abss(sum[0] - sum[1]);
	solve(vecs[0], vecs[1], 1);
	solve(pairs[0], pairs[1], 2);
	std::cout << cur << std::endl;
	std::cout << ans[0] << std::endl;
	if(ans[0] == 1) {
		std::cout << ans[1] + 1 << ' ' << ans[2] + 1 << std::endl;
	} else if(ans[0] == 2) {
		int pos[2] = {-1, -1};
		for(int i = 0; i < sizes[0] && pos[0] == -1; i++) {
			for(int j = i + 1; j < sizes[0]; j++) {
				if(vecs[0][i] + vecs[0][j] == ans[1]) {
					pos[0] = i;
					pos[1] = j;
					break;
				}
			}
		}
		for(int i = 0; i < sizes[1]; i++) {
			for(int j = i + 1; j < sizes[1]; j++) {
				if(vecs[1][i] + vecs[1][j] == ans[2]) {
					std::cout << pos[0] + 1 << ' ' << i + 1 << std::endl;
					std::cout << pos[1] + 1 << ' ' << j + 1 << std::endl;
					i = sizes[1];
					break;
				}
			}
		}
	}
}