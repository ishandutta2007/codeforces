#include <iostream>
#include <vector>

const int ms = 1001000;

bool hole[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m, k;
	std::cin >> n >> m >> k;
	while(m--) {
	    int v;
	    std::cin >> v;
	    hole[v] = true;
	}
	int on = 1;
	while(k--) {
		if(hole[on]) break;
	    int u, v;
	    std::cin >> u >> v;
	    if(on == u) on = v;
	    else if(on == v) on = u;
	}
	std::cout << on << '\n';
}