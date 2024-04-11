#include <algorithm>
#include <iostream>
#include <vector>


int n, m;
std::vector<int> A;
std::vector<int> open_before, closed_before;

int calc(int v){
	int on_left_opened = open_before[v+1];
	int on_right_opened = open_before[A.size()] - on_left_opened;
	int on_left_closed = closed_before[v+1];
	int on_right_closed = closed_before[A.size()] - on_left_closed;
	int max = 0;
	if(v != A.size()-1 && A[v] + 1 != A[v+1]){
		max = on_left_opened + on_right_closed - 1;
	}
	if(v != 0 && A[v] - 1 != A[v-1]){
		max = std::max(max, on_left_opened + on_right_closed - 1);
	}
	return max;
}

void answer(){
	open_before.resize(A.size()+1);
	closed_before.resize(A.size()+1);
	int last = 0;
	bool open = false;
	for(int i = 1; i <= A.size(); ++i){
		open_before[i] = open_before[i-1] + (open ? A[i-1] - last : 0);
		closed_before[i] = closed_before[i-1] + (!open ? A[i-1] - last : 0);
		last = A[i-1];
		open = !open;
	}
	int max = open_before[A.size()];
	for(int i = 0; i < A.size(); ++i){
		max = std::max(max, calc(i));
	}
	std::cout << max << "\n";
}

void read(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	A.resize(n+2);
	A[0] = 0;
	for(int i = 1; i <= n; ++i){
		std::cin >> A[i];
	}
	A[n+1] = m;
}

int main(){
	read();
	answer();
	return 0;
}