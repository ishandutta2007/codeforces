#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <stack>

int ans[200200];
int back[200200];

int main() {
	int n;
	std::cin >> n;
	std::map<int, int> freq;
	int c = -1;
	int st = -1;
	for(int i = 0; i < n; i++) {
		int v;
		scanf("%d", &v);
		if(freq.count(v - 1)) {
			back[i] = freq[v - 1];
			ans[i] = ans[freq[v - 1]] + 1;
		} else {
			back[i] = -1;
		}
		int idx = ans[i];
		if(idx + 1 > c) {
			c = idx + 1;
			st = i;
		}
		freq[v] = i;
	}
	std::cout << c << std::endl;
	std::stack<int> s;
	for(int i = st; i > -1; i = back[i]) s.push(i + 1);//, std::cout << "pushing " << i << std::endl;
	for(int i = 0; i < c; i++) {
		printf("%d%c", s.top(), i + 1 == c ? '\n' : ' ');
		s.pop();
	}
}