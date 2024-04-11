#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

std::set<long long> set;

void rec(std::vector<int> vals, int n, int pos){
	if(vals[0] + vals[1] + vals[2] + vals[3] == n) set.insert(1ll*vals[0] + 5ll*vals[1] + 10ll*vals[2] + 50ll*vals[3]);
	else{
		vals[pos]++;
		while(pos <= 3){
			rec(vals, n, pos);
			pos++;
		}
	}
}

long long answer(int n){
	rec(std::vector<int>(4), n, 0);
	rec(std::vector<int>(4), n, 1);
	rec(std::vector<int>(4), n, 2);
	rec(std::vector<int>(4), n, 3);
	return set.size();
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	if(n < 14){
		std::cout << answer(n) << "\n";
	}else{
		n -= 14;
		std::cout << answer(14) + 49ll*n << "\n";
	}
	return 0;
}