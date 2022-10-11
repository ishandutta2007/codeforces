#include <iostream>
#include <stack>
#include <cstdio>

const int ms = 100100;

int n, k;
long long a[ms], b[ms], c[ms];

bool can(int x) {
	a[n] = x;
	for(int i = 0; i <= n; i++) {
		b[i] = a[i];
		c[i] = 0;
	}
	c[0] = x;
	std::stack<int> s;
	for(int i = 0; i < k; i++) {
		if(b[i]) {
			//std::cout << "pushing " << i << std::endl;
			s.push(i);
		}
	}
	//std::cout << "checking " << x << std::endl;
	/*for(int i = 0; i <= n; i++) {
		std::cout << b[i] << (i == n ? '\n' : ' ');
	}
	for(int i = 0; i <= n; i++) {
		std::cout << c[i] << (i == n ? '\n' : ' ');
	}*/
	for(int i = 0; i < n; i++) {
		if(i + k <= n && b[i + k]) {
			//std::cout << "pushing " << i + k << std::endl;
			s.push(i + k);
		}
		if(!c[i]) continue;
		//std::cout << "got " << c[i] << " in pos " << i << std::endl;
		while(c[i] && !s.empty() && s.top() > i) {
			//std::cout << "nxt pos is " << s.top() << ", with " << b[s.top()] << '\n';
			long long use = std::min(c[i], b[s.top()]);
			c[i] -= use;
			b[s.top()] -= use;
			c[s.top()] += use;
			if(b[s.top()] == 0) {
				s.pop();
			}
		}
		if(c[i]) {
			return false;
		}
	}
	return c[n] == x;
}

int main() {
	std::cin >> n >> k;
	long long l = 0, r = 0;
	for(int i = 1; i < n; i++) {
		//std::cin >> a[i];
		scanf("%lld", a + i);
		r += a[i];
	}
	while(l != r) {
		int mid = (l + r + 1) / 2;
		if(can(mid)) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	std::cout << l << std::endl;
}