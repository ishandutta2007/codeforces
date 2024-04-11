#include <cstdio>
#include <algorithm>
#include <vector>

int n;
std::vector<int> A;

int main(){
	std::scanf("%d", &n);
	A.resize(n);
	for(int i = 0; i < n; ++i) std::scanf("%d", &A[i]);
	if(n == 1) std::printf("-1\n");
	else if(n == 2){
		if(A[0] == A[1]) std::printf("-1\n");
		else std::printf("1\n1\n");
	}else{
		A.push_back(2000000000);
		int min = n;
		for(int i = 0; i < n; ++i){
			if(A[i] < A[min]) min = i;
		}
		std::printf("1\n%d\n", min+1);
	}

	return 0;
}