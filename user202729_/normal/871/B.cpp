#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	std::vector<int> P(number), B(number);
	// P[j]=p_0 xor b_j
	// B[i]=p_i xor b_0
	for(int index=0; index<number; ++index){
		std::cout<<"? 0 "<<index<<std::endl;
		std::cin>>P[index];
		if(index!=0){
			std::cout<<"? "<<index<<" 0"<<std::endl;
			std::cin>>B[index];
		}else B[0]=P[0];
	}

	std::vector<int> p(number), b(number), result;
	int numResult{};
	for(p[0]=0; p[0]<number;++p[0]){
		for(int index=0; index<number; ++index)
			b[index]=p[0] xor P[index];
		for(int index=1; index<number; ++index)
			p[index]=b[0] xor B[index];
		assert(p[0]==(b[0] xor B[0]));

		for(int index=0; index<number; ++index)
			if(b[p[index]]!=index){
				goto continue_outer;
			}

		++numResult;
		if(result.empty()) result=p;

continue_outer:;
	}
	std::cout<<"!\n"<<numResult<<'\n';
	for(auto it: result) std::cout<<it<<' ';
	std::cout<<'\n';
}