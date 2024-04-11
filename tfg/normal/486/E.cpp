#include <iostream>
#include <algorithm>

const int ms = 100100;

int size[ms], got[ms];
int first[ms];

int a[ms];
int lis[ms];

int main() {
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		scanf("%d", a + i);
		size[i] = 1;
	}
	int c = 0;
	for(int i = 0; i < n; i++) {
		int idx = std::lower_bound(lis, lis + c, a[i]) - lis;
		lis[idx] = a[i];
		if(idx == c) {
			c++;
		}
		first[i] = idx;
		size[i] += idx;
	}
	//std::cout << "got c == " << c << "\n";
	c = 0;
	for(int i = n - 1; i >= 0; i--) {
		int idx = std::lower_bound(lis, lis + c, a[i], std::greater<int>()) - lis;
		lis[idx] = a[i];
		if(idx == c) {
			c++;
		}
		size[i] += idx;
	}
	//std::cout << "got c == " << c << "\n";
	for(int i = 0; i < n; i++) {
		//std::cout << size[i] << (i + 1 == n ? '\n' : ' ');
		if(size[i] == c)
		got[first[i]]++;
	}
	for(int i = 0; i < n; i++) {
		if(size[i] < c) {
			printf("1");
		} else if(got[first[i]] > 1) {
			printf("2");
		} else {
			printf("3");
		}
	}
	printf("\n");
}