#include <iostream>
#include <set>
#include <cstdio>

int main() {
	int n;
	std::multiset<int> pots;
	std::cin >> n;
	
	while(n--) {
		int t;
		scanf("%d", &t);
		pots.insert(t);
	}
	int size = 0;
	int last = -1;
	while(pots.size() > 0) {
		int cur = *(pots.begin());
		pots.erase(pots.begin());
		if(pots.size() == 0 || *(pots.begin()) > cur) {
			size++;
			last = cur;
		} else {
			pots.erase(pots.begin());
			pots.insert(cur + 1);
		}
	}
	std::cout << last - size + 1 << std::endl;
}