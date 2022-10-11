#include <iostream>
#include <vector>

int qry(int y) {
	std::cout << y << std::endl;
	int ans;
	std::cin >> ans;
	return ans;
}

int test(int x) {

}

int main() {
	int m, p;
	std::cin >> m >> p;
	std::vector<int> arr(p);
	for(int i = 0; i < p; i++) {
		arr[i] = qry(m);
		if(arr[i] == 0) {
			return 0;
		}
		arr[i] = arr[i] == 1 ? 0 : 1;
	}
	int l = 1, r = m - 1;
	int i = 0;
	while(l != r) {
		int mid = (l + r) / 2;
		int cur_ans = qry(mid);
		if(arr[i] == 0) {
			cur_ans = -cur_ans;
		}
		i = (i + 1) % p;
		if(cur_ans == 0) {
			return 0;
		} else if(cur_ans == -1) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	qry(l);
}