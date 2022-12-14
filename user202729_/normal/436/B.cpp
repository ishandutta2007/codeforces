#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<string>
#include<vector>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int nrow,ncol,nspider;
	std::cin>>nrow>>ncol>>nspider;
	std::vector<int> out(ncol);

	std::string row;row.reserve(ncol);
	for(int rowi=0;rowi<nrow;++rowi){
		std::cin>>row;
		assert((int)row.size()==ncol);
		for(int coli=ncol;coli--;){
			switch(row[coli]){
				case 'L':
					if(coli-rowi>=0) ++out[coli-rowi];
					break;
				case 'R':
					if(coli+rowi<ncol) ++out[coli+rowi];
					break;
				case 'U':
					if(rowi%2==0) ++out[coli];
					break;
				case 'D':
					assert(rowi!=0);
					break;
				case '.':
					break;
				default:
					assert(0);__builtin_unreachable();
			}
		}
	}
	for(auto x:out)std::cout<<x<<' ';
	std::cout<<'\n';
}