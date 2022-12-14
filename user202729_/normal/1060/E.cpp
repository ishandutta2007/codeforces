// I think I've done a harder variant on this problem?...
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int number;
int64_t totalLen;
std::array<int, 2> countColor;
std::vector<std::vector<int>> add;

int work(int node, int par, bool color){ // returns subtree size
	int subtreeSize=1;
	++countColor[color];
	for(int child: add[node]) if(child!=par){
		auto const tmp=work(child, node, not color);
		totalLen+=tmp*int64_t(number-tmp);
		subtreeSize+=tmp;
	}
	return subtreeSize;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::cin>>number;
	add.resize(number);
	for(int _=0;_<number-1;++_) {
		int first, sec; std::cin>>first>>sec;--first;--sec;
		add[first].push_back(sec);
		add[sec].push_back(first);
	}

	//countColor.fill(0);
	work(0, -1, false);
	auto const tmp=totalLen+(int64_t)countColor[0]*countColor[1];
	assert(tmp%2==0);
	std::cout<<(tmp>>1)<<'\n';
}