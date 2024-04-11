#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	std::vector<int> values(number);
	for(auto & it: values) std::cin>>it;

	std::vector<std::vector<char>> coprime(number, std::vector<char>(number));
	for(int first=0;first<number;++first) 
		for(int sec=0;sec<number;++sec) 
			coprime[first][sec]=std::gcd(values[first], values[sec])==1;

	std::vector<std::vector<char>> okayLeft(number, std::vector<char>(number));
	std::vector<std::vector<char>> okayRight(number, std::vector<char>(number));
	// okayLeft[leftmost node inclusive][root] = [leftmost... root] possible?
	// okayRight[rightmost node inclusive][root]
	
	for(int root=0;root<number;++root) 
		okayLeft[root][root]=okayRight[root][root]=true;

	for(int delta=1;delta<number;++delta)
		for(int root=0;root<number;++root){
			for(int left=root-delta,subroot=0; subroot<root;++subroot)
				if(left>=0 and (not coprime[root][subroot]) and okayLeft[left][subroot] and okayRight[root-1][subroot]){
					okayLeft[left][root]=true;
					break;
				}

			for(int right=root+delta,subroot=root+1; subroot<number;++subroot)
				if(right<number and (not coprime[root][subroot]) and okayLeft[root+1][subroot] and okayRight[right][subroot]){
					okayRight[right][root]=true;
					break;
				}
		}

	for(int root=0;root<number;++root)
		if(okayLeft[0][root] and okayRight[number-1][root]){
			std::cout<<"Yes\n";
			return 0;
		}
	std::cout<<"No\n";

}