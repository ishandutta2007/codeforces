#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>
#include<algorithm>

struct info{
	uint16_t nless,ngreater;
};
void proc_in_place(std::vector<int> const& x,std::vector<info>& out){

	static std::vector<int> tmp;
	tmp.assign(begin(x),end(x));
	std::sort(begin(tmp),end(tmp));
	tmp.erase(std::unique(begin(tmp),end(tmp)),end(tmp));

	std::transform(begin(x),end(x),begin(out),[&](int a){
			auto iter=std::lower_bound(begin(tmp),end(tmp),a);
			assert(a==*iter);
			return info{uint16_t(iter-begin(tmp)),uint16_t(end(tmp)-iter-1)};
			});
}

std::vector<info> proc(std::vector<int> const& x){
	std::vector<info> out(x.size());
	proc_in_place(x,out);
	return out;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int nrow,ncol;std::cin>>nrow>>ncol;
	std::vector<std::vector<int>> a(nrow,std::vector<int>(ncol));
	for(auto& row:a)
		for(auto& x:row)
			std::cin>>x;

	std::vector<std::vector<info>> row_stat(nrow);
	std::transform(begin(a),end(a),begin(row_stat),proc);

	std::vector<int> col(nrow);
	std::vector<info> col_stat(nrow);
	for(int coli=0;coli<ncol;++coli){
		std::transform(begin(a),end(a),begin(col),[&](auto const& row){return row[coli];});
		proc_in_place(col,col_stat);
		for(int rowi=0;rowi<nrow;++rowi)
			// reuse a for out
			a[rowi][coli]=1
				+std::max(col_stat[rowi].nless,row_stat[rowi][coli].nless)
				+std::max(col_stat[rowi].ngreater,row_stat[rowi][coli].ngreater);
	}

	for(auto const& row:a){
		for(auto x:row)
			std::cout<<x<<' ';
		std::cout<<'\n';
	}
}