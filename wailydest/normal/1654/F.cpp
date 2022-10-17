#include <cstdio>
#include <algorithm>
#include <vector>

const int L = 18;
const int N = 1 << L;
const int A = 26;
int n, from[N * L + A][2];
char buf[N + 1];

void out(int x) {
	if (x < A) printf("%c", 'a' + x);
	else {
		out(from[x][0]);
		out(from[x][1]);
	}
}

int main() {
	scanf("%d%s", &n, buf);
	std::vector<std::vector<int> > vec(1);
	for (int i = 0; i < 1 << n; ++i) vec[0].push_back(buf[i] - 'a');
	int amt = A;
	do {
		std::vector<std::pair<int, int> > all;
		for (int i = 0; i < (int)vec.size(); ++i) {
			for (int j = 0; j < (int)vec[i].size(); j += 2) {
				all.push_back(std::make_pair(vec[i][j], vec[i][j + 1]));
				all.push_back(std::make_pair(vec[i][j + 1], vec[i][j]));
			}
		}
		std::sort(all.begin(), all.end());
		all.resize(std::unique(all.begin(), all.end()) - all.begin());
		std::vector<std::vector<int> > next;
		for (int i = 0; i < (int)vec.size(); ++i) {
			for (int t = 0; t < 2; ++t) {
				next.push_back(std::vector<int>());
				for (int j = 0; j < (int)vec[i].size(); j += 2) {
					int ind = std::lower_bound(all.begin(), all.end(), std::make_pair(vec[i][j ^ t], vec[i][j ^ t ^ 1])) - all.begin() + amt;
					from[ind][0] = vec[i][j ^ t];
					from[ind][1] = vec[i][j ^ t ^ 1];
					next.back().push_back(ind);
				}
			}
		}
		vec = next;
		amt += all.size();
	} while (vec.size() != (1 << n));
	int mn = ~(1 << 31);
	for (int i = 0; i < 1 << n; ++i) mn = std::min(mn, vec[i].back());
	out(mn);
	printf("\n");
	return 0;
}