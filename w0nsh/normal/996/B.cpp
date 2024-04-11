#include <cstdio>
#include <vector>
#include <algorithm>

int main(){
	
	int n;
	std::scanf("%d", &n);
	std::vector<int> A(n);
	int min = 2000000000;
	for(int i = 0; i < n; ++i){
		std::scanf("%d", &A[i]);
		min = std::min(A[i], min);
	}
	int val = std::max((min / n) - 2, 0) * n;
	for(int i = 0; i < n; ++i){
		A[i] -= val;
	}
	int pos = 0;
	int time = 0;
	while(true){
		if(A[pos] - time <= 0){
			std::printf("%d\n", pos+1);
			break;
		}
		time++;
		pos++;
		if(pos == n) pos = 0;
	}

	return 0;
}