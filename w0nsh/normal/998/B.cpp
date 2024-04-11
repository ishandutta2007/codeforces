#include <algorithm>
#include <cstdio>
#include <vector>
#include <utility>

int n, B;
std::vector<int> A;
std::vector<int> cuts;

void answer(){
	int have = 0;
	for(int i = 0; i < n-1; ++i){
		if(A[i] % 2 == 0) have--;
		else have++;
		if(have == 0) cuts.push_back(std::abs(A[i+1] - A[i]));
	}
	std::sort(cuts.begin(), cuts.end());
	int spent = 0;
	int licz = 0;
	for(auto &cut : cuts){
		spent += cut;
		if(spent <= B) licz++;
		else break;
	}
	std::printf("%d\n", licz);
}

void read(){
	std::scanf("%d%d", &n, &B);
	A.resize(n);
	for(int i = 0; i < n; ++i){
		std::scanf("%d", &A[i]);
	}
}

int main(){
	read();
	answer();
	return 0;
}