#include <iostream>
#include <cstdio>

const int ms = 1001000;

int p[ms];
bool visit[ms];

int main() {
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		scanf("%d", p + i);
		p[i]--;
	}
	int cyc = 0;
	for(int i = 0; i < n; i++) {
		if(visit[i]) continue;
		int on = i;
		while(!visit[on]) {
			visit[on] = true;
			cyc++;
			on = p[on];
		}
		cyc--;
	}
	if((3 * n - cyc) % 2 == 0 && 3 * n >= cyc) {
		std::cout << "Petr\n";
	} else {
		std::cout << "Um_nik\n";
	}
}