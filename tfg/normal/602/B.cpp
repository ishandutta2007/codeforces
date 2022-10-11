#include <iostream>
#include <set>

const int ms = 100100;

int a[ms];

int main() {
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::multiset<int> hmm;
	hmm.insert(a[0]);
	hmm.insert(a[1]);
	int ans = 0;
	for(int l = 0, r = 1; l < n; l++) {
		while(r + 1 < n) {
			int min = *hmm.begin(), max = *hmm.rbegin();
			int cur = a[r + 1];
			if(min != max && cur != min && cur != max) {
				break;
			}
			hmm.insert(cur);
			r++;
		}
		hmm.erase(hmm.lower_bound(a[l]));
		ans = std::max(ans, r - l + 1);
	}
	std::cout << ans << '\n';
}