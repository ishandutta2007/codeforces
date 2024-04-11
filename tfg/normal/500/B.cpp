#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::vector<std::string> mat(n);
	for(int i = 0; i < n; i++) {
		std::cin >> mat[i];
	}
	std::vector<bool> visit(n, false);
	for(int i = 0; i < n; i++) {
		if(visit[i]) continue;
		visit[i] = true;
		std::vector<int> q(1, i);
		std::vector<int> v(1, a[i]);
		for(int l = 0; l < (int) q.size(); l++) {
			for(int j = 0; j < n; j++) {
				if(!visit[j] && mat[j][q[l]] == '1') {
					q.push_back(j);
					v.push_back(a[j]);
					visit[j] = true;
				}
			}
		}
		std::sort(q.begin(), q.end());
		std::sort(v.begin(), v.end());
		for(int i = 0; i < (int) q.size(); i++) {
			a[q[i]] = v[i];
		}
	}
	for(int i = 0; i < n; i++) {
		std::cout << a[i] << (i + 1 == n ? '\n' : ' ');
	}
}