#include <bits/stdc++.h>
#include <math.h>
int q, n, tab[30] = {0, 1, 1, 5, 1, 21, 1, 85, 73, 341, 89, 1365, 1, 5461, 4681, 21845, 1, 87381, 1, 349525, 299593, 1398101, 178481, 5592405, 1082401};

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> q;
	while(q--){
		std::cin >> n;
		if(n == (1<<__builtin_popcount(n))-1)
			std::cout << tab[__builtin_popcount(n)-1] << "\n";
		else
			std::cout << (1<<((int)log2(n)+1))-1 << "\n";
	}
	return 0;
}